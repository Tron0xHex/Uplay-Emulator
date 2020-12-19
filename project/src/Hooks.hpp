#pragma once

#include "Consts.hpp"

#include "Exports/UplayAch.hpp"
#include "Exports/UplayAvatar.hpp"
#include "Exports/UplayCommon.hpp"
#include "Exports/UplayFriends.hpp"
#include "Exports/UplayInstaller.hpp"
#include "Exports/UplayMetaData.hpp"
#include "Exports/UplayOptions.hpp"
#include "Exports/UplayOverlay.hpp"
#include "Exports/UplayParty.hpp"
#include "Exports/UplayPresence.hpp"
#include "Exports/UplaySave.hpp"
#include "Exports/UplayUser.hpp"
#include "Exports/UplayWin.hpp"

namespace UplayR1Loader
{
	inline void InstallHooks()
	{
		if (MH_Initialize() != MH_OK)
		{
			LOGE << "Unable to initialize minhook!";
		}

		// -----------------------------------------------------------------------------------------------------

		// Achievements hooks.

		// -----------------------------------------------------------------------------------------------------

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_ACH_GetAchievementImage",
		                     static_cast<LPVOID>(&UPLAY_ACH_GetAchievementImage), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_ACH_GetAchievementImage hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_ACH_EarnAchievement",
		                     static_cast<LPVOID>(&UPLAY_ACH_EarnAchievement), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_ACH_EarnAchievement hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_ACH_Write",
		                     static_cast<LPVOID>(&UPLAY_ACH_Write), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_ACH_Write hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_ACH_GetAchievements",
		                     static_cast<LPVOID>(&UPLAY_ACH_GetAchievements), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_ACH_GetAchievements hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_ACH_ReleaseAchievementList",
		                     static_cast<LPVOID>(&UPLAY_ACH_GetAchievements), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_ACH_ReleaseAchievementList hook!";
		}

		// -----------------------------------------------------------------------------------------------------

		// Avatar hooks.

