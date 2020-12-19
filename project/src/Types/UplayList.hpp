#pragma once

#include "UplayKey.hpp"
#include "UplaySave.hpp"

namespace UplayR1Loader
{
	class UplayList
	{
	public:
		int Count;

		union
		{
			void** Items;
			UplayKey** Keys;
			UplaySave** Saves;
		};
	};
} // namespace UplayR1Loader
