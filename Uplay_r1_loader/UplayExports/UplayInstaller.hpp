#pragma once
#include <plog/Log.h>

namespace UplayR1Loader::UplayExports
{
	// ReSharper disable CppInconsistentNaming
	UPLAY_API inline int UPLAY_FUNC UPLAY_INSTALLER_Init()
	{
		LOGD << "__CALL__";
		return 1;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_INSTALLER_UpdateInstallOrder()
	{
		LOGD << "__CALL__";
		return 1;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_INSTALLER_AreChunksInstalled(const int a1, const int a2)
	{
		LOGD << a1 << " " << a2;
		return a2 != 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_INSTALLER_GetChunks(void* buffer)
	{
		LOGD << "__CALL__";
		return 1;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_INSTALLER_GetChunkIdsFromTag()
	{
		LOGD << "__CALL__";
		return 1;
	}

	UPLAY_API inline const char* UPLAY_FUNC UPLAY_INSTALLER_GetLanguageUtf8()
	{
		LOGD << "__CALL__";
		return EUplayConfigSingleton::GetInstance()
		       .configHolder.config.uplay.language.c_str();
	}
	// ReSharper restore CppInconsistentNaming
}
