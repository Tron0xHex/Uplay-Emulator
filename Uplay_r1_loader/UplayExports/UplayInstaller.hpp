#pragma once
#include <plog/Log.h>

namespace UplayR1Loader::UplayExports
{
	UPLAY_API inline int UPLAY_FUNC UPLAY_INSTALLER_Init()
	{
		LOGD_IF(UPLAY_LOG) << "__CALL__";
		return 1;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_INSTALLER_UpdateInstallOrder()
	{
		LOGD_IF(UPLAY_LOG) << "__CALL__";
		return 1;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_INSTALLER_AreChunksInstalled(const int a1, const int a2)
	{
		LOGD_IF(UPLAY_LOG) << a1 << " " << a2;
		return a2 != 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_INSTALLER_GetChunks(void* buffer)
	{
		LOGD_IF(UPLAY_LOG) << "__CALL__";
		return 1;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_INSTALLER_GetChunkIdsFromTag()
	{
		LOGD_IF(UPLAY_LOG) << "__CALL__";
		return 1;
	}

	UPLAY_API inline const char* UPLAY_FUNC UPLAY_INSTALLER_GetLanguageUtf8()
	{
		LOGD_IF(UPLAY_LOG) << "__CALL__";
		return UplayConfigSingleton::GetInstance()
			.configHolder.config.uplay.language.c_str();
	}
}