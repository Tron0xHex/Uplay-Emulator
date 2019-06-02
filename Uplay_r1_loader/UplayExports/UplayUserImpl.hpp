#pragma once

#include <plog/Log.h>

#include "../UplayConfigSingleton.hpp"
#include "../UplayTypes/UplayList.hpp"
#include "../UplayTypes/UplayOverlapped.hpp"

UPLAY_API inline DWORD UPLAY_FUNC UPLAY_USER_GetCdKeys(
	UplayList **outCdKeyList, UplayOverlapped *overlapped)
{
	LOGD_IF(UPLAY_LOG) << hex << "OutCdKeyList: " << outCdKeyList << " Overlapped: "
		<< overlapped;

	overlapped->SetZeros();

	const auto uplayKeys = UplayConfigSingleton::GetInstance().configHolder.config.uplay.cdKeys;

	const auto list = new UplayList{ NULL };
	const auto keys = new UplayKey *[uplayKeys.size()]{ nullptr };

	list->keys = keys;
	list->count = uplayKeys.size();

	for (size_t i = 0; i < uplayKeys.size(); i++)
	{
		list->keys[i] = new UplayKey(uplayKeys.at(i).c_str());
	}

	*outCdKeyList = list;

	overlapped->SetResult(&outCdKeyList);
	return 1L;
}

UPLAY_API inline DWORD UPLAY_FUNC UPLAY_USER_GetCredentials(const LPSTR credentials)
{
	LOGD_IF(UPLAY_LOG) << "__CALL__";
	lstrcpyA(credentials, UplayConfigSingleton::GetInstance()
		.configHolder.config.uplay.profile.userName.c_str());
	return 0L;
}

UPLAY_API inline DWORD UPLAY_FUNC UPLAY_USER_GetCdKeyUtf8()
{
	LOGD_IF(UPLAY_LOG) << "__CALL__";
	return 0L;
}

UPLAY_API inline LPCSTR UPLAY_FUNC UPLAY_USER_GetAccountIdUtf8()
{
	LOGD_IF(UPLAY_LOG) << "__CALL__";
	return UplayConfigSingleton::GetInstance()
		.configHolder.config.uplay.profile.accountId.c_str();
}

UPLAY_API inline LPCSTR UPLAY_FUNC UPLAY_USER_GetUsernameUtf8()
{
	LOGD_IF(UPLAY_LOG) << "__CALL__";
	return UplayConfigSingleton::GetInstance()
		.configHolder.config.uplay.profile.userName.c_str();
}

UPLAY_API inline LPCSTR UPLAY_FUNC UPLAY_USER_GetNameUtf8()
{
	LOGD_IF(UPLAY_LOG) << "__CALL__";
	return UplayConfigSingleton::GetInstance()
		.configHolder.config.uplay.profile.userName.c_str();
}


UPLAY_API inline LPCSTR UPLAY_FUNC UPLAY_USER_GetEmailUtf8()
{
	LOGD_IF(UPLAY_LOG) << "__CALL__";
	return UplayConfigSingleton::GetInstance()
		.configHolder.config.uplay.profile.email.c_str();
}

UPLAY_API inline LPCSTR UPLAY_FUNC UPLAY_USER_GetPasswordUtf8()
{
	LOGD_IF(UPLAY_LOG) << "__CALL__";
	return UplayConfigSingleton::GetInstance()
		.configHolder.config.uplay.profile.password.c_str();
}

UPLAY_API inline LPCSTR UPLAY_FUNC UPLAY_USER_GetAccountId()
{
	LOGD_IF(UPLAY_LOG) << "__CALL__";
	return UplayConfigSingleton::GetInstance()
		.configHolder.config.uplay.profile.accountId.c_str();
}

UPLAY_API inline LPCSTR UPLAY_FUNC UPLAY_USER_GetUsername()
{
	LOGD_IF(UPLAY_LOG) << "__CALL__";
	return UplayConfigSingleton::GetInstance()
		.configHolder.config.uplay.profile.userName.c_str();
}

UPLAY_API inline LPCSTR UPLAY_FUNC UPLAY_USER_GetEmail()
{
	LOGD_IF(UPLAY_LOG) << "__CALL__";
	return UplayConfigSingleton::GetInstance()
		.configHolder.config.uplay.profile.email.c_str();
}

UPLAY_API inline LPCSTR UPLAY_FUNC UPLAY_USER_GetPassword()
{
	LOGD_IF(UPLAY_LOG) << "__CALL__";
	return UplayConfigSingleton::GetInstance()
		.configHolder.config.uplay.profile.password.c_str();
}

UPLAY_API inline DWORD UPLAY_FUNC UPLAY_USER_IsConnected()
{
	LOGD_IF(UPLAY_LOG) << "__CALL__";
	return 1L;
}

UPLAY_API inline DWORD UPLAY_FUNC UPLAY_USER_IsOwned()
{
	LOGD_IF(UPLAY_LOG) << "__CALL__";
	return 0L;
}

UPLAY_API inline DWORD UPLAY_FUNC UPLAY_USER_IsInOfflineMode()
{
	LOGD_IF(UPLAY_LOG) << "__CALL__";
	return 0L;
}

UPLAY_API inline DWORD UPLAY_FUNC UPLAY_USER_GetTicketUtf8()
{
	LOGD_IF(UPLAY_LOG) << "__CALL__";
	return 0L;
}

UPLAY_API inline DWORD UPLAY_FUNC UPLAY_USER_ConsumeItem()
{
	LOGD_IF(UPLAY_LOG) << "__CALL__";
	return 0L;
}

UPLAY_API inline DWORD UPLAY_FUNC UPLAY_USER_GetConsumeItem()
{
	LOGD_IF(UPLAY_LOG) << "__CALL__";
	return 0L;
}

UPLAY_API inline DWORD UPLAY_FUNC UPLAY_USER_GetConsumableItems()
{
	LOGD_IF(UPLAY_LOG) << "__CALL__";
	return 0L;
}


UPLAY_API inline DWORD UPLAY_FUNC UPLAY_USER_ReleaseConsumeItemResult()
{
	LOGD_IF(UPLAY_LOG) << "__CALL__";
	return 0L;
}

UPLAY_API inline DWORD UPLAY_FUNC UPLAY_USER_SetGameSession()
{
	LOGD_IF(UPLAY_LOG) << "__CALL__";
	return 0L;
}

UPLAY_API inline DWORD UPLAY_FUNC UPLAY_USER_ClearGameSession()
{
	LOGD_IF(UPLAY_LOG) << "__CALL__";
	return 1L;
}