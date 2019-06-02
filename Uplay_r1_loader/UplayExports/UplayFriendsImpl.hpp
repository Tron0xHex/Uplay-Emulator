#pragma once

#include <plog/Log.h>

UPLAY_API inline DWORD UPLAY_FUNC UPLAY_FRIENDS_Init()
{
	LOGD_IF(UPLAY_LOG) << "__CALL__";
	return 1L;
}

UPLAY_API inline DWORD UPLAY_FUNC UPLAY_FRIENDS_GetFriendList()
{
	LOGD_IF(UPLAY_LOG) << "__CALL__";
	return 0L;
}

UPLAY_API inline DWORD UPLAY_FUNC UPLAY_FRIENDS_RequestFriendship()
{
	LOGD_IF(UPLAY_LOG) << "__CALL__";
	return 0L;
}

UPLAY_API inline DWORD UPLAY_FUNC UPLAY_FRIENDS_IsFriend()
{
	LOGD_IF(UPLAY_LOG) << "__CALL__";
	return 0L;
}

UPLAY_API inline DWORD UPLAY_FUNC UPLAY_FRIENDS_AddToBlackList()
{
	LOGD_IF(UPLAY_LOG) << "__CALL__";
	return 0L;
}

UPLAY_API inline DWORD UPLAY_FUNC UPLAY_FRIENDS_IsBlackListed()
{
	LOGD_IF(UPLAY_LOG) << "__CALL__";
	return 0L;
}

UPLAY_API inline DWORD UPLAY_FUNC UPLAY_FRIENDS_ShowFriendSelectionUI()
{
	LOGD_IF(UPLAY_LOG) << "__CALL__";
	return 0L;
}

UPLAY_API inline DWORD UPLAY_FUNC UPLAY_FRIENDS_EnableFriendMenuItem()
{
	LOGD_IF(UPLAY_LOG) << "__CALL__";
	return 0L;
}

UPLAY_API inline DWORD UPLAY_FUNC UPLAY_FRIENDS_DisableFriendMenuItem()
{
	LOGD_IF(UPLAY_LOG) << "__CALL__";
	return 0L;
}

UPLAY_API inline DWORD UPLAY_FUNC UPLAY_FRIENDS_InviteToGame()
{
	LOGD_IF(UPLAY_LOG) << "__CALL__";
	return 0L;
}