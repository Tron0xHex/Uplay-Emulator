#pragma once

#include <plog/Log.h>

namespace UplayR1Loader::UplayExports
{
	UPLAY_API inline int UPLAY_FUNC UPLAY_AVATAR_GetBitmap()
	{
		LOGD_IF(UPLAY_LOG) << "__CALL__";
		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_AVATAR_GetAvatarIdForCurrentUser()
	{
		LOGD_IF(UPLAY_LOG) << "__CALL__";
		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_AVATAR_Get()
	{
		LOGD_IF(UPLAY_LOG) << "__CALL__";
		return 0;
	}
}