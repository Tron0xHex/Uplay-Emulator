// dllmain.cpp: определяет точку входа для приложения DLL.
#include "stdafx.h"

#include <plog/Init.h>
#include <plog/Log.h>

#include "Consts.hpp"
#include "Hooks.hpp"
#include "Memory/AobScan.hpp"
#include "Patches.hpp"
#include "UplayConfigSingleton.hpp"
#include "UplaySaveInternal.hpp"

using namespace UplayR1Loader;

UPLAY_API inline void UPLAY_FUNC SpaceCat()
{
	// NO_BODY
}

BOOL APIENTRY DllMain(HMODULE hModule,
                      // ReSharper disable CppParameterMayBeConst
                      int ulReasonForCall,
                      // ReSharper restore CppParameterMayBeConst
                      LPVOID lpReserved)
{
	switch (ulReasonForCall)
	{
	case DLL_PROCESS_ATTACH:
		{
			try
			{
				const auto currentPath = filesystem::current_path();
				const auto configPath = currentPath / path(Consts::ConfigName);

				if (!exists(configPath))
				{
					throw exception("Configuration file not found!");
				}

				UplayConfigSingleton::GetInstance().configHolder.Open(configPath);

				if (UplayConfigSingleton::GetInstance().configHolder.config.uplay.log)
				{
					if (filesystem::exists(Consts::LogName))
					{
						filesystem::remove(Consts::LogName);
					}

					init(plog::debug, Consts::LogName);
				}

				if (UplayConfigSingleton::GetInstance().configHolder.config.uplay.hooks)
				{
					char buff[512]{NULL};

					if (GetModuleFileNameA(nullptr, buff, 512))
					{
						const auto dllPath = path(buff);
						const auto hookModule = dllPath.filename().wstring() + dllPath.extension().wstring();

						if (hookModule == Consts::UplayR1OriginalDllName)
						{
							throw std::exception("Can't hook functions in self module!");
						}
					}
				}

				if (UplayConfigSingleton::GetInstance().configHolder.config.uplay.hooks)
				{
					Hooks::InstallHooks();
				}

#ifndef ENVIRONMENT_X64
				if (Memory::AobScan::GetModuleEntry(Consts::FarCry3DllName).has_value())
				{
					Patches::PatchFc3Dll();
				}
#endif
			}
			catch (exception& ex)
			{
				LOGD << ex.what();
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
