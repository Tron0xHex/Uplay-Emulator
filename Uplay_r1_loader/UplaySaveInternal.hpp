#pragma once

#include "stdafx.h"
#include "Consts.hpp"
#include "JsonObjects/Generators.hpp"
#include "JsonObjects/UplaySaveMetaDataStorage.hpp"

namespace UplayR1Loader
{
	struct UplaySaveInternal
	{
	private:
		fstream fs;
	public:
		string initialName;
		path filePath;

		UplaySaveInternal() noexcept;
		UplaySaveInternal(const path& pt) noexcept;
		UplaySaveInternal(const path& pt, const string& name) noexcept;

		DWORD Open();
		DWORD Open(int mode);
		DWORD Write(DWORD numOfBytesToWrite, const char* buffer);
		DWORD Read(DWORD numOfBytesToRead, int offset, char* outBuffer, LPDWORD outNumOfBytesRead);
		DWORD SetName(int slotId, const char* nameUtf8) const;
		DWORD Remove(int slotId);
		DWORD Close();

		static tuple<int, shared_ptr<UplaySaveInternal>> FromFile(const path& savePath);
		static optional<JsonObjects::UplaySaveMetaDataStorage> ReadMetaDataStorage(const path& savesPath);
		static bool UpdateMetaDataStorage(const path& storagePath, const JsonObjects::UplaySaveMetaDataStorage& storage);
		static bool CreateMetaDataStorage(const path& storagePath);

		static bool IsMetaDataStorageExists(const path& storagePath);
		static path GetMetaDataStoragePath(const path& storagePath);
	};

	//------------------------------------------------------------------------------
	inline UplaySaveInternal::UplaySaveInternal() noexcept : initialName(""), filePath("")
	{
	}

	//------------------------------------------------------------------------------
	inline UplaySaveInternal::UplaySaveInternal(const path& path) noexcept : filePath(path)
	{
	}

	//------------------------------------------------------------------------------
	inline UplaySaveInternal::UplaySaveInternal(const path& filePath, const string& name) noexcept : initialName(name), filePath(filePath)
	{
	}

	//------------------------------------------------------------------------------
	inline DWORD UplaySaveInternal::Open(const int mode)
	{
		if (fs.is_open())
		{
			fs.close();
		}

		fs.open(filePath.string(), mode);

		return static_cast<DWORD>(fs.is_open());
	}

	//------------------------------------------------------------------------------
	inline DWORD UplaySaveInternal::Open()
	{
		if (fs.is_open())
		{
			fs.close();
		}

		fs.open(filePath.string(), ios::in | ios::out | ios::binary);

		return static_cast<DWORD>(fs.is_open());
	}

	//------------------------------------------------------------------------------
	inline DWORD UplaySaveInternal::Write(const DWORD numOfBytesToWrite, const char* buffer)
	{
		auto result = 0L;

		if (fs)
		{
			fs.seekg(Consts::DefaultOffset, ios::beg);
			fs.write(buffer, numOfBytesToWrite);

			if (fs) {
				result = 1L;
			}
		}

		return result;
	}

	//------------------------------------------------------------------------------
	inline DWORD UplaySaveInternal::Read(const DWORD numOfBytesToRead, const int offset, char* outBuffer, const LPDWORD outNumOfBytesRead)
	{
		auto result = 0L;

		if (fs)
		{
			fs.seekg(Consts::DefaultOffset + static_cast<streampos>(offset));
			fs.read(outBuffer, numOfBytesToRead);
			*outNumOfBytesRead = static_cast<DWORD>(fs.gcount());
			result = 1L;
		}

		return result;
	}

	//------------------------------------------------------------------------------
	inline DWORD UplaySaveInternal::SetName(const int slotId, const char* nameUtf8) const
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

			return static_cast<DWORD>(UpdateMetaDataStorage(storageDir, storage));
		}

		return 0L;
	}

	//------------------------------------------------------------------------------
	inline DWORD UplaySaveInternal::Remove(const int slotId)
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

		return static_cast<DWORD>(filesystem::remove(filePath));
	}

	//------------------------------------------------------------------------------
	inline DWORD UplaySaveInternal::Close()
	{
		if (!fs.is_open())
		{
			return 0L;
		}

		fs.close();
		return 1L;
	}

	//------------------------------------------------------------------------------
	inline tuple<int, std::shared_ptr<UplaySaveInternal>> UplaySaveInternal::FromFile(const path & savePath)
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
				return make_tuple(slotId, make_shared<UplaySaveInternal>(savePath, storage.saves.at(slotIdString)));
			}
		}

		return make_tuple(slotId, make_shared<UplaySaveInternal>(savePath));
	}

	//------------------------------------------------------------------------------
	inline optional<JsonObjects::UplaySaveMetaDataStorage> UplaySaveInternal::ReadMetaDataStorage(
		const path & storagePath)
	{
		const auto filePath = GetMetaDataStoragePath(storagePath);
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
	inline bool UplaySaveInternal::UpdateMetaDataStorage(const path & storagePath,
		const JsonObjects::UplaySaveMetaDataStorage & storage)
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
	inline bool UplaySaveInternal::CreateMetaDataStorage(const path & storagePath)
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
	inline bool UplaySaveInternal::IsMetaDataStorageExists(const path & storagePath)
	{
		return exists(GetMetaDataStoragePath(storagePath));
	}

	//------------------------------------------------------------------------------
	inline path UplaySaveInternal::GetMetaDataStoragePath(const path & storagePath)
	{
		return storagePath / path(Consts::SavesMetaDataStorageName);
	}
}
