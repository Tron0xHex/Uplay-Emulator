#pragma once

#include <plog/Log.h>

#include "../UplayConfigSingleton.hpp"
#include "../UplayTypes/UplayOverlapped.hpp"
#include "../UplayTypes/UplayList.hpp"
#include "../UplaySaveStorageSingleton.hpp"

namespace UplayR1Loader::UplayExports
{
	// ReSharper disable CppInconsistentNaming
	UPLAY_API inline int UPLAY_FUNC UPLAY_Startup()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_Start()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_Quit()
	{
		LOGD << "__CALL__";
		return 1;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_HasOverlappedOperationCompleted(
		UplayTypes::UplayOverlapped* overlapped)
	{
		LOGD << hex << "Overlapped: " << overlapped;

		if (overlapped)
		{
			return overlapped->isOperationCompleted != 0L;
		}

		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_Init()
	{
		const auto savesPath = path(
			UplayConfigSingleton::GetInstance().configHolder.config.uplay.saves);

		if (!exists(savesPath) && !create_directories(savesPath))
		{
			throw exception("Unable to create directories!");
		}

		if (!UplaySaveInternal::IsMetaDataStorageExists(savesPath) && !UplaySaveInternal::CreateMetaDataStorage(
			savesPath))
		{
			throw exception("Unable to create meta data storage!");
		}

		if (!filesystem::is_empty(savesPath))
		{
			for (const auto& dirEntry : directory_iterator(savesPath))
			{
				const auto path = dirEntry.path();

				if (path.has_extension() && path.extension().string() == Consts::SaveFileExtension)
				{
					auto [slotId, uplaySave] = UplaySaveInternal::FromFile(path);

					UplaySaveStorageSingleton::GetInstance().storage.AppendSave(
						slotId, uplaySave);
				}
			}
		}

		return 1;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_GetOverlappedOperationResult(
		const UplayTypes::UplayOverlapped* overlapped, int* outResult)
	{
		LOGD << hex << "Overlapped: " << overlapped
			<< " OutResult: " << outResult;

		if (overlapped && overlapped->isOperationCompleted)
		{
			*outResult = overlapped->reserved;
			return 1;
		}

		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_Update()
	{
		LOGD << "__CALL__";
		return 1;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_Release(UplayTypes::UplayList* list)
	{
		LOGD << "__CALL__";

		if (list)
		{
			delete list;
		}

		return 1;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_GetNextEvent(int* arg)
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_GetLastError(char* err)
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_GetInstallationError(int* err)
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_SetGameSession(int a1, int a2,
	                                                     int a3, int a4)
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_ClearGameSession()
	{
		LOGD << "__CALL__";
		return 1;
	}
	// ReSharper restore CppInconsistentNaming
}
