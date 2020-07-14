#pragma once

#include <plog/Log.h>

#include "../UplayTypes/UplayOverlapped.hpp"

namespace UplayR1Loader::UplayExports
{
	// ReSharper disable CppInconsistentNaming
	UPLAY_API inline int UPLAY_FUNC UPLAY_OVERLAY_Show(
		const int overlaySection, UplayTypes::UplayOverlapped* overlapped)
	{
		LOGD << hex << "OverlaySection: " << overlaySection << " Overlapped: " << overlapped;
		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_OVERLAY_SetShopUrl(
		void* url, UplayTypes::UplayOverlapped* overlapped)
	{
		LOGD << hex << "Url: " << url
			<< " Overlapped: " << overlapped;

		if (overlapped)
		{
			overlapped->reserved = 0;
			overlapped->isOperationCompleted = 1;
		}

		return 1;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_OVERLAY_ShowShopUrl(
		void* url, UplayTypes::UplayOverlapped* overlapped)
	{
		LOGD << hex << "Url: " << url
			<< " Overlapped: " << overlapped;
		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_OVERLAY_ShowNotification(
		void* url, UplayTypes::UplayOverlapped* overlapped)
	{
		LOGD << hex << "Url: " << url
			<< " Overlapped: " << overlapped;
		return 0;
	}
	// ReSharper restore CppInconsistentNaming
}
