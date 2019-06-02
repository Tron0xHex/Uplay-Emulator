#pragma once

#include "JsonTypes/Generators.hpp"
#include "JsonTypes/UplayConfig.hpp"

struct UplayConfigHolder
{
	UplayR1Loader::UplayConfig config;
	void Open(const path& filePath);
};

inline void UplayConfigHolder::Open(const path& filePath)
{
	const auto fs = fstream(filePath, ios::in);
	const auto jsonString = static_cast<stringstream const&>(stringstream() << fs.rdbuf()).str();

	config = json::parse(jsonString);
}