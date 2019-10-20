#pragma once
#include <plog/Log.h>

namespace UplayR1Loader::UplayExports
{
	UPLAY_API inline DWORD UPLAY_FUNC UPLAY_WIN_GetRewards()
	{
		LOGD_IF(UPLAY_LOG) << "__CALL__";
		return 0L;
	}

	UPLAY_API inline DWORD UPLAY_FUNC UPLAY_WIN_RefreshActions()
	{
		LOGD_IF(UPLAY_LOG) << "__CALL__";
		return 1L;
	}
}