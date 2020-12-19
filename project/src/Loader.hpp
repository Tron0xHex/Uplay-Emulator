#pragma once

#include "src/pch.h"

#include "Hooks.hpp"
#include "Consts.hpp"

#include "Helpers/Json.hpp"
#include "Objects/UplayConfig.hpp"

// ReSharper disable CppUnusedIncludeDirective
#include "Exports/UplayAch.hpp"
#include "Exports/UplayAvatar.hpp"
#include "Exports/UplayCommon.hpp"
#include "Exports/UplayFriends.hpp"
#include "Exports/UplayInstaller.hpp"
#include "Exports/UplayMetaData.hpp"
#include "Exports/UplayOverlay.hpp"
#include "Exports/UplayParty.hpp"
#include "Exports/UplaySave.hpp"
#include "Exports/UplayUser.hpp"
#include "Exports/UplayWin.hpp"
// ReSharper restore CppUnusedIncludeDirective

namespace UplayR1Loader
{
	using std::filesystem::path;

	inline void InitConfig()
	{
		const auto currentPath = filesystem::current_path();
		const auto configPath = currentPath / path(CONFIG_NAME);

		FailCheck(!exists(configPath), fmt::format("{} file not found!", CONFIG_NAME));
		FailCheck(exists(configPath) && filesystem::is_empty(configPath),
		          fmt::format("{} file is empty!", CONFIG_NAME));

		UplayConfig config;
		NameValuePair<Uplay&> uplay("Uplay", config.Uplay);

		DeserializeFromJsonFile(configPath, uplay);

		FailCheck(config.Uplay.Saves.empty(), "Saves path is empty!");
		FailCheck(config.Uplay.Profile.Email.empty(), "Email is empty!");
		FailCheck(config.Uplay.Profile.Username.empty(), "Username is empty!");
		FailCheck(config.Uplay.Profile.Password.empty(), "Password is empty!");
		FailCheck(config.Uplay.Profile.AccountId.empty(), "Account id is empty!");
		FailCheck(config.Uplay.Log.Write && config.Uplay.Log.Path.empty(), "Log path is empty!");

		Singleton<UplayConfig>::Instance().Set(config);
	}

	inline void InitLog()
	{
		if (Singleton<UplayConfig>::Instance().Get().Uplay.Log.Write)
		{
			const auto& logFile = Singleton<UplayConfig>::Instance().Get().Uplay.Log.Path;

			FailCheck(filesystem::exists(logFile) && !filesystem::remove(logFile),
			          fmt::format("Unable to remove {}!", logFile));

			init(plog::debug, logFile.c_str());
		}
	}

	inline void InitHooks()
	{
		if (Singleton<UplayConfig>::Instance().Get().Uplay.InstallHooks)
		{
			wchar_t buff[MAX_PATH]{NULL};

			if (GetModuleFileNameW(nullptr, buff, MAX_PATH))
			{
				const auto dllPath = path(buff);
				const auto hookModule = dllPath.filename().wstring() + dllPath.extension().wstring();

				FailCheck(hookModule == UPLAY_R1_ORIGINAL_DLL_NAME, "Can't hook functions in self module!");

				InstallHooks();
			}
		}
	}
} // namespace UplayR1Loader
