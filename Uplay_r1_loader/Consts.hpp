#pragma once

#include "stdafx.h"

namespace UplayR1Loader::Consts
{
	static constexpr auto LogName = "Log.txt";
	static constexpr auto ConfigName = "Uplay.json";
	static constexpr auto SavesMetaDataStorageName = "MetaData.json";
	static constexpr auto SaveFileExtension = ".save";

#ifdef UPLAY_API_2014_NEXT_GEN
	static constexpr auto DefaultSaveDataOffset = 520U;
#else
	static constexpr auto DefaultSaveDataOffset = 520U;
#endif

#ifdef ENVIRONMENT_X64
	static constexpr auto UplayR1OriginalDllName = L"uplay_r1_loader64.dll";
#else
	static constexpr auto UplayR1OriginalDllName = L"uplay_r1_loader.dll";
#endif
};
