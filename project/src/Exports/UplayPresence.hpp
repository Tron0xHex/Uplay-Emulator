#pragma once

#include "src/pch.h"

#include "src/Macro.hpp"

namespace UplayR1Loader
{
	// ReSharper disable CppInconsistentNaming
	UPLAY_API inline long UPLAY_FUNC UPLAY_PRESENCE_SetPresence()
	{
		LOGD << "__CALL__";
		return 0;
	}

	// ReSharper restore CppInconsistentNaming
} // namespace UplayR1Loader