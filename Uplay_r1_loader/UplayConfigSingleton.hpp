#pragma once

#include "stdafx.h"

#include "JsonTypes/Generators.hpp"
#include "UplayConfigHolder.hpp"

using namespace UplayR1Loader;

struct UplayConfigSingleton
{
	UplayConfigHolder configHolder;
	static UplayConfigSingleton& GetInstance();
private:
	UplayConfigSingleton() = default;
	~UplayConfigSingleton() = default;
	UplayConfigSingleton(const UplayConfigSingleton&) = delete;
	UplayConfigSingleton& operator=(const UplayConfigSingleton&) = delete;
};

inline UplayConfigSingleton& UplayConfigSingleton::GetInstance()
{
	static UplayConfigSingleton instance;
	return instance;
}