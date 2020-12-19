#pragma once

#include "Macro.hpp"

namespace UplayR1Loader
{
	static constexpr auto CONFIG_NAME = "Uplay.json";
	static constexpr auto SAVE_FILE_EXTENSION = ".save";
	static constexpr auto SAVE_NAME_EXTENSION = ".name";
	static constexpr auto DEFAULT_SAVE_DATA_OFFSET = 520U;

#ifdef ENVIRONMENT_X64
	static constexpr auto UPLAY_R1_ORIGINAL_DLL_NAME = L"uplay_r1_loader64.dll";
#else
	static constexpr auto UPLAY_R1_ORIGINAL_DLL_NAME = L"uplay_r1_loader.dll";
#endif
}; // namespace UplayR1Loader
