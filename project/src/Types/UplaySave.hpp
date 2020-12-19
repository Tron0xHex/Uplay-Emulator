#pragma once

#include "src/Macro.hpp"

namespace UplayR1Loader
{
	class UplaySave
	{
	public:
		int SlotId;
#ifdef UPLAY_API_2014_NEXT_GEN
		int Pad = 0;
#endif
		const char *Name;
		UplaySave(int slotId, const char *name);
	};

	//------------------------------------------------------------------------------
	inline UplaySave::UplaySave(const int slotId, const char *name) : SlotId(slotId), Name(name)
	{
	}
} // namespace UplayR1Loader
