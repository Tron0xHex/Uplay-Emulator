#pragma once

#include <plog/Log.h>

#include "Consts.hpp"
#include "Memory/AobScan.hpp"
#include "Memory/Inject.hpp"

namespace UplayR1Loader::Patches
{
#ifndef ENVIRONMENT_X64
	inline void PatchFc3Dll()
	{
		/*
		 * 78C75186 | C746 40 01000000          | mov int ptr ds:[esi+40],1                                                             |
		 * 78C7518D | 8B0D 4C8A267A             | mov ecx,int ptr ds:[7A268A4C]                                                         | ecx:EntryPoint
		 * 78C75193 | E8 F524F5FF               | call fc3.78BC768D                                                                     |
		 */

		const auto addresses = Memory::AobScan::FindPatternInModule(Consts::FarCry3DllName, Consts::FarCry3DllPatchSig);

		LOGD << "Found FC3.dll sig addresses: " << addresses.size();

		/*
		 * 78C75186 | C746 40 05000000          | mov int ptr ds:[esi+40],5                                                               |
		 * 78C7518D | 90                        | nop                                                                                     |
		 * 78C7518E | 90                        | nop                                                                                     |
		 * 78C7518F | 90                        | nop                                                                                     |
		 * 78C75190 | 90                        | nop                                                                                     |
		 * 78C75191 | 90                        | nop                                                                                     |
		 * 78C75192 | 90                        | nop                                                                                     |
		 * 78C75193 | 90                        | nop                                                                                     |
		 * 78C75194 | 90                        | nop                                                                                     |
		 * 78C75195 | 90                        | nop                                                                                     |
		 * 78C75196 | 90                        | nop                                                                                     |
		 * 78C75197 | 90                        | nop                                                                                     |
		 */

		if (addresses.size() > 0)
		{
			LOGD << "FC3.dll sig address: " << "0x" << hex << addresses.front();

			const auto injectAddress = addresses.front();
			const auto injectBytes = Memory::Utils::HexToBin(Consts::FarCry3DllInjectSig);

			Memory::Inject::WriteMem(injectAddress, injectBytes);
		}
	}
#endif
}
