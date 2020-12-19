#pragma once

#include "src/pch.h"

#include "src/Macro.hpp"

namespace UplayR1Loader
{
	// ReSharper disable CppInconsistentNaming
	UPLAY_API inline long UPLAY_FUNC UPLAY_OPTIONS_Open(const char *cmd)
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_OPTIONS_Enumerate()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_OPTIONS_Set()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_OPTIONS_Apply()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_OPTIONS_ReleaseKeyValueList()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_OPTIONS_Close()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_OPTIONS_SetInGameState()
	{
		LOGD << "__CALL__";
		return 1;
	}

	// ReSharper restore CppInconsistentNaming
} // namespace UplayR1Loader
