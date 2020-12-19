#pragma once

#include "src/pch.h"

#include "Failure.hpp"

namespace UplayR1Loader
{
	using namespace std;
	using namespace cereal;

	using std::filesystem::path;

	template <class T>
	void SerializeJsonToFile(const path &file, const T &data)
	{
		if (auto fs = fstream(file, ios::out); fs)
		{
			JSONOutputArchive ar(fs);
			ar(data);
			return;
		}

		Fail(fmt::format("File write error: {}", file.string()), true);
	}

	template <class T>
	void DeserializeFromJsonFile(const path &file, T &data)
	{
		if (auto fs = fstream(file, ios::in); fs)
		{
			JSONInputArchive ar(fs);
			ar(data);
			return;
		}

		Fail(fmt::format("File read error: {}", file.string()), true);
	}
} // namespace UbiorbitapiR2Loader
