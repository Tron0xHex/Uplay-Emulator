#pragma once

#include "src/pch.h"

#include "src/Macro.hpp"
#include "src/Types/UplayOverlapped.hpp"

namespace UplayR1Loader
{
	// ReSharper disable CppInconsistentNaming
	UPLAY_API inline long UPLAY_FUNC UPLAY_OVERLAY_Show(
		const int overlaySection, const UplayOverlapped *overlapped)
	{
		LOGD << fmt::format("OverlaySection: {} Overlapped: {}", overlaySection, reinterpret_cast<void *>(&overlapped));
		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_OVERLAY_SetShopUrl(
		void *url, UplayOverlapped *overlapped)
	{
		LOGD << fmt::format("Url: {} Overlapped: {}", url, reinterpret_cast<void *>(&overlapped));

		if (overlapped)
		{
			overlapped->Reserved = 0;
			overlapped->IsOperationCompleted = 1;
		}

		return 1;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_OVERLAY_ShowShopUrl(
		const void *url, const UplayOverlapped *overlapped)
	{
		LOGD << fmt::format("Url: {} Overlapped: {}", url, reinterpret_cast<void *>(&overlapped));
		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_OVERLAY_ShowNotification(
		const void *url, const UplayOverlapped *overlapped)
	{
		LOGD << fmt::format("Url: {} Overlapped: {}", url, reinterpret_cast<void *>(&overlapped));
		return 0;
	}

	// ReSharper restore CppInconsistentNaming
} // namespace UplayR1Loader