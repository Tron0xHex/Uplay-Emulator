#pragma once

#include <plog/Log.h>

namespace UplayR1Loader::UplayExports
{
	// ReSharper disable CppInconsistentNaming
	UPLAY_API inline int UPLAY_FUNC UPLAY_FRIENDS_Init()
	{
		LOGD << "__CALL__";
		return 1;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_FRIENDS_GetFriendList()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_FRIENDS_RequestFriendship()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_FRIENDS_IsFriend()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_FRIENDS_AddToBlackList()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_FRIENDS_IsBlackListed()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_FRIENDS_ShowFriendSelectionUI()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_FRIENDS_EnableFriendMenuItem()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_FRIENDS_DisableFriendMenuItem()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_FRIENDS_InviteToGame()
	{
		LOGD << "__CALL__";
		return 0;
	}
	// ReSharper restore CppInconsistentNaming
}
