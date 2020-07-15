#pragma once

#include "stdafx.h"
#include "Consts.hpp"
#include "JsonObjects/Generators.hpp"
#include "JsonObjects/UplaySaveMetaDataStorage.hpp"

namespace UplayR1Loader
{
	struct EUplaySave
	{
	private:
		fstream fs;
	public:
		string initialName;
		path filePath;

		EUplaySave() noexcept;
		explicit EUplaySave(const path& path) noexcept;
		EUplaySave(const path& filePath, const string& name) noexcept;

		int Open();
		int Open(int mode);
		int Write(int numOfBytesToWrite, const char* buffer);
		int Read(int numOfBytesToRead, int offset, char* outBuffer, unsigned int* outNumOfBytesRead);
		int SetName(int slotId, const char* nameUtf8) const;
		int Remove(int slotId);
		int GetSize() const;
		int Close();

		static tuple<int, shared_ptr<EUplaySave>> FromFile(const path& savePath);
		static optional<JsonObjects::UplaySaveMetaDataStorage> ReadMetaDataStorage(const path& savesPath);
		static bool UpdateMetaDataStorage(const path& storagePath,
		                                  const JsonObjects::UplaySaveMetaDataStorage& storage);
		static bool CreateMetaDataStorage(const path& storagePath);

		static bool IsMetaDataStorageExists(const path& storagePath);
		static path GetMetaDataStoragePath(const path& storagePath);
	};

	//------------------------------------------------------------------------------
	inline EUplaySave::EUplaySave() noexcept : initialName(""), filePath("")
	{
	}

	//------------------------------------------------------------------------------
	inline EUplaySave::EUplaySave(const path& path) noexcept : filePath(path)
	{
	}

	//------------------------------------------------------------------------------
	inline EUplaySave::
	EUplaySave(const path& filePath, const string& name) noexcept : initialName(name), filePath(filePath)
	{
	}

	//------------------------------------------------------------------------------
	inline int EUplaySave::Open(const int mode)
	{
		if (fs.is_open())
		{
			fs.close();
		}

		fs.open(filePath.string(), mode);

		return static_cast<int>(fs.is_open());
	}

	//------------------------------------------------------------------------------
	inline int EUplaySave::Open()
	{
		if (fs.is_open())
		{
			fs.close();
		}

		fs.open(filePath.string(), ios::in | ios::out | ios::binary);

		return static_cast<int>(fs.is_open());
	}

	//------------------------------------------------------------------------------
	inline int EUplaySave::Write(const int numOfBytesToWrite, const char* buffer)
	{
		auto result = 0L;

		if (fs)
		{
			fs.seekg(Consts::DefaultSaveDataOffset, ios::beg);
			fs.write(buffer, numOfBytesToWrite);

			if (fs)
			{
				result = 1L;
			}
		}

		return result;
	}

	//------------------------------------------------------------------------------
	inline int EUplaySave::Read(const int numOfBytesToRead, const int offset, char* outBuffer,
	                                   unsigned int* outNumOfBytesRead)
	{
		auto result = 0L;

		if (fs)
		{
			fs.seekg(Consts::DefaultSaveDataOffset + static_cast<streampos>(offset));
			fs.read(outBuffer, numOfBytesToRead);

			*outNumOfBytesRead = static_cast<unsigned int>(fs.gcount());

			result = 1L;
		}

		return result;
	}

	//------------------------------------------------------------------------------
	inline int EUplaySave::SetName(const int slotId, const char* nameUtf8) const
	{
		const auto storageDir = filePath.parent_path();
		const auto slotIdStr = to_string(slotId);
		const auto storageOpt = ReadMetaDataStorage(storageDir);
		const auto name = string(nameUtf8);

		if (storageOpt.has_value())
		{
			auto storage = storageOpt.value();

			if (storage.saves.find(slotIdStr) != storage.saves.end())
			{
				storage.saves.at(slotIdStr) = name;
			}
			else
			{
				storage.saves.emplace(slotIdStr, name);
			}

			return static_cast<int>(UpdateMetaDataStorage(storageDir, storage));
		}

		return 0;
	}

