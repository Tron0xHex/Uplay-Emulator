#pragma once

#include "stdafx.h"
#include <minhook/include/MinHook.h>
#include <plog/Log.h>
#include "UplayExports/UplayAchievements.hpp"
#include "UplayExports/UplaySave.hpp"
#include "UplayExports/UplayAvatar.hpp"
#include "UplayExports/UplayCommon.hpp"
#include "UplayExports/UplayFriends.hpp"
#include "UplayExports/UplayInstaller.hpp"
#include "UplayExports/UplayMetaData.hpp"
#include "UplayExports/UplayOverlay.hpp"
#include "UplayExports/UplayParty.hpp"
#include "UplayExports/UplayUser.hpp"
#include "UplayExports/UplayWin.hpp"
#include "UplayExports/UplayOptions.hpp"
#include "UplayExports/UplayPresence.hpp"

namespace UplayR1Loader::Hooks
{
	inline void InstallHooks()
	{
		if (MH_Initialize() != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to initialize minhook!";
		}

		// -----------------------------------------------------------------------------------------------------

		// Achievements hooks.

		// -----------------------------------------------------------------------------------------------------

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_ACH_GetAchievementImage",
		                     &UplayExports::UPLAY_ACH_GetAchievementImage, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_ACH_GetAchievementImage hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_ACH_EarnAchievement",
			&UplayExports::UPLAY_ACH_EarnAchievement, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_ACH_EarnAchievement hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_ACH_Write",
			&UplayExports::UPLAY_ACH_Write, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_ACH_Write hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_ACH_GetAchievements",
			&UplayExports::UPLAY_ACH_GetAchievements, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_ACH_GetAchievements hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_ACH_ReleaseAchievementList",
			&UplayExports::UPLAY_ACH_GetAchievements, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_ACH_ReleaseAchievementList hook!";
		}

		// -----------------------------------------------------------------------------------------------------

		// Avatar hooks.

