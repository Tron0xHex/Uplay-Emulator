#pragma once

#include "src/pch.h"

namespace UplayR1Loader
{
	using namespace std;
	using namespace cereal;

	struct Log
	{
		bool Write;
		string Path;

		// ReSharper disable CppInconsistentNaming
		template <class Archive>
		void serialize(Archive& ar)
		{
			ar(CEREAL_NVP(Write), CEREAL_NVP(Path));
		}

		// ReSharper restore CppInconsistentNaming
	};

	struct Profile
	{
		string AccountId;
		string Email;
		string Username;
		string Password;

		// ReSharper disable CppInconsistentNaming
		template <class Archive>
		void serialize(Archive& ar)
		{
			ar(CEREAL_NVP(AccountId), CEREAL_NVP(Email), CEREAL_NVP(Username), CEREAL_NVP(Password));
		}

		// ReSharper restore CppInconsistentNaming
	};

	struct Uplay
	{
		Profile Profile;
		vector<string> CdKeys;
		string Saves;
		Log Log;
		string Language;
		bool OfflineMode;
		bool InstallHooks;

		// ReSharper disable CppInconsistentNaming
		template <class Archive>
		void serialize(Archive& ar)
		{
			ar(CEREAL_NVP(Profile),
			   CEREAL_NVP(CdKeys),
			   CEREAL_NVP(Saves),
			   CEREAL_NVP(Log),
			   CEREAL_NVP(Language),
			   CEREAL_NVP(OfflineMode),
			   CEREAL_NVP(InstallHooks));
		}

		// ReSharper restore CppInconsistentNaming
	};

	struct UplayConfig
	{
		Uplay Uplay;
	};
} // namespace UplayR1Loader
