#pragma once

#include <plog/Log.h>

#include "../UplaySaveStorageSingleton.hpp"
#include "../UplayTypes/UplayOverlapped.hpp"
#include "../UplayConfigSingleton.hpp"
#include "../UplayTypes/UplaySave.hpp"
#include "../UplayTypes/UplayList.hpp"

namespace UplayR1Loader::UplayExports
{
	// ReSharper disable CppInconsistentNaming
	UPLAY_API inline int UPLAY_FUNC UPLAY_SAVE_GetSavegames(
		UplayTypes::UplayList** outGamesList, UplayTypes::UplayOverlapped* overlapped)
	{
		LOGD << hex << "OutGamesList: " << outGamesList
			<< " Overlapped: " << overlapped;

#ifdef UPLAY_API_2014_NEXT_GEN
		int index = 0U;

		const auto uplayList = new UplayTypes::UplayList{NULL};
		const auto uplaySaves = UplaySaveStorageSingleton::GetInstance().storage.GetSaves();

		const auto savesSize = static_cast<int>(uplaySaves.size());
		const auto savesList = new UplayTypes::UplaySave * [savesSize]{nullptr};

		uplayList->count = static_cast<int>(uplaySaves.size());
		uplayList->saves = savesList;

		for (const auto& [slotId, uplaySave] : uplaySaves)
		{
			savesList[index++] = new UplayTypes::UplaySave
				(slotId, uplaySave->initialName.c_str());
		}

		*outGamesList = uplayList;

		overlapped->SetResult();
#else
		int index = 0U;

		const auto uplayList = new UplayTypes::UplayList{NULL};
		const auto uplaySaves = UplaySaveStorageSingleton::GetInstance().storage.GetSaves();

		const auto savesSize = static_cast<int>(uplaySaves.size());
		const auto savesList = new UplayTypes::UplaySave * [savesSize]{nullptr};

		uplayList->count = static_cast<int>(uplaySaves.size());
		uplayList->saves = savesList;

		for (const auto& [slotId, uplaySave] : uplaySaves)
		{
			savesList[index++] = new UplayTypes::UplaySave(slotId, uplaySave->initialName.c_str());
		}

		*outGamesList = uplayList;

		overlapped->SetZeros();
		overlapped->SetResult(&outGamesList);
#endif
		return 1;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_SAVE_Open(const int slotId, const int mode,
	                                                int* outSaveHandle,
	                                                UplayTypes::UplayOverlapped* overlapped)
	{
		LOGD << hex << "SlotId: " << slotId << " Mode: " << mode
			<< " OutSaveHandle: " << outSaveHandle
			<< " Overlapped: " << overlapped;

		auto result = 0L;
		auto openMode = ios::in | ios::out | ios::binary;

		if (mode)
		{
			openMode = openMode | ios::trunc;
		}

		try
		{
			if (!UplaySaveStorageSingleton::GetInstance().storage.IsSaveExists(slotId))
			{
				const auto saves = UplayConfigSingleton::GetInstance().configHolder.config.uplay.saves;
				const auto saveFileName = to_string(slotId) + Consts::SaveFileExtension;

				const auto savePath = path(saves) / path(saveFileName);
				const auto uplaySave = make_shared<UplaySaveInternal>(savePath);

				UplaySaveStorageSingleton::GetInstance().storage.AppendSave(slotId, uplaySave);

				result = uplaySave->Open(openMode);
			}
			else
			{
				result = UplaySaveStorageSingleton::GetInstance().storage.GetSave(slotId)->Open(openMode);
			}
		}
		catch (exception& ex)
		{
			LOGD << ex.what();
		}

		*outSaveHandle = slotId;

#ifdef UPLAY_API_2014_NEXT_GEN
		overlapped->SetResult();
#else
		overlapped->SetZeros();
		overlapped->SetResult(&outSaveHandle);
#endif
		return result;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_SAVE_Close(const int outSaveHandle)
	{
		LOGD << hex << "OutSaveHandle: " << outSaveHandle;

		if (UplaySaveStorageSingleton::GetInstance().storage.IsSaveExists(outSaveHandle))
		{
			const auto uplaySave = UplaySaveStorageSingleton::GetInstance().storage.GetSave(outSaveHandle);

			if (uplaySave->Close())
			{
				return 1;
			}
		}

		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_SAVE_Read(const int saveHandle,
	                                                const int numOfBytesToRead,
	                                                const int offset, char** outBuffer,
	                                                unsigned int* outNumOfBytesRead,
	                                                UplayTypes::UplayOverlapped* overlapped)
	{
		LOGD << hex << "SaveHandle: " << saveHandle
			<< " NumOfBytesToRead: " << numOfBytesToRead << " Offset: " << offset
			<< " OutBuffer: " << outBuffer << " OutNumOfBytesRead: "
			<< outNumOfBytesRead << " Overlapped: " << overlapped;

		overlapped->SetZeros();

		try
		{
			if (UplaySaveStorageSingleton::GetInstance().storage.IsSaveExists(saveHandle))
			{
				const auto uplaySave = UplaySaveStorageSingleton::GetInstance().storage.GetSave(saveHandle);

				if (uplaySave->Read(numOfBytesToRead, offset, *outBuffer, outNumOfBytesRead))
				{
#ifdef UPLAY_API_2014_NEXT_GEN
					overlapped->SetResult();
#else
					overlapped->SetResult(static_cast<void*>(outNumOfBytesRead));
#endif
					return 1;
				}
			}
		}
		catch (exception& ex)
		{
			LOGD << ex.what();
		}

		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_SAVE_Write(
		const int saveHandle, const int numOfBytesToWrite, const char** buffer,
		UplayTypes::UplayOverlapped* overlapped)
	{
		LOGD << hex << "SaveHandle: " << saveHandle
			<< " NumOfBytesToWrite: " << numOfBytesToWrite
			<< " Buffer: " << buffer << " Overlapped: "
			<< overlapped;

		overlapped->SetZeros();

		try
		{
			if (UplaySaveStorageSingleton::GetInstance().storage.IsSaveExists(saveHandle))
			{
				const auto uplaySave = UplaySaveStorageSingleton::GetInstance().storage.GetSave(saveHandle);

				if (uplaySave->Write(numOfBytesToWrite, *buffer))
				{
#ifdef UPLAY_API_2014_NEXT_GEN
					overlapped->SetResult();
#else
					overlapped->SetResult(&buffer);
#endif
					return 1;
				}
			}
		}
		catch (exception& ex)
		{
			LOGD << ex.what();
		}

		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_SAVE_SetName(const int saveHandle,
	                                                   const char* nameUtf8)
	{
		LOGD << hex << "SaveHandle: " << saveHandle
			<< " NameUtf8: " << nameUtf8;

		try
		{
			if (UplaySaveStorageSingleton::GetInstance().storage.IsSaveExists(saveHandle))
			{
				const auto uplaySave = UplaySaveStorageSingleton::GetInstance().storage.GetSave(saveHandle);

				if (uplaySave->SetName(saveHandle, nameUtf8))
				{
					return 1;
				}
			}
		}
		catch (exception& ex)
		{
			LOGD << ex.what();
		}

		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_SAVE_Remove(
		int slotId, UplayTypes::UplayOverlapped* overlapped)
	{
		LOGD << hex << "SlotId: " << slotId << " Overlapped: " << overlapped;

		overlapped->SetZeros();

		try
		{
			if (UplaySaveStorageSingleton::GetInstance().storage.IsSaveExists(slotId))
			{
				const auto uplaySave = UplaySaveStorageSingleton::GetInstance().storage.GetSave(slotId);

				if (uplaySave->Remove(slotId))
				{
					UplaySaveStorageSingleton::GetInstance().storage.RemoveSave(slotId);

#ifdef UPLAY_API_2014_NEXT_GEN
					overlapped->SetResult();
#else
					overlapped->SetResult(&slotId);
#endif
					return 1;
				}
			}
		}
		catch (exception& ex)
		{
			LOGD << ex.what();
		}

		return 0;
	}
	// ReSharper restore CppInconsistentNaming
}
