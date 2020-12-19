#pragma once

#include "src/pch.h"

#include "src/Macro.hpp"
#include "src/Types/UplayList.hpp"
#include "src/Types/UplayOverlapped.hpp"

#include "src/Objects/UplayConfig.hpp"

namespace UplayR1Loader
{
	// ReSharper disable CppInconsistentNaming
	UPLAY_API inline long UPLAY_FUNC UPLAY_USER_GetCdKeys(
		UplayList** outCdKeyList, UplayOverlapped* overlapped)
	{
		LOGD << fmt::format("OutCdKeyList: {}  Overlapped: {}", reinterpret_cast<void *>(&outCdKeyList),
		                    reinterpret_cast<void *>(&overlapped));

		const auto& uplayKeys = Singleton<UplayConfig>::Instance().Get().Uplay.CdKeys;
		auto* const list = new UplayList{0};

		const auto keysSize = static_cast<int>(uplayKeys.size());
		auto* const keys = new UplayKey *[keysSize]{nullptr};

		list->Keys = keys;
		list->Count = keysSize;

		for (auto i = 0; i < keysSize; i++)
		{
			list->Keys[i] = new UplayKey(uplayKeys.at(i).c_str());
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

	UPLAY_API inline long UPLAY_FUNC UPLAY_USER_ReleaseCdKeyList(UplayList* cdKeyList)
	{
		LOGD << fmt::format("CdKeyList: {}", reinterpret_cast<void *>(&cdKeyList));
		delete cdKeyList;
		return 1;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_USER_GetCredentials(char* credentials,
	                                                           UplayOverlapped* overlapped)
	{
		LOGD << fmt::format("Credentials: {}  Overlapped: {}", reinterpret_cast<void *>(&credentials),
		                    reinterpret_cast<void *>(&overlapped));

		const auto& username = Singleton<UplayConfig>::Instance().Get().Uplay.Profile.Username;

		strcpy_s(credentials, username.size() + 1, username.c_str());

#ifdef UPLAY_API_2014_NEXT_GEN
		overlapped->SetResult();
#else
		overlapped->SetZeros();
		overlapped->SetResult(credentials);
#endif

		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_USER_GetCdKeyUtf8()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline LPCSTR UPLAY_FUNC UPLAY_USER_GetAccountIdUtf8()
	{
		LOGD << "__CALL__";
		return Singleton<UplayConfig>::Instance().Get().Uplay.Profile.AccountId.c_str();
	}

	UPLAY_API inline LPCSTR UPLAY_FUNC UPLAY_USER_GetUsernameUtf8()
	{
		LOGD << "__CALL__";
		return Singleton<UplayConfig>::Instance().Get().Uplay.Profile.Username.c_str();
	}

	UPLAY_API inline LPCSTR UPLAY_FUNC UPLAY_USER_GetNameUtf8()
	{
		LOGD << "__CALL__";
		return Singleton<UplayConfig>::Instance().Get().Uplay.Profile.Username.c_str();
	}

	UPLAY_API inline LPCSTR UPLAY_FUNC UPLAY_USER_GetEmailUtf8()
	{
		LOGD << "__CALL__";
		return Singleton<UplayConfig>::Instance().Get().Uplay.Profile.Email.c_str();
	}

	UPLAY_API inline LPCSTR UPLAY_FUNC UPLAY_USER_GetPasswordUtf8()
	{
		LOGD << "__CALL__";
		return Singleton<UplayConfig>::Instance().Get().Uplay.Profile.Password.c_str();
	}

	UPLAY_API inline LPCSTR UPLAY_FUNC UPLAY_USER_GetAccountId()
	{
		LOGD << "__CALL__";
		return Singleton<UplayConfig>::Instance().Get().Uplay.Profile.AccountId.c_str();
	}

	UPLAY_API inline LPCSTR UPLAY_FUNC UPLAY_USER_GetUsername()
	{
		LOGD << "__CALL__";
		return Singleton<UplayConfig>::Instance().Get().Uplay.Profile.Username.c_str();
	}

	UPLAY_API inline LPCSTR UPLAY_FUNC UPLAY_USER_GetEmail()
	{
		LOGD << "__CALL__";
		return Singleton<UplayConfig>::Instance().Get().Uplay.Profile.Email.c_str();
	}

	UPLAY_API inline LPCSTR UPLAY_FUNC UPLAY_USER_GetPassword()
	{
		LOGD << "__CALL__";
		return Singleton<UplayConfig>::Instance().Get().Uplay.Profile.Password.c_str();
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_USER_IsConnected()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_USER_IsOwned(const char* buffer)
	{
		LOGD << fmt::format("Buffer: {}", reinterpret_cast<const void *>(&buffer));
		return 1;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_USER_IsInOfflineMode()
	{
		LOGD << "__CALL__";
		return static_cast<int>(Singleton<UplayConfig>::Instance().Get().Uplay.OfflineMode);
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_USER_GetTicketUtf8()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_USER_ConsumeItem()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_USER_GetConsumeItem()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_USER_GetConsumableItems()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_USER_ReleaseConsumeItemResult()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_USER_SetGameSession()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_USER_ClearGameSession()
	{
		LOGD << "__CALL__";
		return 1;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_USER_GetGPUScoreConfidenceLevel()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_USER_GetGPUScore()
	{
		LOGD << "__CALL__";
		return 0;
	}

	UPLAY_API inline long UPLAY_FUNC UPLAY_USER_GetCPUScore()
	{
		LOGD << "__CALL__";
		return 0;
	}

	// ReSharper restore CppInconsistentNaming
} // namespace UplayR1Loader
