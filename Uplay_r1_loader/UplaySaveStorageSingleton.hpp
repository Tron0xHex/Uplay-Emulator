#pragma once

#include "stdafx.h"
#include "UplaySaveStorageInternal.hpp"

namespace UplayR1Loader
{
	struct UplaySaveStorageSingleton
	{
		UplaySaveStorageInternal storage;
		static UplaySaveStorageSingleton& GetInstance();
	private:
		UplaySaveStorageSingleton() = default;
		~UplaySaveStorageSingleton() = default;
		UplaySaveStorageSingleton(const UplaySaveStorageSingleton&) = delete;
		UplaySaveStorageSingleton& operator=(const UplaySaveStorageSingleton&) = delete;
	};

	//------------------------------------------------------------------------------
	inline UplaySaveStorageSingleton& UplaySaveStorageSingleton::GetInstance()
	{
		static UplaySaveStorageSingleton instance;
		return instance;
	}
}
