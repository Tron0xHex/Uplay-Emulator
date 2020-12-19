#pragma once

#include "src/pch.h"

#include "src/Macro.hpp"
#include "src/Objects/UplayConfig.hpp"
#include "src/Utils/Singleton.hpp"

namespace UplayR1Loader
{
	// ReSharper disable CppInconsistentNaming
	UPLAY_API inline long UPLAY_FUNC UPLAY_INSTALLER_Init()
	{
		LOGD << "__CALL__";
		return 1;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_INSTALLER_UpdateInstallOrder()
	{
		LOGD << "__CALL__";
		return 1;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_INSTALLER_AreChunksInstalled(const int a1, const int a2)
	{
		LOGD << a1 << " " << a2;
		return a2 != 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_INSTALLER_GetChunks(const void* buffer)
	{
		LOGD << "__CALL__";
		return 1;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_INSTALLER_GetChunkIdsFromTag()
	{
		LOGD << "__CALL__";
		return 1;
	}

	UPLAY_API inline const char*UPLAY_FUNC UPLAY_INSTALLER_GetLanguageUtf8()
	{
		LOGD << "__CALL__";
		return Singleton<UplayConfig>::Instance().Get().Uplay.Language.c_str();
	}

	// ReSharper restore CppInconsistentNaming
} // namespace UplayR1Loader
