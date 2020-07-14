#pragma once

#include "stdafx.h"

namespace UplayR1Loader::Consts
{
	static constexpr auto LogName = "Log.log";
	static constexpr auto ConfigName = "Uplay.json";
	static constexpr auto SavesMetaDataStorageName = "MetaData.json";
	static constexpr auto SaveFileExtension = ".save";
	static constexpr auto DefaultSaveDataOffset = 520U;

#ifdef ENVIRONMENT_X64
	static constexpr auto UplayR1OriginalDllName = L"uplay_r1_loader64.dll";
#else
	static constexpr auto UplayR1OriginalDllName = L"uplay_r1_loader.dll";
	static constexpr auto FarCry3DllName = "FC3.dll";
	static constexpr auto FarCry3DllPatchSig = "C7 46 40 01 00 00 00 8B 0D ?? ?? ?? ?? E8 ?? ?? ?? ??";
	static constexpr auto FarCry3DllInjectSig = "C7 46 40 05 00 00 00 90 90 90 90 90 90 90 90 90 90 90";
#endif
};
