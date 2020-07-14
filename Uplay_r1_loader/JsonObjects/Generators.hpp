// Generators.hpp

//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     Generators.hpp data = nlohmann::json::parse(jsonString);

#pragma once

#include <nlohmann/json.hpp>

#include "UplaySaveMetaDataStorage.hpp"
#include "UplayConfig.hpp"
#include "Uplay.hpp"
#include "Profile.hpp"

namespace nlohmann
{
	void from_json(const json& j, UplayR1Loader::JsonObjects::UplaySaveMetaDataStorage& x);
	void to_json(json& j, const UplayR1Loader::JsonObjects::UplaySaveMetaDataStorage& x);

	inline void from_json(const json& j, UplayR1Loader::JsonObjects::UplaySaveMetaDataStorage& x)
	{
		x.saves = j.at("Saves").get<std::map<std::string, std::string>>();
	}

	inline void to_json(json& j, const UplayR1Loader::JsonObjects::UplaySaveMetaDataStorage& x)
	{
		j = json::object();
		j["Saves"] = x.saves;
	}

	void from_json(const json& j, UplayR1Loader::JsonObjects::Profile& x);
	void to_json(json& j, const UplayR1Loader::JsonObjects::Profile& x);

	void from_json(const json& j, UplayR1Loader::JsonObjects::Uplay& x);
	void to_json(json& j, const UplayR1Loader::JsonObjects::Uplay& x);

	void from_json(const json& j, UplayR1Loader::JsonObjects::UplayConfig& x);
	void to_json(json& j, const UplayR1Loader::JsonObjects::UplayConfig& x);

	inline void from_json(const json& j, UplayR1Loader::JsonObjects::Profile& x)
	{
		x.accountId = j.at("AccountId").get<std::string>();
		x.email = j.at("Email").get<std::string>();
		x.userName = j.at("UserName").get<std::string>();
		x.password = j.at("Password").get<std::string>();
	}

	inline void to_json(json& j, const UplayR1Loader::JsonObjects::Profile& x)
	{
		j = json::object();
		j["AccountId"] = x.accountId;
		j["Email"] = x.email;
		j["UserName"] = x.userName;
		j["Password"] = x.password;
	}

	inline void from_json(const json& j, UplayR1Loader::JsonObjects::Uplay& x)
	{
		x.profile = j.at("Profile").get<UplayR1Loader::JsonObjects::Profile>();
		x.saves = j.at("Saves").get<std::string>();
		x.cdKeys = j.at("CdKeys").get<std::vector<std::string>>();
		x.language = j.at("Language").get<std::string>();
		x.offline = j.at("Offline").get<bool>();
		x.hooks = j.at("Hooks").get<bool>();
		x.log = j.at("Log").get<bool>();
	}

	inline void to_json(json& j, const UplayR1Loader::JsonObjects::Uplay& x)
	{
		j = json::object();
		j["Profile"] = x.profile;
		j["Saves"] = x.saves;
		j["CdKeys"] = x.cdKeys;
		j["Language"] = x.language;
		j["Offline"] = x.offline;
		j["Hooks"] = x.hooks;
		j["Log"] = x.log;
	}

	inline void from_json(const json& j, UplayR1Loader::JsonObjects::UplayConfig& x)
	{
		x.uplay = j.at("Uplay").get<UplayR1Loader::JsonObjects::Uplay>();
	}

	inline void to_json(json& j, const UplayR1Loader::JsonObjects::UplayConfig& x)
	{
		j = json::object();
		j["Uplay"] = x.uplay;
	}
}
