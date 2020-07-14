#pragma once
#include <plog/Log.h>

namespace UplayR1Loader::UplayExports
{
	// ReSharper disable CppInconsistentNaming
	UPLAY_API inline int UPLAY_FUNC UPLAY_WIN_GetRewards()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_WIN_RefreshActions()
	{
		LOGD << "__CALL__";
		return 1;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_WIN_SetActionsCompleted()
	{
		LOGD << "__CALL__";
		return 1;
	}
	// ReSharper restore CppInconsistentNaming
}
