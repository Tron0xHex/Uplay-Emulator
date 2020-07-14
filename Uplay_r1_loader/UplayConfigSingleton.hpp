#pragma once

#include "stdafx.h"

#include "UplayConfigHolder.hpp"

namespace UplayR1Loader
{
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

	//------------------------------------------------------------------------------
	inline UplayConfigSingleton& UplayConfigSingleton::GetInstance()
	{
		static UplayConfigSingleton instance;
		return instance;
	}
}
