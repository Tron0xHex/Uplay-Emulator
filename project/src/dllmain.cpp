#include "pch.h"
#include "Macro.hpp"
// ReSharper disable CppUnusedIncludeDirective
#include "Loader.hpp"
// ReSharper restore CppUnusedIncludeDirective

UPLAY_API inline void UPLAY_FUNC SpaceCat()
{
	// NO_BODY
}

// ReSharper disable CppParameterMayBeConst

BOOL APIENTRY DllMain(HMODULE hModule,
					  DWORD ulReasonForCall,
					  LPVOID lpReserved)
{
	switch (ulReasonForCall)
	{
	case DLL_PROCESS_ATTACH:
	{
		UplayR1Loader::InitConfig();
		UplayR1Loader::InitLog();
		UplayR1Loader::InitHooks();
#ifdef ENVIRONMENT_X32
		UplayR1Loader::InitPatches();
#endif // ENVIRONMENT_X32
		break;
	}
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	default:;
	}
	return TRUE;
}
// ReSharper restore CppParameterMayBeConst
