#pragma once
#include <plog/Log.h>

namespace UplayR1Loader::UplayExports
{
	// ReSharper disable CppInconsistentNaming
	UPLAY_API inline int UPLAY_FUNC UPLAY_PRESENCE_SetPresence()
	{
		LOGD << "__CALL__";
		return 0;
	}
	// ReSharper restore CppInconsistentNaming
}
