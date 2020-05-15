#pragma once

namespace UplayR1Loader::UplayTypes
{

#ifdef UPLAY_API_2014_NEXT_GEN
	struct UplaySave
	{
		DWORD slotId;
		DWORD pad;
		const char* name;
		UplaySave(DWORD slotId, const char* name);
	};

	//------------------------------------------------------------------------------
	inline UplaySave::UplaySave(const DWORD slotId, const char* name) : slotId(slotId), pad(0),
	                                                                                      name(name)
	{
	}
#else
	struct UplaySave
	{
		DWORD slotId;
		const char* name;
		UplaySave(DWORD slotId, const char* name);
	};

	//------------------------------------------------------------------------------
	inline UplaySave::UplaySave(const DWORD slotId, const char* name) : slotId(slotId), name(name)
	{
	}
#endif
}