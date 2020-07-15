#pragma once

#include "JsonObjects/Generators.hpp"
#include "JsonObjects/UplayConfig.hpp"

namespace UplayR1Loader
{
	struct EUplayConfigHolder
	{
		JsonObjects::UplayConfig config;
		void Open(const path& filePath);
	};

	//------------------------------------------------------------------------------
	inline void EUplayConfigHolder::Open(const path& filePath)
	{
		const auto fs = fstream(filePath, ios::in);
		const auto jsonString = static_cast<stringstream const&>(stringstream() << fs.rdbuf()).str();

		config = json::parse(jsonString);
	}
}
