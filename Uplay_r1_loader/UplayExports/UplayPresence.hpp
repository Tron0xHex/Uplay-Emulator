#pragma once
#include <plog/Log.h>

namespace UplayR1Loader::UplayExports
{
	UPLAY_API inline int UPLAY_FUNC UPLAY_PRESENCE_SetPresence()
	{
		LOGD_IF(UPLAY_LOG) << "__CALL__";
		return 0;
	}
}
