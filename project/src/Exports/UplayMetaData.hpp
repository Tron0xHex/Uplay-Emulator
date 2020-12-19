#pragma once

#include "src/pch.h"

#include "src/Macro.hpp"

namespace UplayR1Loader
{
	// ReSharper disable CppInconsistentNaming
	UPLAY_API inline long UPLAY_FUNC UPLAY_METADATA_SetSingleEventTag()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_METADATA_SetContinuousTag()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_METADATA_ClearContinuousTag()
	{
		LOGD << "__CALL__";
		return 0;
	}

	// ReSharper restore CppInconsistentNaming
} // namespace UplayR1Loader
