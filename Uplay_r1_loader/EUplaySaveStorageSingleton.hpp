#pragma once

#include "stdafx.h"
#include "EUplaySaveStorage.hpp"

namespace UplayR1Loader
{
	struct EUplaySaveStorageSingleton
	{
		EUplaySaveStorage storage;
		static EUplaySaveStorageSingleton& GetInstance();
	private:
		EUplaySaveStorageSingleton() = default;
		~EUplaySaveStorageSingleton() = default;
		EUplaySaveStorageSingleton(const EUplaySaveStorageSingleton&) = delete;
		EUplaySaveStorageSingleton& operator=(const EUplaySaveStorageSingleton&) = delete;
	};

	//------------------------------------------------------------------------------
	inline EUplaySaveStorageSingleton& EUplaySaveStorageSingleton::GetInstance()
	{
		static EUplaySaveStorageSingleton instance;
		return instance;
	}
}
