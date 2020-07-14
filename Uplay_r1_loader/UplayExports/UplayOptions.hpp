#pragma once
#include <plog/Log.h>

namespace UplayR1Loader::UplayExports
{
	// ReSharper disable CppInconsistentNaming
	UPLAY_API inline int UPLAY_FUNC UPLAY_OPTIONS_Open(char* cmd)
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_OPTIONS_Enumerate()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_OPTIONS_Set()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_OPTIONS_Apply()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_OPTIONS_ReleaseKeyValueList()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_OPTIONS_Close()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_OPTIONS_SetInGameState()
	{
		LOGD << "__CALL__";
		return 1;
	}
	// ReSharper restore CppInconsistentNaming
}
