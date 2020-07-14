#pragma once

#include <plog/Log.h>

#include "../UplayConfigSingleton.hpp"
#include "../UplayTypes/UplayList.hpp"
#include "../UplayTypes/UplayOverlapped.hpp"

namespace UplayR1Loader::UplayExports
{
	// ReSharper disable CppInconsistentNaming
	UPLAY_API inline int UPLAY_FUNC UPLAY_USER_GetCdKeys(
		UplayTypes::UplayList** outCdKeyList, UplayTypes::UplayOverlapped* overlapped)
	{
		LOGD << hex << "OutCdKeyList: " << outCdKeyList << " Overlapped: "
			<< overlapped;

		const auto uplayKeys = UplayConfigSingleton::GetInstance().configHolder.config.uplay.cdKeys;

		const auto list = new UplayTypes::UplayList{NULL};

		const auto keysSize = static_cast<int>(uplayKeys.size());
		const auto keys = new UplayTypes::UplayKey * [keysSize]{nullptr};

		list->keys = keys;
		list->count = uplayKeys.size();

		for (int i = 0; i < keysSize; i++)
		{
			list->keys[i] = new UplayTypes::UplayKey(uplayKeys.at(i).c_str());
		}

		*outCdKeyList = list;

#ifdef UPLAY_API_2014_NEXT_GEN
		overlapped->SetResult();
#else
		overlapped->SetZeros();
		overlapped->SetResult(&outCdKeyList);
#endif
		return 1;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_USER_ReleaseCdKeyList()
	{
		return 1;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_USER_GetCredentials(const LPSTR credentials,
	                                                          UplayTypes::UplayOverlapped* overlapped)
	{
		LOGD << "__CALL__";

		const auto userName = UplayConfigSingleton::GetInstance()
		                      .configHolder.config.uplay.profile.userName;

		lstrcpyA(credentials, userName.c_str());

#ifdef UPLAY_API_2014_NEXT_GEN
		overlapped->SetResult();
#else
		overlapped->SetZeros();
		overlapped->SetResult(credentials);
#endif

		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_USER_GetCdKeyUtf8()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline LPCSTR UPLAY_FUNC UPLAY_USER_GetAccountIdUtf8()
	{
		LOGD << "__CALL__";
		return UplayConfigSingleton::GetInstance()
		       .configHolder.config.uplay.profile.accountId.c_str();
	}

	UPLAY_API inline LPCSTR UPLAY_FUNC UPLAY_USER_GetUsernameUtf8()
	{
		LOGD << "__CALL__";
		return UplayConfigSingleton::GetInstance()
		       .configHolder.config.uplay.profile.userName.c_str();
	}

	UPLAY_API inline LPCSTR UPLAY_FUNC UPLAY_USER_GetNameUtf8()
	{
		LOGD << "__CALL__";
		return UplayConfigSingleton::GetInstance()
		       .configHolder.config.uplay.profile.userName.c_str();
	}


	UPLAY_API inline LPCSTR UPLAY_FUNC UPLAY_USER_GetEmailUtf8()
	{
		LOGD << "__CALL__";
		return UplayConfigSingleton::GetInstance()
		       .configHolder.config.uplay.profile.email.c_str();
	}

	UPLAY_API inline LPCSTR UPLAY_FUNC UPLAY_USER_GetPasswordUtf8()
	{
		LOGD << "__CALL__";
		return UplayConfigSingleton::GetInstance()
		       .configHolder.config.uplay.profile.password.c_str();
	}

	UPLAY_API inline LPCSTR UPLAY_FUNC UPLAY_USER_GetAccountId()
	{
		LOGD << "__CALL__";
		return UplayConfigSingleton::GetInstance()
		       .configHolder.config.uplay.profile.accountId.c_str();
	}

	UPLAY_API inline LPCSTR UPLAY_FUNC UPLAY_USER_GetUsername()
	{
		LOGD << "__CALL__";
		return UplayConfigSingleton::GetInstance()
		       .configHolder.config.uplay.profile.userName.c_str();
	}

	UPLAY_API inline LPCSTR UPLAY_FUNC UPLAY_USER_GetEmail()
	{
		LOGD << "__CALL__";
		return UplayConfigSingleton::GetInstance()
		       .configHolder.config.uplay.profile.email.c_str();
	}

	UPLAY_API inline LPCSTR UPLAY_FUNC UPLAY_USER_GetPassword()
	{
		LOGD << "__CALL__";
		return UplayConfigSingleton::GetInstance()
		       .configHolder.config.uplay.profile.password.c_str();
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_USER_IsConnected()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_USER_IsOwned(const char* buffer)
	{
		LOGD << "__CALL__";
		return 1;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_USER_IsInOfflineMode()
	{
		LOGD << "__CALL__";
		return static_cast<int>(UplayConfigSingleton::GetInstance()
		                        .configHolder.config.uplay.offline);
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_USER_GetTicketUtf8()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_USER_ConsumeItem()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_USER_GetConsumeItem()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_USER_GetConsumableItems()
	{
		LOGD << "__CALL__";
		return 0;
	}


	UPLAY_API inline int UPLAY_FUNC UPLAY_USER_ReleaseConsumeItemResult()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_USER_SetGameSession()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_USER_ClearGameSession()
	{
		LOGD << "__CALL__";
		return 1;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_USER_GetGPUScoreConfidenceLevel(int* level)
	{
		LOGD << "__CALL__";

		if (level)
		{
			*level = 1;
		}

		return 1;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_USER_GetGPUScore(int* score)
	{
		LOGD << "__CALL__";

		if (score)
		{
			*score = 105;
		}

		return 1;
	}

	UPLAY_API inline int UPLAY_FUNC UPLAY_USER_GetCPUScore(int* score)
	{
		LOGD << "__CALL__";

		if (score)
		{
			*score = 105;
		}

		return 1;
	}
	// ReSharper restore CppInconsistentNaming
}