	//------------------------------------------------------------------------------
	inline int EUplaySave::Remove(const int slotId)
	{
		if (fs.is_open())
		{
			fs.close();
		}

		const auto storageDir = filePath.parent_path();
		const auto storageOpt = ReadMetaDataStorage(storageDir);
		const auto slotIdString = to_string(slotId);

		if (storageOpt.has_value())
		{
			auto storage = storageOpt.value();

			if (storage.saves.find(slotIdString) != storage.saves.end())
			{
				storage.saves.erase(slotIdString);
			}

			UpdateMetaDataStorage(storageDir, storage);
		}

		return static_cast<int>(filesystem::remove(filePath));
	}

	//------------------------------------------------------------------------------
	inline int EUplaySave::GetSize() const
	{
		if (!fs.is_open())
		{
			return 0;
		}

		return static_cast<int>(file_size(filePath));
	}

	//------------------------------------------------------------------------------
	inline int EUplaySave::Close()
	{
		if (!fs.is_open())
		{
			return 0;
		}

		fs.close();
		return 1;
	}

	//------------------------------------------------------------------------------
	inline tuple<int, std::shared_ptr<EUplaySave>> EUplaySave::FromFile(const path& savePath)
	{
		const auto storageDir = savePath.parent_path();
		const auto slotIdString = savePath.stem().string();
		const auto slotId = stoi(slotIdString);
		const auto storageOpt = ReadMetaDataStorage(storageDir);

		if (storageOpt.has_value())
		{
			const auto storage = storageOpt.value();

			if (storage.saves.find(slotIdString) != storage.saves.end())
			{
				return make_tuple(slotId, make_shared<EUplaySave>(savePath, storage.saves.at(slotIdString)));
			}
		}

		return make_tuple(slotId, make_shared<EUplaySave>(savePath));
	}

	//------------------------------------------------------------------------------
	inline optional<JsonObjects::UplaySaveMetaDataStorage> EUplaySave::ReadMetaDataStorage(
		const path& savesPath)
	{
		const auto filePath = GetMetaDataStoragePath(savesPath);
		const auto fs = fstream(filePath.string(), ios::in);

		if (fs)
		{
			JsonObjects::UplaySaveMetaDataStorage data = json::parse(
				static_cast<stringstream const&>(stringstream() << fs.rdbuf()).str());
			return data;
		}

		return {};
	}

	//------------------------------------------------------------------------------
	inline bool EUplaySave::UpdateMetaDataStorage(const path& storagePath,
	                                                     const JsonObjects::UplaySaveMetaDataStorage& storage)
	{
		const auto filePath = GetMetaDataStoragePath(storagePath);

		json json;
		to_json(json, storage);

		auto fs = fstream(filePath.string(), ios::out | ios::trunc);

		if (fs)
		{
			fs << json.dump(4) << endl;
			return true;
		}

		return false;
	}

	//------------------------------------------------------------------------------
	inline bool EUplaySave::CreateMetaDataStorage(const path& storagePath)
	{
		auto fs = fstream(GetMetaDataStoragePath(storagePath).string(), ios::out);

		if (fs)
		{
			fs << R"({"Saves": {}})"_json.dump(4) << endl;
			return true;
		}

		return false;
	}

	//------------------------------------------------------------------------------
	inline bool EUplaySave::IsMetaDataStorageExists(const path& storagePath)
	{
		return exists(GetMetaDataStoragePath(storagePath));
	}

	//------------------------------------------------------------------------------
	inline path EUplaySave::GetMetaDataStoragePath(const path& storagePath)
	{
		return storagePath / path(Consts::SavesMetaDataStorageName);
	}
}