		// -----------------------------------------------------------------------------------------------------

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_AVATAR_GetBitmap",
		                     static_cast<LPVOID>(&UPLAY_AVATAR_GetBitmap), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_AVATAR_GetBitmap hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_AVATAR_GetAvatarIdForCurrentUser",
		                     static_cast<LPVOID>(&UPLAY_AVATAR_GetAvatarIdForCurrentUser), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_AVATAR_GetAvatarIdForCurrentUser hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_AVATAR_Get",
		                     static_cast<LPVOID>(&UPLAY_AVATAR_Get), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_AVATAR_Get hook!";
		}

		// -----------------------------------------------------------------------------------------------------

		// Common hooks.

		// -----------------------------------------------------------------------------------------------------

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_Startup",
		                     static_cast<LPVOID>(&UPLAY_Startup), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_Startup hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_Start",
		                     static_cast<LPVOID>(&UPLAY_Start), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_Start hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_Quit",
		                     static_cast<LPVOID>(&UPLAY_Quit), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_Quit hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_HasOverlappedOperationCompleted",
		                     static_cast<LPVOID>(&UPLAY_HasOverlappedOperationCompleted), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_HasOverlappedOperationCompleted hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_Init",
		                     static_cast<LPVOID>(&UPLAY_Init), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_Init hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_GetOverlappedOperationResult",
		                     static_cast<LPVOID>(&UPLAY_GetOverlappedOperationResult), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_GetOverlappedOperationResult hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_Update",
		                     static_cast<LPVOID>(&UPLAY_Update), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_Update hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_Release",
		                     static_cast<LPVOID>(&UPLAY_Release), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_Release hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_GetNextEvent",
		                     static_cast<LPVOID>(&UPLAY_GetNextEvent), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_GetNextEvent hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_GetLastError",
		                     static_cast<LPVOID>(&UPLAY_GetLastError), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_GetLastError hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_GetInstallationError",
		                     static_cast<LPVOID>(&UPLAY_GetInstallationError), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_GetInstallationError hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_SetGameSession",
		                     static_cast<LPVOID>(&UPLAY_SetGameSession), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_SetGameSession hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_ClearGameSession",
		                     static_cast<LPVOID>(&UPLAY_ClearGameSession), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_ClearGameSession hook!";
		}

		// -----------------------------------------------------------------------------------------------------

		// Friends hooks.

		// -----------------------------------------------------------------------------------------------------

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_FRIENDS_Init",
		                     static_cast<LPVOID>(&UPLAY_FRIENDS_Init), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_FRIENDS_Init hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_FRIENDS_GetFriendList",
		                     static_cast<LPVOID>(&UPLAY_FRIENDS_GetFriendList), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_FRIENDS_GetFriendList hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_FRIENDS_RequestFriendship",
		                     static_cast<LPVOID>(&UPLAY_FRIENDS_RequestFriendship), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_FRIENDS_RequestFriendship hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_FRIENDS_IsFriend",
		                     static_cast<LPVOID>(&UPLAY_FRIENDS_IsFriend), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_FRIENDS_IsFriend hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_FRIENDS_AddToBlackList",
		                     static_cast<LPVOID>(&UPLAY_FRIENDS_AddToBlackList), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_FRIENDS_AddToBlackList hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_FRIENDS_IsBlackListed",
		                     static_cast<LPVOID>(&UPLAY_FRIENDS_IsBlackListed), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_FRIENDS_IsBlackListed hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_FRIENDS_ShowFriendSelectionUI",
		                     static_cast<LPVOID>(&UPLAY_FRIENDS_ShowFriendSelectionUI), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_FRIENDS_ShowFriendSelectionUI hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_FRIENDS_EnableFriendMenuItem",
		                     static_cast<LPVOID>(&UPLAY_FRIENDS_EnableFriendMenuItem), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_FRIENDS_EnableFriendMenuItem hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_FRIENDS_DisableFriendMenuItem",
		                     static_cast<LPVOID>(&UPLAY_FRIENDS_DisableFriendMenuItem), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_FRIENDS_DisableFriendMenuItem hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_FRIENDS_InviteToGame",
		                     static_cast<LPVOID>(&UPLAY_FRIENDS_InviteToGame), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_FRIENDS_InviteToGame hook!";
		}

		// -----------------------------------------------------------------------------------------------------

		// Installer hooks.

		// -----------------------------------------------------------------------------------------------------

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_INSTALLER_Init",
		                     static_cast<LPVOID>(&UPLAY_INSTALLER_Init), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_INSTALLER_Init hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_INSTALLER_Init",
		                     static_cast<LPVOID>(&UPLAY_INSTALLER_Init), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_INSTALLER_Init hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_INSTALLER_UpdateInstallOrder",
		                     static_cast<LPVOID>(&UPLAY_INSTALLER_UpdateInstallOrder), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_INSTALLER_UpdateInstallOrder hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_INSTALLER_AreChunksInstalled",
		                     static_cast<LPVOID>(&UPLAY_INSTALLER_AreChunksInstalled), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_INSTALLER_AreChunksInstalled hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_INSTALLER_GetChunks",
		                     static_cast<LPVOID>(&UPLAY_INSTALLER_GetChunks), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_INSTALLER_GetChunks hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_INSTALLER_GetChunkIdsFromTag",
		                     static_cast<LPVOID>(&UPLAY_INSTALLER_GetChunkIdsFromTag), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_INSTALLER_GetChunkIdsFromTag hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_INSTALLER_GetLanguageUtf8",
		                     static_cast<LPVOID>(&UPLAY_INSTALLER_GetLanguageUtf8), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_INSTALLER_GetLanguageUtf8 hook!";
		}

		// -----------------------------------------------------------------------------------------------------

		// MetaData hooks.

		// -----------------------------------------------------------------------------------------------------

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_METADATA_SetSingleEventTag",
		                     static_cast<LPVOID>(&UPLAY_METADATA_SetSingleEventTag), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_METADATA_SetSingleEventTag hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_METADATA_SetContinuousTag",
		                     static_cast<LPVOID>(&UPLAY_METADATA_SetContinuousTag), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_METADATA_SetContinuousTag hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_METADATA_ClearContinuousTag",
		                     static_cast<LPVOID>(&UPLAY_METADATA_ClearContinuousTag), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_METADATA_ClearContinuousTag hook!";
		}

		// -----------------------------------------------------------------------------------------------------

		// Overlay hooks.

		// -----------------------------------------------------------------------------------------------------

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_OVERLAY_Show",
		                     static_cast<LPVOID>(&UPLAY_OVERLAY_Show), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_OVERLAY_Show hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_OVERLAY_SetShopUrl",
		                     static_cast<LPVOID>(&UPLAY_OVERLAY_SetShopUrl), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_OVERLAY_SetShopUrl hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_OVERLAY_ShowShopUrl",
		                     static_cast<LPVOID>(&UPLAY_OVERLAY_ShowShopUrl), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_OVERLAY_ShowShopUrl hook!";
		}

		// -----------------------------------------------------------------------------------------------------

		// Party hooks.

		// -----------------------------------------------------------------------------------------------------

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_PARTY_Init",
		                     static_cast<LPVOID>(&UPLAY_PARTY_Init), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_PARTY_Init hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_PARTY_Init",
		                     static_cast<LPVOID>(&UPLAY_PARTY_InviteToParty), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_PARTY_InviteToParty hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_PARTY_RespondToGameInvite",
		                     static_cast<LPVOID>(&UPLAY_PARTY_RespondToGameInvite), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_PARTY_RespondToGameInvite hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_PARTY_ShowGameInviteOverlayUI",
		                     static_cast<LPVOID>(&UPLAY_PARTY_ShowGameInviteOverlayUI), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_PARTY_ShowGameInviteOverlayUI hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_PARTY_GetInGameMemberList",
		                     static_cast<LPVOID>(&UPLAY_PARTY_GetInGameMemberList), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_PARTY_GetInGameMemberList hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_PARTY_GetFullMemberList",
		                     static_cast<LPVOID>(&UPLAY_PARTY_GetFullMemberList), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_PARTY_GetFullMemberList hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_PARTY_SetUserData",
		                     static_cast<LPVOID>(&UPLAY_PARTY_SetUserData), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_PARTY_SetUserData hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_PARTY_IsInParty",
		                     static_cast<LPVOID>(&UPLAY_PARTY_IsInParty), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_PARTY_IsInParty hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_PARTY_IsPartyLeader",
		                     static_cast<LPVOID>(&UPLAY_PARTY_IsPartyLeader), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_PARTY_IsPartyLeader hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_PARTY_PromoteToLeader",
		                     static_cast<LPVOID>(&UPLAY_PARTY_PromoteToLeader), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_PARTY_PromoteToLeader hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_PARTY_InvitePartyToGame",
		                     static_cast<LPVOID>(&UPLAY_PARTY_InvitePartyToGame), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_PARTY_InvitePartyToGame hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_PARTY_EnablePartyMemberMenuItem",
		                     static_cast<LPVOID>(&UPLAY_PARTY_EnablePartyMemberMenuItem), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_PARTY_EnablePartyMemberMenuItem hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_PARTY_DisablePartyMemberMenuItem",
		                     static_cast<LPVOID>(&UPLAY_PARTY_DisablePartyMemberMenuItem), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_PARTY_DisablePartyMemberMenuItem hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_PARTY_SetGuest",
		                     static_cast<LPVOID>(&UPLAY_PARTY_SetGuest), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_PARTY_SetGuest hook!";
		}

		// -----------------------------------------------------------------------------------------------------

		// Save hooks.

		// -----------------------------------------------------------------------------------------------------

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_SAVE_GetSavegames",
		                     static_cast<LPVOID>(&UPLAY_SAVE_GetSavegames), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_SAVE_GetSavegames hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_SAVE_Open",
		                     static_cast<LPVOID>(&UPLAY_SAVE_Open), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_SAVE_GetSavegames hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_SAVE_Close",
		                     static_cast<LPVOID>(&UPLAY_SAVE_Close), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_SAVE_Close hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_SAVE_Read",
		                     static_cast<LPVOID>(&UPLAY_SAVE_Read), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_SAVE_Read hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_SAVE_Write",
		                     static_cast<LPVOID>(&UPLAY_SAVE_Write), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_SAVE_Write hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_SAVE_SetName",
		                     static_cast<LPVOID>(&UPLAY_SAVE_SetName), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_SAVE_SetName hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_SAVE_Remove",
		                     static_cast<LPVOID>(&UPLAY_SAVE_Remove), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_SAVE_Remove hook!";
		}

		// -----------------------------------------------------------------------------------------------------

		// User hooks.

		// -----------------------------------------------------------------------------------------------------

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_USER_GetCdKeys",
		                     static_cast<LPVOID>(&UPLAY_USER_GetCdKeys), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_USER_GetCdKeys hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_USER_ReleaseCdKeyList",
		                     static_cast<LPVOID>(&UPLAY_USER_ReleaseCdKeyList), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_USER_ReleaseCdKeyList hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_USER_GetCredentials",
		                     static_cast<LPVOID>(&UPLAY_USER_GetCredentials), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_USER_GetCredentials hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_USER_GetCdKeyUtf8",
		                     static_cast<LPVOID>(&UPLAY_USER_GetCdKeyUtf8), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_USER_GetCdKeyUtf8 hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_USER_GetAccountIdUtf8",
		                     static_cast<LPVOID>(&UPLAY_USER_GetAccountIdUtf8), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_USER_GetAccountIdUtf8 hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_USER_GetUsernameUtf8",
		                     static_cast<LPVOID>(&UPLAY_USER_GetUsernameUtf8), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_USER_GetUsernameUtf8 hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_USER_GetNameUtf8",
		                     static_cast<LPVOID>(&UPLAY_USER_GetNameUtf8), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_USER_GetNameUtf8 hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_USER_GetEmailUtf8",
		                     static_cast<LPVOID>(&UPLAY_USER_GetEmailUtf8), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_USER_GetEmailUtf8 hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_USER_GetPasswordUtf8",
		                     static_cast<LPVOID>(&UPLAY_USER_GetPasswordUtf8), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_USER_GetPasswordUtf8 hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_USER_GetAccountId",
		                     static_cast<LPVOID>(&UPLAY_USER_GetAccountId), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_USER_GetAccountId hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_USER_GetUsername",
		                     static_cast<LPVOID>(&UPLAY_USER_GetUsername), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_USER_GetUsername hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_USER_GetEmail",
		                     static_cast<LPVOID>(&UPLAY_USER_GetEmail), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_USER_GetEmail hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_USER_GetPassword",
		                     static_cast<LPVOID>(&UPLAY_USER_GetPassword), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_USER_GetPassword hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_USER_IsConnected",
		                     static_cast<LPVOID>(&UPLAY_USER_IsConnected), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_USER_IsConnected hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_USER_IsOwned",
		                     static_cast<LPVOID>(&UPLAY_USER_IsOwned), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_USER_IsOwned hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_USER_IsInOfflineMode",
		                     static_cast<LPVOID>(&UPLAY_USER_IsInOfflineMode), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_USER_IsInOfflineMode hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_USER_GetTicketUtf8",
		                     static_cast<LPVOID>(&UPLAY_USER_GetTicketUtf8), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_USER_GetTicketUtf8 hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_USER_ConsumeItem",
		                     static_cast<LPVOID>(&UPLAY_USER_ConsumeItem), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_USER_ConsumeItem hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_USER_GetConsumeItem",
		                     static_cast<LPVOID>(&UPLAY_USER_GetConsumeItem), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_USER_GetConsumeItem hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_USER_GetConsumableItems",
		                     static_cast<LPVOID>(&UPLAY_USER_GetConsumableItems), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_USER_GetConsumableItems hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_USER_ReleaseConsumeItemResult",
		                     static_cast<LPVOID>(&UPLAY_USER_ReleaseConsumeItemResult), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_USER_ReleaseConsumeItemResult hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_USER_SetGameSession",
		                     static_cast<LPVOID>(&UPLAY_USER_SetGameSession), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_USER_SetGameSession hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_USER_ClearGameSession",
		                     static_cast<LPVOID>(&UPLAY_USER_ClearGameSession), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_USER_ClearGameSession hook!";
		}

		// -----------------------------------------------------------------------------------------------------

		// Win hooks.

		// -----------------------------------------------------------------------------------------------------

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_WIN_GetRewards",
		                     static_cast<LPVOID>(&UPLAY_WIN_GetRewards), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_WIN_GetRewards hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_WIN_RefreshActions",
		                     static_cast<LPVOID>(&UPLAY_WIN_RefreshActions), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_WIN_RefreshActions hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_WIN_SetActionsCompleted",
		                     static_cast<LPVOID>(&UPLAY_WIN_SetActionsCompleted), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_WIN_SetActionsCompleted hook!";
		}

		// -----------------------------------------------------------------------------------------------------

		// Options hooks.

		// -----------------------------------------------------------------------------------------------------

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_OPTIONS_Open",
		                     static_cast<LPVOID>(&UPLAY_OPTIONS_Open), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_OPTIONS_Open hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_OPTIONS_Enumerate",
		                     static_cast<LPVOID>(&UPLAY_OPTIONS_Enumerate), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_OPTIONS_Enumerate hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_OPTIONS_Set",
		                     static_cast<LPVOID>(&UPLAY_OPTIONS_Set), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_OPTIONS_Set hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_OPTIONS_Apply",
		                     static_cast<LPVOID>(&UPLAY_OPTIONS_Apply), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_OPTIONS_Apply hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_OPTIONS_ReleaseKeyValueList",
		                     static_cast<LPVOID>(&UPLAY_OPTIONS_ReleaseKeyValueList), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_OPTIONS_ReleaseKeyValueList hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_OPTIONS_Close",
		                     static_cast<LPVOID>(&UPLAY_OPTIONS_Close), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_OPTIONS_Close hook!";
		}

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_OPTIONS_SetInGameState",
		                     static_cast<LPVOID>(&UPLAY_OPTIONS_SetInGameState), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_OPTIONS_SetInGameState hook!";
		}

		// -----------------------------------------------------------------------------------------------------

		// Presence hooks.

		// -----------------------------------------------------------------------------------------------------

		if (MH_CreateHookApi(UPLAY_R1_ORIGINAL_DLL_NAME, "UPLAY_PRESENCE_SetPresence",
		                     static_cast<LPVOID>(&UPLAY_PRESENCE_SetPresence), nullptr) != MH_OK)
		{
			LOGE << "Unable to install UPLAY_PRESENCE_SetPresence hook!";
		}

		// -----------------------------------------------------------------------------------------------------

		// ReSharper disable CppZeroConstantCanBeReplacedWithNullptr
		if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK)
			// ReSharper restore CppZeroConstantCanBeReplacedWithNullptr
		{
			LOGE << "Hooks cannot be enabled!";
		}
	}
} // namespace UplayR1Loader
