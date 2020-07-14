#pragma once

namespace UplayR1Loader::UplayTypes
{
#ifdef UPLAY_API_2014_NEXT_GEN
	struct UplaySave
	{
		int slotId;
		int pad;
		const char* name;
		UplaySave(int slotId, const char* name);
	};

	//------------------------------------------------------------------------------
	inline UplaySave::UplaySave(const int slotId, const char* name) : slotId(slotId), pad(0), name(name)
	{
	}
#else
	struct UplaySave
	{
		int slotId;
		const char* name;
		UplaySave(int slotId, const char* name);
	};

	//------------------------------------------------------------------------------
	inline UplaySave::UplaySave(const int slotId, const char* name) : slotId(slotId), name(name)
	{
	}
#endif
}
