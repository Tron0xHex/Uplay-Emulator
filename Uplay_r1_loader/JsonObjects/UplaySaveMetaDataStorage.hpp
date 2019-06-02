// UplaySaveMetaDataStorage.hpp

//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     UplaySaveMetaDataStorage.hpp data = nlohmann::json::parse(jsonString);

#pragma once

#include <nlohmann/json.hpp>

namespace UplayR1Loader
{
	using nlohmann::json;

	struct UplaySaveMetaDataStorage
	{
		std::map<std::string, std::string> saves;
	};
}
