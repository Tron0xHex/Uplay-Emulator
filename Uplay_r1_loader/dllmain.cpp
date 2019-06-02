// dllmain.cpp: определяет точку входа для приложения DLL.
#include "stdafx.h"

#include <plog/Init.h>

#include "Consts.hpp"

BOOL APIENTRY DllMain(HMODULE hModule,
                                DWORD ul_reason_for_call,
                                LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		{
#ifdef _DEBUG
		init(plog::debug, UplayR1Loader::Consts::LogName);
#endif // _DEBUG
			break;
		}
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
