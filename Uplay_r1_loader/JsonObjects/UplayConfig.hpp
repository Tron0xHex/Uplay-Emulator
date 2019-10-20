// UplayConfig.hpp

//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     UplayConfig.hpp data = nlohmann::json::parse(jsonString);

#pragma once

#include <nlohmann/json.hpp>

#include "Uplay.hpp"

namespace UplayR1Loader::JsonObjects
{
	using nlohmann::json;

	struct UplayConfig
	{
		Uplay uplay;
	};
}
