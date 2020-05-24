#pragma once
#include <plog/Log.h>

namespace UplayR1Loader::UplayExports
{
	UPLAY_API inline DWORD UPLAY_FUNC UPLAY_METADATA_SetSingleEventTag()
	{
		LOGD_IF(UPLAY_LOG) << "__CALL__";
		return 0L;
	}

	UPLAY_API inline DWORD UPLAY_FUNC UPLAY_METADATA_SetContinuousTag()
	{
		LOGD_IF(UPLAY_LOG) << "__CALL__";
		return 0L;
	}

	UPLAY_API inline DWORD UPLAY_FUNC UPLAY_METADATA_ClearContinuousTag()
	{
		LOGD_IF(UPLAY_LOG) << "__CALL__";
		return 0L;
	}
}