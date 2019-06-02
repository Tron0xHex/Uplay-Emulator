#pragma once

#include <plog/Log.h>

#include "../UplaySaveStorageSingleton.hpp"
#include "../UplayTypes/UplayOverlapped.hpp"
#include "../UplayConfigSingleton.hpp"
#include "../UplayTypes/UplaySave.hpp"
#include "../UplayTypes/UplayList.hpp"

UPLAY_API inline DWORD UPLAY_FUNC UPLAY_SAVE_GetSavegames(
	UplayList **outGamesList, UplayOverlapped *overlapped)
{
	LOGD_IF(UPLAY_LOG) << hex << "OutGamesList: " << outGamesList
		<< " Overlapped: " << overlapped;

	overlapped->SetZeros();

	auto index = 0U;

	const auto list = new UplayList{ NULL };
	const auto uplaySaves = UplaySaveStorageSingleton::GetInstance().storage.GetSaves();
	const auto savesList = new UplaySave *[uplaySaves.size()]{ nullptr };

	list->count = uplaySaves.size();
	list->saves = savesList;

	for (const auto &[slotId, uplaySave] : uplaySaves)
	{
		savesList[index++] = new UplaySave(slotId, uplaySave->initialName.c_str());
	}

	*outGamesList = list;

	overlapped->SetResult(&outGamesList);
	return 1L;
}

UPLAY_API inline DWORD UPLAY_FUNC UPLAY_SAVE_Open(const int slotId, const int mode,
	int *outSaveHandle,
	UplayOverlapped *overlapped)
{
	LOGD_IF(UPLAY_LOG) << hex << "SlotId: " << slotId << " Mode: " << mode
		<< " OutSaveHandle: " << outSaveHandle
		<< " Overlapped: " << overlapped;

	auto result = 0L;
	auto openMode = ios::in | ios::out | ios::binary;

	if (mode)
	{
		openMode = openMode | ios::trunc;
	}

	overlapped->SetZeros();

	try
	{
		if (!UplaySaveStorageSingleton::GetInstance().storage.IsSaveExists(slotId))
		{
			const auto saves = UplayConfigSingleton::GetInstance().configHolder.config.uplay.saves;
			const auto saveFileName = to_string(slotId) + Consts::SaveFileExtension;

			const auto savePt = path(saves) / path(saveFileName);
			const auto uplaySave = make_shared<UplaySaveInternal>(savePt);

			UplaySaveStorageSingleton::GetInstance().storage.AppendSave(slotId, uplaySave);

			result = uplaySave->Open(openMode);
		}
		else
		{
			result = UplaySaveStorageSingleton::GetInstance().storage.GetSave(slotId)->Open(openMode);
		}
	}
	catch (exception &ex)
	{
		LOGD_IF(UPLAY_LOG) << ex.what();
	}

	*outSaveHandle = slotId;

	overlapped->SetResult(&outSaveHandle);
	return result;
}

UPLAY_API inline DWORD UPLAY_FUNC UPLAY_SAVE_Close(const int outSaveHandle)
{
	LOGD_IF(UPLAY_LOG) << hex << "OutSaveHandle: " << outSaveHandle;

	if (UplaySaveStorageSingleton::GetInstance().storage.IsSaveExists(outSaveHandle)) {

		const auto uplaySave = UplaySaveStorageSingleton::GetInstance().storage.GetSave(outSaveHandle);

		if (uplaySave->Close())
		{
			return 1L;
		}
	}

	return 0L;
}

UPLAY_API inline DWORD UPLAY_FUNC UPLAY_SAVE_Read(const int saveHandle,
                                                  const DWORD numOfBytesToRead,
                                                  const int offset, char **outBuffer,
                                                  const LPDWORD outNumOfBytesRead,
	UplayOverlapped *overlapped)
{
	LOGD_IF(UPLAY_LOG) << hex << "SaveHandle: " << saveHandle
		<< " NumOfBytesToRead: " << numOfBytesToRead << " Offset: " << offset
		<< " OutBuffer: " << outBuffer << " OutNumOfBytesRead: "
		<< outNumOfBytesRead << " Overlapped: " << overlapped;

	overlapped->SetZeros();

	try
	{
		if (UplaySaveStorageSingleton::GetInstance().storage.IsSaveExists(saveHandle)) {

			const auto uplaySave = UplaySaveStorageSingleton::GetInstance().storage.GetSave(saveHandle);

			if (uplaySave->Read(numOfBytesToRead, offset, *outBuffer, outNumOfBytesRead))
			{
				overlapped->SetResult(outNumOfBytesRead);
				return 1L;
			}
		}
	}
	catch (exception &ex)
	{
		LOGD_IF(UPLAY_LOG) << ex.what();
	}

	return 0L;
}

UPLAY_API inline DWORD UPLAY_FUNC UPLAY_SAVE_Write(
	const int saveHandle, const DWORD numOfBytesToWrite, const char **buffer,
	UplayOverlapped *overlapped)
{
	LOGD_IF(UPLAY_LOG) << hex << "SaveHandle: " << saveHandle
		<< " NumOfBytesToWrite: " << numOfBytesToWrite
		<< " Buffer: " << buffer << " Overlapped: "
		<< overlapped;

	overlapped->SetZeros();

	try
	{
		if (UplaySaveStorageSingleton::GetInstance().storage.IsSaveExists(saveHandle)) {

			const auto uplaySave = UplaySaveStorageSingleton::GetInstance().storage.GetSave(saveHandle);

			if (uplaySave->Write(numOfBytesToWrite, *buffer))
			{
				overlapped->SetResult(&buffer);
				return 1L;
			}
		}
	}
	catch (exception &ex)
	{
		LOGD_IF(UPLAY_LOG) << ex.what();
	}

	return 0L;
}

UPLAY_API inline DWORD UPLAY_FUNC UPLAY_SAVE_SetName(const int saveHandle,
	const char *nameUtf8)
{
	LOGD_IF(UPLAY_LOG) << hex << "SaveHandle: " << saveHandle
		<< " NameUtf8: " << nameUtf8;

	try
	{
		if (UplaySaveStorageSingleton::GetInstance().storage.IsSaveExists(saveHandle)) {

			const auto uplaySave = UplaySaveStorageSingleton::GetInstance().storage.GetSave(saveHandle);

			if (uplaySave->SetName(saveHandle, nameUtf8))
			{
				return 1L;
			}
		}
	}
	catch (exception &ex)
	{
		LOGD_IF(UPLAY_LOG) << ex.what();
	}

	return 0L;
}

UPLAY_API inline DWORD UPLAY_FUNC UPLAY_SAVE_Remove(
	int slotId, UplayOverlapped *overlapped)
{
	LOGD_IF(UPLAY_LOG) << hex << "SlotId: " << slotId << " Overlapped: " << overlapped;

	overlapped->SetZeros();

	try
	{
		if (UplaySaveStorageSingleton::GetInstance().storage.IsSaveExists(slotId)) {

			const auto uplaySave = UplaySaveStorageSingleton::GetInstance().storage.GetSave(slotId);

			if (uplaySave->Remove(slotId))
			{
				UplaySaveStorageSingleton::GetInstance().storage.RemoveSave(slotId);
				overlapped->SetResult(&slotId);
				return 1L;
			}
		}
	}
	catch (exception &ex)
	{
		LOGD_IF(UPLAY_LOG) << ex.what();
	}

	return 0L;
}