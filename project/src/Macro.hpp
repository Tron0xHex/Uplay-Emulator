#pragma once

#define UPLAY_FUNC __cdecl
#define UPLAY_API extern "C" __declspec(dllexport)

#if _WIN32 || _WIN64
    #if _WIN64
        #define ENVIRONMENT_X64
    #else
        #define ENVIRONMENT_X32
    #endif
#endif