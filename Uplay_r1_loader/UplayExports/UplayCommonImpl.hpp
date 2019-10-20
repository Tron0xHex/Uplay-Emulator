#pragma once

#include <plog/Log.h>

#include "../UplayConfigSingleton.hpp"
#include "../UplaySaveInternal.hpp"
#include "../UplaySaveStorageSingleton.hpp"
#include "../UplayTypes/UplayOverlapped.hpp"
#include "../UplayTypes/UplayList.hpp"

namespace UplayR1Loader::UplayExports
{
	UPLAY_API inline DWORD UPLAY_FUNC UPLAY_Startup()
	{
		LOGD_IF(UPLAY_LOG) << "__CALL__";

		try
		{
			const auto currentPt = filesystem::current_path();
			const auto configPt = currentPt / path(Consts::ConfigName);

			if (!exists(configPt))
			{
				throw std::exception("Configuration file not found!");
			}

			UplayConfigSingleton::GetInstance().configHolder.Open(configPt);

			const auto savesPt = path(UplayConfigSingleton::GetInstance().configHolder.config.uplay.saves);

			if (!exists(savesPt) && !create_directories(savesPt))
			{
				throw std::exception("Unable to create directories!");
			}

			if (!UplaySaveInternal::IsMetaDataStorageExists(savesPt))
			{
				if (!UplaySaveInternal::CreateMetaDataStorage(savesPt))
				{
					throw std::exception("Unable to create meta data storage!");
				}
			}

			if (!filesystem::is_empty(savesPt))
			{
				for (const auto& dirEntry : directory_iterator(savesPt))
				{
					const auto pt = dirEntry.path();

					if (pt.has_extension() && pt.extension().string() == Consts::SaveFileExtension)
					{
						auto [slotId, uplaySave] = UplaySaveInternal::FromFile(pt);

						UplaySaveStorageSingleton::GetInstance().storage.AppendSave(
							slotId, uplaySave);
					}
				}
			}

			return 0L;
		}
		catch (exception & ex)
		{
			LOGD_IF(UPLAY_LOG) << ex.what();
		}

		return 1L;
	}

	UPLAY_API inline DWORD UPLAY_FUNC UPLAY_Quit()
	{
		LOGD_IF(UPLAY_LOG) << "__CALL__";

		UplaySaveStorageSingleton::GetInstance().storage.RemoveAll();
		return 1L;
	}

	UPLAY_API inline DWORD UPLAY_FUNC UPLAY_HasOverlappedOperationCompleted(
		UplayTypes::UplayOverlapped* overlapped)
	{
		LOGD_IF(UPLAY_LOG) << hex << "Overlapped: " << overlapped;

		if (overlapped) {
			return overlapped->isOperationCompleted != 0L;
		}

		return 0L;
	}

	UPLAY_API inline DWORD UPLAY_FUNC UPLAY_Init()
	{
		return 1L;
	}

	UPLAY_API inline DWORD UPLAY_FUNC UPLAY_GetOverlappedOperationResult(
		const UplayTypes::UplayOverlapped* overlapped, DWORD* outResult)
	{
		LOGD_IF(UPLAY_LOG) << hex << "Overlapped: " << overlapped
			<< " OutResult: " << outResult;

		if (overlapped && overlapped->isOperationCompleted)
		{
			*outResult = overlapped->reserved;
			return 1L;
		}

		return 0L;
	}

	UPLAY_API inline DWORD UPLAY_FUNC UPLAY_Update()
	{
		LOGD_IF(UPLAY_LOG) << "__CALL__";
		return 1L;
	}

	UPLAY_API inline DWORD UPLAY_FUNC UPLAY_Release(UplayTypes::UplayList* list)
	{
		LOGD_IF(UPLAY_LOG) << "__CALL__";

		if (list)
		{
			delete list;
		}

		return 1L;
	}

	UPLAY_API inline DWORD UPLAY_FUNC UPLAY_GetNextEvent(int* arg)
	{
		LOGD_IF(UPLAY_LOG) << "__CALL__";
		return 0L;
	}

	UPLAY_API inline DWORD UPLAY_FUNC UPLAY_GetLastError(char* err)
	{
		LOGD_IF(UPLAY_LOG) << "__CALL__";
		return 0L;
	}

	UPLAY_API inline DWORD UPLAY_FUNC UPLAY_GetInstallationError(int* err)
	{
		LOGD_IF(UPLAY_LOG) << "__CALL__";
		return 0L;
	}

	UPLAY_API inline DWORD UPLAY_FUNC UPLAY_SetGameSession(int a1, int a2,
		int a3, int a4)
	{
		LOGD_IF(UPLAY_LOG) << "__CALL__";
		return 0L;
	}

	UPLAY_API inline DWORD UPLAY_FUNC UPLAY_ClearGameSession()
	{
		LOGD_IF(UPLAY_LOG) << "__CALL__";
		return 1L;
	}
}