		// -----------------------------------------------------------------------------------------------------

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_AVATAR_GetBitmap",
			&UplayExports::UPLAY_AVATAR_GetBitmap, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_AVATAR_GetBitmap hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_AVATAR_GetAvatarIdForCurrentUser",
			&UplayExports::UPLAY_AVATAR_GetAvatarIdForCurrentUser, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_AVATAR_GetAvatarIdForCurrentUser hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_AVATAR_Get",
			&UplayExports::UPLAY_AVATAR_Get, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_AVATAR_Get hook!";
		}

		// -----------------------------------------------------------------------------------------------------

		// Common hooks.

		// -----------------------------------------------------------------------------------------------------

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_Startup",
			&UplayExports::UPLAY_Startup, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_Startup hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_Start",
			&UplayExports::UPLAY_Start, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_Start hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_Quit",
			&UplayExports::UPLAY_Quit, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_Quit hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_HasOverlappedOperationCompleted",
			&UplayExports::UPLAY_HasOverlappedOperationCompleted, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_HasOverlappedOperationCompleted hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_Init",
			&UplayExports::UPLAY_Init, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_Init hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_GetOverlappedOperationResult",
			&UplayExports::UPLAY_GetOverlappedOperationResult, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_GetOverlappedOperationResult hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_Update",
			&UplayExports::UPLAY_Update, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_Update hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_Release",
			&UplayExports::UPLAY_Release, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_Release hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_GetNextEvent",
			&UplayExports::UPLAY_GetNextEvent, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_GetNextEvent hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_GetLastError",
			&UplayExports::UPLAY_GetLastError, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_GetLastError hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_GetInstallationError",
			&UplayExports::UPLAY_GetInstallationError, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_GetInstallationError hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_SetGameSession",
			&UplayExports::UPLAY_SetGameSession, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_SetGameSession hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_ClearGameSession",
			&UplayExports::UPLAY_ClearGameSession, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_ClearGameSession hook!";
		}

		// -----------------------------------------------------------------------------------------------------

		// Friends hooks.

		// -----------------------------------------------------------------------------------------------------

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_FRIENDS_Init",
			&UplayExports::UPLAY_FRIENDS_Init, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_FRIENDS_Init hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_FRIENDS_GetFriendList",
			&UplayExports::UPLAY_FRIENDS_GetFriendList, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_FRIENDS_GetFriendList hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_FRIENDS_RequestFriendship",
			&UplayExports::UPLAY_FRIENDS_RequestFriendship, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_FRIENDS_RequestFriendship hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_FRIENDS_IsFriend",
			&UplayExports::UPLAY_FRIENDS_IsFriend, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_FRIENDS_IsFriend hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_FRIENDS_AddToBlackList",
			&UplayExports::UPLAY_FRIENDS_AddToBlackList, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_FRIENDS_AddToBlackList hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_FRIENDS_IsBlackListed",
			&UplayExports::UPLAY_FRIENDS_IsBlackListed, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_FRIENDS_IsBlackListed hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_FRIENDS_ShowFriendSelectionUI",
			&UplayExports::UPLAY_FRIENDS_ShowFriendSelectionUI, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_FRIENDS_ShowFriendSelectionUI hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_FRIENDS_EnableFriendMenuItem",
			&UplayExports::UPLAY_FRIENDS_EnableFriendMenuItem, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_FRIENDS_EnableFriendMenuItem hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_FRIENDS_DisableFriendMenuItem",
			&UplayExports::UPLAY_FRIENDS_DisableFriendMenuItem, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_FRIENDS_DisableFriendMenuItem hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_FRIENDS_InviteToGame",
			&UplayExports::UPLAY_FRIENDS_InviteToGame, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_FRIENDS_InviteToGame hook!";
		}

		// -----------------------------------------------------------------------------------------------------

		// Installer hooks.

		// -----------------------------------------------------------------------------------------------------

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_INSTALLER_Init",
			&UplayExports::UPLAY_INSTALLER_Init, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_INSTALLER_Init hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_INSTALLER_Init",
			&UplayExports::UPLAY_INSTALLER_Init, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_INSTALLER_Init hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_INSTALLER_UpdateInstallOrder",
			&UplayExports::UPLAY_INSTALLER_UpdateInstallOrder, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_INSTALLER_UpdateInstallOrder hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_INSTALLER_AreChunksInstalled",
			&UplayExports::UPLAY_INSTALLER_AreChunksInstalled, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_INSTALLER_AreChunksInstalled hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_INSTALLER_GetChunks",
			&UplayExports::UPLAY_INSTALLER_GetChunks, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_INSTALLER_GetChunks hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_INSTALLER_GetChunkIdsFromTag",
			&UplayExports::UPLAY_INSTALLER_GetChunkIdsFromTag, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_INSTALLER_GetChunkIdsFromTag hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_INSTALLER_GetLanguageUtf8",
			&UplayExports::UPLAY_INSTALLER_GetLanguageUtf8, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_INSTALLER_GetLanguageUtf8 hook!";
		}

		// -----------------------------------------------------------------------------------------------------

		// MetaData hooks.

		// -----------------------------------------------------------------------------------------------------

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_METADATA_SetSingleEventTag",
			&UplayExports::UPLAY_METADATA_SetSingleEventTag, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_METADATA_SetSingleEventTag hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_METADATA_SetContinuousTag",
			&UplayExports::UPLAY_METADATA_SetContinuousTag, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_METADATA_SetContinuousTag hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_METADATA_ClearContinuousTag",
			&UplayExports::UPLAY_METADATA_ClearContinuousTag, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_METADATA_ClearContinuousTag hook!";
		}

		// -----------------------------------------------------------------------------------------------------

		// Overlay hooks.

		// -----------------------------------------------------------------------------------------------------

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_OVERLAY_Show",
			&UplayExports::UPLAY_OVERLAY_Show, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_OVERLAY_Show hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_OVERLAY_SetShopUrl",
			&UplayExports::UPLAY_OVERLAY_SetShopUrl, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_OVERLAY_SetShopUrl hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_OVERLAY_ShowShopUrl",
			&UplayExports::UPLAY_OVERLAY_ShowShopUrl, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_OVERLAY_ShowShopUrl hook!";
		}

		// -----------------------------------------------------------------------------------------------------

		// Party hooks.

		// -----------------------------------------------------------------------------------------------------

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_PARTY_Init",
			&UplayExports::UPLAY_PARTY_Init, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_PARTY_Init hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_PARTY_Init",
			&UplayExports::UPLAY_PARTY_InviteToParty, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_PARTY_InviteToParty hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_PARTY_RespondToGameInvite",
			&UplayExports::UPLAY_PARTY_RespondToGameInvite, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_PARTY_RespondToGameInvite hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_PARTY_ShowGameInviteOverlayUI",
			&UplayExports::UPLAY_PARTY_ShowGameInviteOverlayUI, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_PARTY_ShowGameInviteOverlayUI hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_PARTY_GetInGameMemberList",
			&UplayExports::UPLAY_PARTY_GetInGameMemberList, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_PARTY_GetInGameMemberList hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_PARTY_GetFullMemberList",
			&UplayExports::UPLAY_PARTY_GetFullMemberList, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_PARTY_GetFullMemberList hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_PARTY_SetUserData",
			&UplayExports::UPLAY_PARTY_SetUserData, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_PARTY_SetUserData hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_PARTY_IsInParty",
			&UplayExports::UPLAY_PARTY_IsInParty, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_PARTY_IsInParty hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_PARTY_IsPartyLeader",
			&UplayExports::UPLAY_PARTY_IsPartyLeader, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_PARTY_IsPartyLeader hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_PARTY_PromoteToLeader",
			&UplayExports::UPLAY_PARTY_PromoteToLeader, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_PARTY_PromoteToLeader hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_PARTY_InvitePartyToGame",
			&UplayExports::UPLAY_PARTY_InvitePartyToGame, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_PARTY_InvitePartyToGame hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_PARTY_EnablePartyMemberMenuItem",
			&UplayExports::UPLAY_PARTY_EnablePartyMemberMenuItem, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_PARTY_EnablePartyMemberMenuItem hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_PARTY_DisablePartyMemberMenuItem",
			&UplayExports::UPLAY_PARTY_DisablePartyMemberMenuItem, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_PARTY_DisablePartyMemberMenuItem hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_PARTY_SetGuest",
			&UplayExports::UPLAY_PARTY_SetGuest, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_PARTY_SetGuest hook!";
		}

		// -----------------------------------------------------------------------------------------------------

		// Save hooks.

		// -----------------------------------------------------------------------------------------------------

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_SAVE_GetSavegames",
			&UplayExports::UPLAY_SAVE_GetSavegames, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_SAVE_GetSavegames hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_SAVE_Open",
			&UplayExports::UPLAY_SAVE_Open, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_SAVE_GetSavegames hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_SAVE_Close",
			&UplayExports::UPLAY_SAVE_Close, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_SAVE_Close hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_SAVE_Read",
			&UplayExports::UPLAY_SAVE_Read, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_SAVE_Read hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_SAVE_Write",
			&UplayExports::UPLAY_SAVE_Write, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_SAVE_Write hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_SAVE_SetName",
			&UplayExports::UPLAY_SAVE_SetName, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_SAVE_SetName hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_SAVE_Remove",
			&UplayExports::UPLAY_SAVE_Remove, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_SAVE_Remove hook!";
		}

		// -----------------------------------------------------------------------------------------------------

		// User hooks.

		// -----------------------------------------------------------------------------------------------------

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_USER_GetCdKeys",
			&UplayExports::UPLAY_USER_GetCdKeys, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_USER_GetCdKeys hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_USER_ReleaseCdKeyList",
			&UplayExports::UPLAY_USER_ReleaseCdKeyList, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_USER_ReleaseCdKeyList hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_USER_GetCredentials",
			&UplayExports::UPLAY_USER_GetCredentials, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_USER_GetCredentials hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_USER_GetCdKeyUtf8",
			&UplayExports::UPLAY_USER_GetCdKeyUtf8, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_USER_GetCdKeyUtf8 hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_USER_GetAccountIdUtf8",
			&UplayExports::UPLAY_USER_GetAccountIdUtf8, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_USER_GetAccountIdUtf8 hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_USER_GetUsernameUtf8",
			&UplayExports::UPLAY_USER_GetUsernameUtf8, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_USER_GetUsernameUtf8 hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_USER_GetNameUtf8",
			&UplayExports::UPLAY_USER_GetNameUtf8, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_USER_GetNameUtf8 hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_USER_GetEmailUtf8",
			&UplayExports::UPLAY_USER_GetEmailUtf8, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_USER_GetEmailUtf8 hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_USER_GetPasswordUtf8",
			&UplayExports::UPLAY_USER_GetPasswordUtf8, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_USER_GetPasswordUtf8 hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_USER_GetAccountId",
			&UplayExports::UPLAY_USER_GetAccountId, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_USER_GetAccountId hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_USER_GetUsername",
			&UplayExports::UPLAY_USER_GetUsername, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_USER_GetUsername hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_USER_GetEmail",
			&UplayExports::UPLAY_USER_GetEmail, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_USER_GetEmail hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_USER_GetPassword",
			&UplayExports::UPLAY_USER_GetPassword, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_USER_GetPassword hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_USER_IsConnected",
			&UplayExports::UPLAY_USER_IsConnected, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_USER_IsConnected hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_USER_IsOwned",
			&UplayExports::UPLAY_USER_IsOwned, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_USER_IsOwned hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_USER_IsInOfflineMode",
			&UplayExports::UPLAY_USER_IsInOfflineMode, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_USER_IsInOfflineMode hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_USER_GetTicketUtf8",
			&UplayExports::UPLAY_USER_GetTicketUtf8, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_USER_GetTicketUtf8 hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_USER_ConsumeItem",
			&UplayExports::UPLAY_USER_ConsumeItem, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_USER_ConsumeItem hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_USER_GetConsumeItem",
			&UplayExports::UPLAY_USER_GetConsumeItem, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_USER_GetConsumeItem hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_USER_GetConsumableItems",
			&UplayExports::UPLAY_USER_GetConsumableItems, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_USER_GetConsumableItems hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_USER_ReleaseConsumeItemResult",
			&UplayExports::UPLAY_USER_ReleaseConsumeItemResult, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_USER_ReleaseConsumeItemResult hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_USER_SetGameSession",
			&UplayExports::UPLAY_USER_SetGameSession, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_USER_SetGameSession hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_USER_ClearGameSession",
			&UplayExports::UPLAY_USER_ClearGameSession, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_USER_ClearGameSession hook!";
		}

		// -----------------------------------------------------------------------------------------------------

		// Win hooks.

		// -----------------------------------------------------------------------------------------------------

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_WIN_GetRewards",
			&UplayExports::UPLAY_WIN_GetRewards, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_WIN_GetRewards hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_WIN_RefreshActions",
			&UplayExports::UPLAY_WIN_RefreshActions, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_WIN_RefreshActions hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_WIN_SetActionsCompleted",
			&UplayExports::UPLAY_WIN_SetActionsCompleted, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_WIN_SetActionsCompleted hook!";
		}

		// -----------------------------------------------------------------------------------------------------

		// Options hooks.

		// -----------------------------------------------------------------------------------------------------

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_OPTIONS_Open",
			&UplayExports::UPLAY_OPTIONS_Open, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_OPTIONS_Open hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_OPTIONS_Enumerate",
			&UplayExports::UPLAY_OPTIONS_Enumerate, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_OPTIONS_Enumerate hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_OPTIONS_Set",
			&UplayExports::UPLAY_OPTIONS_Set, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_OPTIONS_Set hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_OPTIONS_Apply",
			&UplayExports::UPLAY_OPTIONS_Apply, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_OPTIONS_Apply hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_OPTIONS_ReleaseKeyValueList",
			&UplayExports::UPLAY_OPTIONS_ReleaseKeyValueList, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_OPTIONS_ReleaseKeyValueList hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_OPTIONS_Close",
			&UplayExports::UPLAY_OPTIONS_Close, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_OPTIONS_Close hook!";
		}

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_OPTIONS_SetInGameState",
			&UplayExports::UPLAY_OPTIONS_SetInGameState, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_OPTIONS_SetInGameState hook!";
		}

		// -----------------------------------------------------------------------------------------------------

		// Presence hooks.

		// -----------------------------------------------------------------------------------------------------

		if (MH_CreateHookApi(Consts::UplayR1OriginalDllName, "UPLAY_PRESENCE_SetPresence",
			&UplayExports::UPLAY_PRESENCE_SetPresence, nullptr) != MH_OK)
		{
			LOGE_IF(UPLAY_LOG) << "Unable to install UPLAY_PRESENCE_SetPresence hook!";
		}

		// -----------------------------------------------------------------------------------------------------

		// ReSharper disable CppZeroConstantCanBeReplacedWithNullptr
		if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK)
			// ReSharper restore CppZeroConstantCanBeReplacedWithNullptr
		{
			LOGE_IF(UPLAY_LOG) << "Hooks cannot be enabled!";
		}
	}
}
