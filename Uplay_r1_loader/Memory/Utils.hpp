#pragma once

#include <vector>
#include <string>
#include <sstream>

namespace UplayR1Loader::Memory
{
	using namespace std;

	class Utils
	{
	public:
		static vector<string> Split(const string& str, const char delimiter)
		{
			auto token = string{};
			auto tokens = vector<string>{};
			auto ss = stringstream(str);

			while (getline(ss, token, delimiter))
			{
				tokens.push_back(token);
			}

			return tokens;
		}

		static int CharToInt(const char input)
		{
			if (input >= '0' && input <= '9')
				return input - '0';
			if (input >= 'A' && input <= 'F')
				return input - 'A' + 10;
			if (input >= 'a' && input <= 'f')
				return input - 'a' + 10;

			return -1;
		}

		static vector<char> HexToBin(const string& src)
		{
			auto result = vector<char>{};

			for (const auto& token : Split(src, ' '))
			{
				if (token == "??")
				{
					result.push_back('\0');
				}
				else
				{
					result.push_back(static_cast<char>(stoul(token, nullptr, 16)));
				}
			}

			return result;
		}
	};
}
