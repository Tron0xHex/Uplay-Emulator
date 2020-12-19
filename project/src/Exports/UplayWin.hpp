#pragma once

#include "src/pch.h"

#include "src/Macro.hpp"

namespace UplayR1Loader
{
	// ReSharper disable CppInconsistentNaming
	UPLAY_API inline long UPLAY_FUNC UPLAY_WIN_GetRewards()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_WIN_RefreshActions()
	{
		LOGD << "__CALL__";
		return 1;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_WIN_SetActionsCompleted()
	{
		LOGD << "__CALL__";
		return 1;
	}

	// ReSharper restore CppInconsistentNaming
} // namespace UplayR1Loader
