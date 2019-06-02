#pragma once
#include <plog/Log.h>

UPLAY_API inline DWORD UPLAY_FUNC UPLAY_INSTALLER_Init()
{
	LOGD_IF(UPLAY_LOG) << "__CALL__";
	return 0L;
}

UPLAY_API inline DWORD UPLAY_FUNC UPLAY_INSTALLER_UpdateInstallOrder()
{
	LOGD_IF(UPLAY_LOG) << "__CALL__";
	return 0L;
}

UPLAY_API inline DWORD UPLAY_FUNC UPLAY_INSTALLER_AreChunksInstalled()
{
	LOGD_IF(UPLAY_LOG) << "__CALL__";
	return 0L;
}

UPLAY_API inline DWORD UPLAY_FUNC UPLAY_INSTALLER_GetLanguageUtf8()
{
	LOGD_IF(UPLAY_LOG) << "__CALL__";
	return 0L;
}