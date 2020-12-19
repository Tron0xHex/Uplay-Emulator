#pragma once

#include "src/pch.h"

#include "src/Macro.hpp"
#include "src/Types/UplayList.hpp"
#include "src/Types/UplayOverlapped.hpp"

namespace UplayR1Loader
{
	// ReSharper disable CppInconsistentNaming
	UPLAY_API inline long UPLAY_FUNC UPLAY_ACH_GetAchievementImage()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_ACH_EarnAchievement()
	{
		LOGD << "__CALL__";
		return 1;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_ACH_Write()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_ACH_GetAchievements(const int a1, const int a2,
															   const UplayList **outAchievementsList,
															   const UplayOverlapped *overlapped)
	{
		LOGD << fmt::format("OutAchievementsList: {} Overlapped: {}", reinterpret_cast<void *>(&outAchievementsList),
							reinterpret_cast<void *>(&overlapped));
		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_ACH_ReleaseAchievementList(const UplayList **achievementsList)
	{
		LOGD << fmt::format("AchievementsList: {}", reinterpret_cast<void *>(&achievementsList));
		return 1;
	}

	// ReSharper restore CppInconsistentNaming
} // namespace UplayR1Loader
