#pragma once
#include <plog/Log.h>
#include "../UplayTypes/UplayOverlapped.hpp"
#include "../UplayTypes/UplayList.hpp"

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
	                                                          UplayTypes::UplayList** outAchievementsList,
	                                                          UplayTypes::UplayOverlapped* overlapped)
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_ACH_ReleaseAchievementList(UplayTypes::UplayList** achievementsList)
	{
		LOGD << "__CALL__";
		return 1;
	}
	// ReSharper restore CppInconsistentNaming
}
