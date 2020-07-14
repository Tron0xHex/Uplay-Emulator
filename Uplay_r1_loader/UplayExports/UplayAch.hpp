#pragma once
#include <plog/Log.h>

namespace UplayR1Loader::UplayExports
{
	// ReSharper disable CppInconsistentNaming
	UPLAY_API inline int UPLAY_FUNC UPLAY_ACH_GetAchievementImage()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_ACH_EarnAchievement()
	{
		LOGD << "__CALL__";
		return 1;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_ACH_Write()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_ACH_GetAchievements(int a1, int a2,
	                                                          int a3, int a4[3])
	{
		LOGD << "__CALL__";
		return 0;
	}
	// ReSharper restore CppInconsistentNaming
}
