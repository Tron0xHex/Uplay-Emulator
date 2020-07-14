#pragma once

#include <minwindef.h>
#include <vector>

namespace UplayR1Loader::Memory
{
	using namespace std;

	class Inject
	{
	public:
		static void WriteMem(const int address, const vector<char>& bytes)
		{
			DWORD oldProtect;

			VirtualProtect(reinterpret_cast<void*>(address), bytes.size(), PAGE_EXECUTE_READWRITE, &oldProtect);
			memcpy_s(reinterpret_cast<void*>(address), bytes.size() + 1, bytes.data(), bytes.size());
			VirtualProtect(reinterpret_cast<void*>(address), bytes.size(), oldProtect, &oldProtect);
		}
	};
}
