#pragma once

#include "stdafx.h"
#include "EUplaySave.hpp"

namespace UplayR1Loader
{
	struct EUplaySaveStorage
	{
	private:
		map<int, shared_ptr<EUplaySave>> saves{};
	public:
		bool IsSaveExists(int id) const;
		shared_ptr<EUplaySave> GetSave(int id) const;
		map<int, shared_ptr<EUplaySave>> GetSaves() const;
		void AppendSave(int id, shared_ptr<EUplaySave> save);
		void RemoveSave(int id);
		void RemoveAll();
	};

	//------------------------------------------------------------------------------
	inline bool EUplaySaveStorage::IsSaveExists(const int id) const
	{
		return saves.find(id) != saves.end();
	}

	//------------------------------------------------------------------------------
	inline shared_ptr<EUplaySave> EUplaySaveStorage::GetSave(const int id) const
	{
		return saves.at(id);
	}

	//------------------------------------------------------------------------------
	inline map<int, shared_ptr<EUplaySave>> EUplaySaveStorage::GetSaves() const
	{
		return saves;
	}

	//------------------------------------------------------------------------------
	inline void EUplaySaveStorage::AppendSave(int id, shared_ptr<EUplaySave> save)
	{
		saves.emplace(id, save);
	}

	//------------------------------------------------------------------------------
	inline void EUplaySaveStorage::RemoveSave(const int id)
	{
		saves.erase(id);
	}

	//------------------------------------------------------------------------------
	inline void EUplaySaveStorage::RemoveAll()
	{
		for (auto& [slotId, uplaySave] : saves)
		{
			uplaySave->Close();
		}

		saves.clear();
	}
}
