#pragma once

#include "../stdafx.h"

#include "UplayKey.hpp"
#include "UplaySave.hpp"

struct UplayList
{
	DWORD count;

	union
	{
		void** items;
		UplayKey** keys;
		UplaySave** saves;
	};
};
