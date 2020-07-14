#pragma once
#include <plog/Log.h>

namespace UplayR1Loader::UplayExports
{
	// ReSharper disable CppInconsistentNaming
	UPLAY_API inline int UPLAY_FUNC UPLAY_METADATA_SetSingleEventTag()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_METADATA_SetContinuousTag()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_METADATA_ClearContinuousTag()
	{
		LOGD << "__CALL__";
		return 0;
	}
	// ReSharper restore CppInconsistentNaming
}
