#pragma once

#include "src/pch.h"

#include "src/Macro.hpp"
#include "src/Types/UplayList.hpp"
#include "src/Types/UplayOverlapped.hpp"

namespace UplayR1Loader
{
	using namespace std;

	// ReSharper disable CppInconsistentNaming
	UPLAY_API inline long UPLAY_FUNC UPLAY_Startup()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_Start()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_Quit()
	{
		LOGD << "__CALL__";
		return 1;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_HasOverlappedOperationCompleted(
		const UplayOverlapped *overlapped)
	{
		LOGD << fmt::format("Overlapped: {}", reinterpret_cast<const void *>(&overlapped));

		if (overlapped)
		{
			return overlapped->IsOperationCompleted != 0L;
		}

		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_Init()
	{
		LOGD << "__CALL__";
		return 1;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_GetOverlappedOperationResult(
		const UplayOverlapped *overlapped, int *outResult)
	{
		LOGD << fmt::format("Overlapped: {} OutResult: {}", reinterpret_cast<const void *>(&overlapped), reinterpret_cast<void *>(&outResult));

		if (overlapped && overlapped->IsOperationCompleted)
		{
			*outResult = overlapped->Reserved;
			return 1;
		}

		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_Update()
	{
		LOGD << "__CALL__";
		return 1;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_Release(UplayList *list)
	{
		LOGD << fmt::format("UplayList: {}", reinterpret_cast<void *>(&list));

		delete list;
		return 1;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_GetNextEvent(const int *arg)
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_GetLastError(const char *err)
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_GetInstallationError(const int *err)
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_SetGameSession(const int a1, const int a2,
														  const int a3, const int a4)
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_ClearGameSession()
	{
		LOGD << "__CALL__";
		return 1;
	}

	// ReSharper restore CppInconsistentNaming
} // namespace UplayR1Loader
