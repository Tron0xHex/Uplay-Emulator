#pragma once

namespace UplayR1Loader
{
	class UplayKey
	{
	public:
		const char* CdKey;
		explicit UplayKey(const char*);
	};

	//------------------------------------------------------------------------------
	inline UplayKey::UplayKey(const char* key)
	{
		CdKey = key;
	}
} // namespace UplayR1Loader
