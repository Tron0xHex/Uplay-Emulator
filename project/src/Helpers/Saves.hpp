#pragma once

#include "src/pch.h"

#include "src/Consts.hpp"
#include "src/Utils/Singleton.hpp"

namespace UplayR1Loader
{
	using namespace std;
	using std::filesystem::path;

	namespace fs = std::filesystem;

	inline path GetSavesPath()
	{
		return path(Singleton<UplayConfig>::Instance().Get().Uplay.Saves);
	}

	inline path GetSavePath(const unsigned int saveId)
	{
		path savePath;

		savePath /= GetSavesPath();
		savePath /= fmt::format("{}{}", saveId, SAVE_FILE_EXTENSION);

		return savePath;
	}

	inline path GetSaveNamePath(const path& savesPath, const unsigned int saveId)
	{
		path namePath;

		namePath /= savesPath;
		namePath /= fmt::format("{}{}", saveId, SAVE_NAME_EXTENSION);

		return namePath;
	}

	inline path GetSaveNamePath(const unsigned int saveId)
	{
		const auto savesPath = GetSavesPath();
		const auto namePath = GetSaveNamePath(savesPath, saveId);

		return namePath;
	}

	inline string ReadSaveName(const path& file)
	{
		const auto fs = fstream(file, ios::in);

		stringstream buffer;
		buffer << fs.rdbuf();

		return buffer.str();
	}

	inline void WriteSaveName(const path& file, const string& content)
	{
		auto fs = fstream(file, ios::out | ios::trunc);
		fs.write(content.data(), content.size());
	}

	inline unsigned int ReadSave(const path& file, const unsigned int offset, char* buff,
	                             const unsigned int numberOfBytes)
	{
		auto fs = fstream(file, ios::in | ios::binary);

		fs.seekg(offset, ios::beg);
		fs.read(buff, numberOfBytes);

		const auto bytesCount = static_cast<unsigned int>(fs.gcount());
		return bytesCount;
	}

	inline unsigned int WriteSave(const path& file, const ios::openmode openOptions, const char* buff, const unsigned int numberOfBytes)
	{
		auto fs = fstream(file, openOptions);

		fs.seekp(0, ios::beg);
		const auto currentPosition = fs.tellp();
		fs.write(buff, numberOfBytes);

		const auto bytesCount = static_cast<unsigned int>(fs.tellp() - currentPosition);
		return bytesCount;
	}

	inline vector<tuple<unsigned int, string>> GetSavegames()
	{
		vector<tuple<unsigned int, string>> saves{};
		
		const auto savesPath = GetSavesPath();
		
		for (const auto& dirEntry : fs::directory_iterator(savesPath))
		{
			const auto& path = dirEntry.path();

			if (path.has_extension() && path.extension() == SAVE_FILE_EXTENSION)
			{
				const auto id = ST::string(path.stem().string()).to_uint();
				const auto namePath = GetSaveNamePath(id);

				if (fs::exists(namePath))
				{
					const auto name = ST::string(ReadSaveName(namePath)).trim().to_std_string();
					const auto save = make_tuple(id, name);

					saves.push_back(save);
				}
			}
		}

		return saves;
	}
} // namespace UbiorbitapiR2Loader
