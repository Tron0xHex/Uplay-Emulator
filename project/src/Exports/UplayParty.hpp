#pragma once

#include "src/pch.h"

#include "src/Macro.hpp"

namespace UplayR1Loader
{
	// ReSharper disable CppInconsistentNaming
	UPLAY_API inline long UPLAY_FUNC UPLAY_PARTY_Init()
	{
		LOGD << "__CALL__";
		return 1;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_PARTY_InviteToParty()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_PARTY_RespondToGameInvite()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_PARTY_ShowGameInviteOverlayUI()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_PARTY_GetInGameMemberList()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_PARTY_GetFullMemberList()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_PARTY_SetUserData()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_PARTY_IsInParty()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_PARTY_IsPartyLeader()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_PARTY_PromoteToLeader()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_PARTY_InvitePartyToGame()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_PARTY_EnablePartyMemberMenuItem()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_PARTY_DisablePartyMemberMenuItem()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_PARTY_SetGuest()
	{
		LOGD << "__CALL__";
		return 0;
	}

	// ReSharper restore CppInconsistentNaming
} // namespace UplayR1Loader
