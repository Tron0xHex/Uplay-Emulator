#pragma once

#include "src/pch.h"

#include "src/Macro.hpp"
#include "src/Helpers/Saves.hpp"
#include "src/Types/UplaySave.hpp"
#include "src/Types/UplayList.hpp"
#include "src/Types/UplayOverlapped.hpp"

#include "src/Uplay/OpenOptionsManager.hpp"

namespace UplayR1Loader
{
	using namespace std;
	using std::filesystem::path;

	// ReSharper disable once CppInconsistentNaming
	namespace fs = std::filesystem;

	// ReSharper disable CppInconsistentNaming
	UPLAY_API inline long UPLAY_FUNC UPLAY_SAVE_GetSavegames(
		UplayList** outSaveGamesList, UplayOverlapped* overlapped)
	{
		LOGD << fmt::format("OutSaveGamesList: {} Overlapped: {}", reinterpret_cast<void*>(&outSaveGamesList),
		                    reinterpret_cast<void*>(&overlapped));

		typedef vector<tuple<unsigned int, string>> SavesList;

		try
		{
			int index = 0U;

			auto* const uplayList = new UplayList{0, {nullptr}};

			const auto uplaySaves = GetSavegames();
			const auto savesSize = static_cast<int>(uplaySaves.size());

			Singleton<SavesList>::Instance().Set(uplaySaves);

			auto* const savesList = new UplaySave*[savesSize]{nullptr};

			uplayList->Count = static_cast<int>(savesSize);
			uplayList->Saves = savesList;

			for (const auto& [id, name] : Singleton<SavesList>::Instance().Get())
			{
				savesList[index++] = new UplaySave(static_cast<int>(id), name.c_str());
			}

			*outSaveGamesList = uplayList;

#ifdef UPLAY_API_2014_NEXT_GEN
			overlapped->SetResult();
#else
			overlapped->SetZeros();
			overlapped->SetResult(&outSaveGamesList);
#endif

			return 1;
		}
		catch (exception& ex)
		{
			LOGE << ex.what();
		}

		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_SAVE_Open(const int slotId, const int mode,
	                                                 int* outSaveHandle,
	                                                 UplayOverlapped* overlapped)
	{
		LOGD << fmt::format("SlotId: {} Mode: {} OutSaveHandle: {} Overlapped: {}", slotId, mode,
		                    reinterpret_cast<void*>(&outSaveHandle),
		                    reinterpret_cast<void*>(&overlapped));

		auto openMode = ios::in | ios::out | ios::binary;

		if (mode)
		{
			openMode = openMode | ios::trunc;
		}

		Singleton<OpenOptionsManager>::Instance().Get().SetOpenOptions(slotId, openMode);

		*outSaveHandle = slotId;

#ifdef UPLAY_API_2014_NEXT_GEN
		overlapped->SetResult();
#else
		overlapped->SetZeros();
		overlapped->SetResult(&outSaveHandle);
#endif

		return 1;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_SAVE_Close(const int outSaveHandle)
	{
		LOGD << fmt::format("OutSaveHandle: {}", outSaveHandle);

		Singleton<OpenOptionsManager>::Instance().Get().RemoveOpenOptions(outSaveHandle);
		return 1;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_SAVE_Read(const int saveHandle,
	                                                 const int numOfBytesToRead,
	                                                 const int offset, char** outBuffer,
	                                                 unsigned int* outNumOfBytesRead,
	                                                 UplayOverlapped* overlapped)
	{
		LOGD << fmt::format(
			"SaveHandle: {} NumOfBytesToRead: {} Offset: {} OutBuffer: {} OutNumOfBytesRead: {} Overlapped: {}",
			saveHandle, numOfBytesToRead, offset, reinterpret_cast<void*>(&outBuffer),
			reinterpret_cast<void*>(&outNumOfBytesRead), reinterpret_cast<void*>(&overlapped));

		overlapped->SetZeros();

		const auto saveName = GetSavePath(saveHandle);

		try
		{
			*outNumOfBytesRead = ReadSave(saveName, offset, *outBuffer, numOfBytesToRead);

#ifdef UPLAY_API_2014_NEXT_GEN
			overlapped->SetResult();
#else
			overlapped->SetResult(reinterpret_cast<void*>(&outBuffer));
#endif
			return 1;
		}
		catch (exception& ex)
		{
			LOGE << ex.what();
		}

		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_SAVE_Write(
		const int saveHandle, const int numOfBytesToWrite, const char** buffer,
		UplayOverlapped* overlapped)
	{
		LOGD << fmt::format(
			"SaveHandle: {} NumOfBytesToWrite: {} Buffer: {} Overlapped: {}", saveHandle,
			numOfBytesToWrite, reinterpret_cast<void*>(&buffer), reinterpret_cast<void*>(&overlapped));

		overlapped->SetZeros();

		const auto savePath = GetSavePath(saveHandle);

		try
		{
			if (auto openOptions = Singleton<OpenOptionsManager>::Instance().Get().GetOpenOptions(saveHandle))
			{
				WriteSave(savePath, *openOptions, *buffer, numOfBytesToWrite);

#ifdef UPLAY_API_2014_NEXT_GEN
				overlapped->SetResult();
#else
				overlapped->SetResult(&buffer);
#endif
				return 1;
			}
		}
		catch (exception& ex)
		{
			LOGE << ex.what();
		}

		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_SAVE_SetName(const int saveHandle,
	                                                    const char* nameUtf8)
	{
		LOGD << fmt::format("SaveHandle: {} NameUtf8: {}", saveHandle, reinterpret_cast<const void*>(&nameUtf8));

		const auto saveName = string(nameUtf8);
		const auto saveNamePath = GetSaveNamePath(saveHandle);

		try
		{
			WriteSaveName(saveNamePath, saveName);
			return 1;
		}
		catch (exception& ex)
		{
			LOGE << ex.what();
		}

		return 0;
	}

	// ReSharper disable CppParameterMayBeConst
	UPLAY_API inline long UPLAY_FUNC UPLAY_SAVE_Remove(
		int slotId, UplayOverlapped* overlapped)
	{
		LOGD << fmt::format("SlotId: {} Overlapped: {}", slotId, reinterpret_cast<void*>(&overlapped));

		overlapped->SetZeros();

		const auto savePath = GetSavePath(slotId);
		const auto saveNamePath = GetSaveNamePath(slotId);

		if (fs::remove(savePath) && fs::remove(saveNamePath))
		{
#ifdef UPLAY_API_2014_NEXT_GEN
			overlapped->SetResult();
#else
			overlapped->SetResult(reinterpret_cast<void*>(&slotId));
#endif
			return 1;
		}

		return 0;
	}

	// ReSharper restore CppParameterMayBeConst
	// ReSharper restore CppInconsistentNaming
} // namespace UplayR1Loader
