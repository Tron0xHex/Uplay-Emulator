#pragma once

#include "src/pch.h"

namespace UplayR1Loader
{
	using namespace std;

	class OpenOptionsManager
	{
		map<int, ios::openmode> SavesOpenOptions;

	public:
		void SetOpenOptions(int id, ios::openmode options);
		void RemoveOpenOptions(int id);
		optional<ios::openmode> GetOpenOptions(int id);
	};

	//------------------------------------------------------------------------------
	inline void OpenOptionsManager::SetOpenOptions(const int id, ios::openmode options)
	{
		SavesOpenOptions.emplace(id, options);
	}

	//------------------------------------------------------------------------------
	inline void OpenOptionsManager::RemoveOpenOptions(const int id)
	{
		const auto saveOpenOptions = find_if(SavesOpenOptions.begin(), SavesOpenOptions.end(),
		                                     [&](const pair<int, ios::openmode>& val)
		                                     {
			                                     return val.first == id;
		                                     });

		if (saveOpenOptions != SavesOpenOptions.end())
		{
			SavesOpenOptions.erase(saveOpenOptions, SavesOpenOptions.end());
		}
	}

	//------------------------------------------------------------------------------
	inline optional<ios::openmode> OpenOptionsManager::GetOpenOptions(const int id)
	{
		const auto saveOpenOptions = find_if(SavesOpenOptions.begin(), SavesOpenOptions.end(),
		                                     [&](const pair<int, ios::openmode>& openOptions)
		                                     {
			                                     return openOptions.first == id;
		                                     });

		if (saveOpenOptions != SavesOpenOptions.end())
		{
			return make_optional<ios::openmode>(saveOpenOptions->second);
		}

		return {};
	}
} // namespace UplayR1Loader
