// dllmain.cpp: определяет точку входа для приложения DLL.
#include "stdafx.h"

#include <plog/Init.h>
#include <minhook/include/MinHook.h>

#include "Consts.hpp"
#include <plog/Log.h>
#include "UplayConfigSingleton.hpp"
#include "UplaySaveInternal.hpp"
#include "UplaySaveStorageSingleton.hpp"
#include "Hooks.hpp"

UPLAY_API inline void UPLAY_FUNC SpaceCat()
{
	// NO_BODY
}

BOOL APIENTRY DllMain(HMODULE hModule,
                      DWORD ul_reason_for_call,
                      LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		{
#ifdef _DEBUG
			if (std::filesystem::exists(UplayR1Loader::Consts::LogName))
			{
				std::filesystem::remove(UplayR1Loader::Consts::LogName);
			}

			init(plog::debug, UplayR1Loader::Consts::LogName);
#endif
			try
			{
				const auto currentPt = filesystem::current_path();
				const auto configPt = currentPt / path(UplayR1Loader::Consts::ConfigName);

				if (!exists(configPt))
				{
					throw std::exception("Configuration file not found!");
				}

				UplayR1Loader::UplayConfigSingleton::GetInstance().configHolder.Open(configPt);

				if (UplayR1Loader::UplayConfigSingleton::GetInstance().configHolder.config.uplay.hooks)
				{
					char buff[512]{NULL};

					if (GetModuleFileNameA(nullptr, buff, 512))
					{
						const auto dllPath = path(buff);

						if (dllPath.filename().wstring() + dllPath.extension().wstring() == UplayR1Loader::Consts::
							UplayR1OriginalDllName)
						{
							throw std::exception("Can't hook functions in self module!");
						}
					}
				}

				if (UplayR1Loader::UplayConfigSingleton::GetInstance().configHolder.config.uplay.hooks)
				{
					UplayR1Loader::Hooks::InstallHooks();
				}

				const auto savesPt = path(
					UplayR1Loader::UplayConfigSingleton::GetInstance().configHolder.config.uplay.saves);

				if (!exists(savesPt) && !create_directories(savesPt))
				{
					throw std::exception("Unable to create directories!");
				}

				if (!UplayR1Loader::UplaySaveInternal::IsMetaDataStorageExists(savesPt))
				{
					if (!UplayR1Loader::UplaySaveInternal::CreateMetaDataStorage(savesPt))
					{
						throw std::exception("Unable to create meta data storage!");
					}
				}

				if (!filesystem::is_empty(savesPt))
				{
					for (const auto& dirEntry : directory_iterator(savesPt))
					{
						const auto pt = dirEntry.path();

						if (pt.has_extension() && pt.extension().string() == UplayR1Loader::Consts::SaveFileExtension)
						{
							auto [slotId, uplaySave] = UplayR1Loader::UplaySaveInternal::FromFile(pt);

							UplayR1Loader::UplaySaveStorageSingleton::GetInstance().storage.AppendSave(
								slotId, uplaySave);
						}
					}
				}
			}
			catch (exception& ex)
			{
				LOGD_IF(UPLAY_LOG) << ex.what();
			}
			break;
		}
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
