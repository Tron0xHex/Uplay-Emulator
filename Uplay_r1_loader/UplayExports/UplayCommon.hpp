#pragma once

#include <plog/Log.h>

#include "../EUplayConfigSingleton.hpp"
#include "../UplayTypes/UplayOverlapped.hpp"
#include "../UplayTypes/UplayList.hpp"

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
		LOGD << "__CALL__";
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
