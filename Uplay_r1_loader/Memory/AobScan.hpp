#pragma once

#include <cassert>
#include <exception>
#include <optional>
#include <Psapi.h>
#include <string>
#include <vector>
#include <Windows.h>
#include "Utils.hpp"

namespace UplayR1Loader::Memory
{
	using namespace std;

	class AobScan
	{
	public:
		struct ModuleEntry
		{
			const DWORD size;
			const int baseAddress;
		};

		static optional<ModuleEntry> GetModuleEntry(const string& moduleName)
		{
			assert(!moduleName.empty());

			auto moduleInfo = MODULEINFO{nullptr};

			const auto hModule = GetModuleHandleA(moduleName.c_str());

			if (hModule == nullptr)
			{
				return {};
			}

			if (GetModuleInformation(GetCurrentProcess(), hModule, &moduleInfo, sizeof(MODULEINFO)))
			{
				const auto size = moduleInfo.SizeOfImage;
				const auto baseAddress = reinterpret_cast<int>(moduleInfo.lpBaseOfDll);

				return ModuleEntry{size, baseAddress};
			}

			return {};
		}

		static string GetMaskFromPattern(const string& bytes)
		{
			assert(!bytes.empty());

			auto result = string{};

			for (const auto& token : Utils::Split(bytes, ' '))
			{
				if (token == "??")
				{
					result += "?";
				}
				else
				{
					result += "x";
				}
			}

			return result;
		}

		static vector<int> FindPattern(const int baseAddress, const int scanSize, const string& bytes,
		                                 const size_t offset)
		{
			assert(scanSize > 0 && !bytes.empty());

			auto result = vector<int>{};

			const auto bytesBin = Utils::HexToBin(bytes);
			const auto bytesMask = GetMaskFromPattern(bytes);

			static auto findPatternPredicate = [](const char* data, const vector<char>& bytesBin,
			                                      const string& bytesMask) -> auto
			{
				auto found = true;

				for (size_t j = 0; j < bytesBin.size(); ++j)
				{
					if (bytesMask[j] == '?')
					{
						continue;
					}

					if (data[j] != bytesBin[j])
					{
						found = false;
					}
				}

				return found;
			};

			for (size_t j = 0; j <= scanSize - bytesBin.size(); ++j)
			{
				const auto scanAddress = baseAddress + offset + j;
				const auto scanAddressPointer = reinterpret_cast<const char*>(scanAddress);
				const auto findPredicateResult = findPatternPredicate(scanAddressPointer, bytesBin, bytesMask);

				if (findPredicateResult)
				{
					result.push_back(scanAddress);
				}
			}

			return result;
		}

		static vector<int> FindPatternInModule(const string& moduleName, const string& bytes)
		{
			assert(!moduleName.empty() && !bytes.empty());

			const auto moduleEntry = GetModuleEntry(moduleName);

			if (!moduleEntry.has_value())
			{
				throw exception("Unable to find module entry!");
			}

			return FindPattern(moduleEntry.value().baseAddress, moduleEntry.value().size, bytes, 0);
		}
	};
}
