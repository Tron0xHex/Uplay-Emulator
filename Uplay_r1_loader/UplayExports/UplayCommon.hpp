#pragma once

#include <plog/Log.h>

#include "../UplaySaveStorageSingleton.hpp"
#include "../UplayTypes/UplayOverlapped.hpp"
#include "../UplayTypes/UplayList.hpp"

namespace UplayR1Loader::UplayExports
{
	UPLAY_API inline int UPLAY_FUNC UPLAY_Startup()
	{
		LOGD_IF(UPLAY_LOG) << "__CALL__";
		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_Start()
	{
		LOGD_IF(UPLAY_LOG) << "__CALL__";
		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_Quit()
	{
		LOGD_IF(UPLAY_LOG) << "__CALL__";

		UplaySaveStorageSingleton::GetInstance().storage.RemoveAll();
		return 1;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_HasOverlappedOperationCompleted(
		UplayTypes::UplayOverlapped* overlapped)
	{
		LOGD_IF(UPLAY_LOG) << hex << "Overlapped: " << overlapped;

		if (overlapped)
		{
			return overlapped->isOperationCompleted != 0L;
		}

		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_Init()
	{
		LOGD_IF(UPLAY_LOG) << "__CALL__";
		return 1;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_GetOverlappedOperationResult(
		const UplayTypes::UplayOverlapped* overlapped, DWORD* outResult)
	{
		LOGD_IF(UPLAY_LOG) << hex << "Overlapped: " << overlapped
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
		LOGD_IF(UPLAY_LOG) << "__CALL__";
		return 1;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_Release(UplayTypes::UplayList* list)
	{
		LOGD_IF(UPLAY_LOG) << "__CALL__";

		// TODO: FIX.

		if (list)
		{
			delete list;
		}

		return 1;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_GetNextEvent(int* arg)
	{
		LOGD_IF(UPLAY_LOG) << "__CALL__";
		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_GetLastError(char* err)
	{
		LOGD_IF(UPLAY_LOG) << "__CALL__";
		return 1;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_GetInstallationError(int* err)
	{
		LOGD_IF(UPLAY_LOG) << "__CALL__";
		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_SetGameSession(int a1, int a2,
	                                                     int a3, int a4)
	{
		LOGD_IF(UPLAY_LOG) << "__CALL__";
		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_ClearGameSession()
	{
		LOGD_IF(UPLAY_LOG) << "__CALL__";
		return 1;
	}
}
