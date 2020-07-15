#pragma once

#include "stdafx.h"
#include "EUplayConfigHolder.hpp"

namespace UplayR1Loader
{
	struct EUplayConfigSingleton
	{
		EUplayConfigHolder configHolder;
		static EUplayConfigSingleton& GetInstance();
	private:
		EUplayConfigSingleton() = default;
		~EUplayConfigSingleton() = default;
		EUplayConfigSingleton(const EUplayConfigSingleton&) = delete;
		EUplayConfigSingleton& operator=(const EUplayConfigSingleton&) = delete;
	};

	//------------------------------------------------------------------------------
	inline EUplayConfigSingleton& EUplayConfigSingleton::GetInstance()
	{
		static EUplayConfigSingleton instance;
		return instance;
	}
}
