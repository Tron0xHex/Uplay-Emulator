#pragma once

struct UplayKey
{
	const char* cdKey;
	explicit UplayKey(const char*);
};

//------------------------------------------------------------------------------
inline UplayKey::UplayKey(const char* key)
{
	cdKey = key;
}
