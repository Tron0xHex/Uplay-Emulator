// Uplay.hpp

//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     Uplay.hpp data = nlohmann::json::parse(jsonString);

#pragma once

#include <nlohmann/json.hpp>

#include "Profile.hpp"

namespace UplayR1Loader::JsonObjects
{
	using nlohmann::json;

	struct Uplay
	{
		Profile profile;
		std::vector<std::string> cdKeys;
		std::string saves;
	};
}
