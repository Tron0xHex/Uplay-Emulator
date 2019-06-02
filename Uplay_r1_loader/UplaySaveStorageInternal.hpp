#pragma once

#include "stdafx.h"
#include "UplaySaveInternal.hpp"

struct UplaySaveStorageInternal
{
private:
	map<int, shared_ptr<UplaySaveInternal>> saves{};
public:
	bool IsSaveExists(int id) const;
	shared_ptr<UplaySaveInternal> GetSave(int id) const;
	map<int, shared_ptr<UplaySaveInternal>> GetSaves() const;
	void AppendSave(int id, shared_ptr<UplaySaveInternal> save);
	void RemoveSave(int id);
	void RemoveAll();
};

inline bool UplaySaveStorageInternal::IsSaveExists(const int id) const
{
	return saves.find(id) != saves.end();
}

inline shared_ptr<UplaySaveInternal> UplaySaveStorageInternal::GetSave(const int id) const
{
	return saves.at(id);
}

inline map<int, shared_ptr<UplaySaveInternal>> UplaySaveStorageInternal::GetSaves() const
{
	return saves;
}

inline void UplaySaveStorageInternal::AppendSave(int id, shared_ptr<UplaySaveInternal> save)
{
	saves.emplace(id, save);
}

inline void UplaySaveStorageInternal::RemoveSave(const int id)
{
	saves.erase(id);
}

inline void UplaySaveStorageInternal::RemoveAll()
{
	for (auto &[slotId, uplaySave] : saves) {
		uplaySave->Close();
	}

	saves.clear();
}