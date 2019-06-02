#pragma once

struct UplaySave
{
	int slotId;
	const char *name;
	UplaySave(int slotId, const char *name);
};

inline UplaySave::UplaySave(const int slotId, const char *name) : slotId(slotId), name(name)
{
}