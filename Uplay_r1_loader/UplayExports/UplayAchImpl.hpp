#pragma once
#include <plog/Log.h>

namespace UplayR1Loader::UplayExports
{
	UPLAY_API inline DWORD UPLAY_FUNC UPLAY_ACH_GetAchievementImage()
	{
		LOGD_IF(UPLAY_LOG) << "__CALL__";
		return 0L;
	}

	UPLAY_API inline DWORD UPLAY_FUNC UPLAY_ACH_EarnAchievement()
	{
		LOGD_IF(UPLAY_LOG) << "__CALL__";
		return 1L;
	}

	UPLAY_API inline DWORD UPLAY_FUNC UPLAY_ACH_Write()
	{
		LOGD_IF(UPLAY_LOG) << "__CALL__";
		return 0L;
	}

	UPLAY_API inline DWORD UPLAY_FUNC UPLAY_ACH_GetAchievements(int a1, int a2,
		int a3, int a4[3])
	{
		LOGD_IF(UPLAY_LOG) << "__CALL__";
		return 0L;
	}
}