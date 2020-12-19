#pragma once

#include "src/pch.h"
#include "src/Macro.hpp"

namespace UplayR1Loader
{
#ifdef UPLAY_API_2014_NEXT_GEN
	class UplayOverlapped
	{
	public:
		int *Result;
		int IsOperationCompleted;
		int Reserved;

		void SetZeros();
		void SetResult();
	};

	//------------------------------------------------------------------------------
	inline void UplayOverlapped::SetZeros()
	{
		memset(this, NULL, sizeof(UplayOverlapped));
	}

	//------------------------------------------------------------------------------
	inline void UplayOverlapped::SetResult()
	{
		// Result++;
		IsOperationCompleted = 1;
		Reserved = 0;
	}
#else
	class UplayOverlapped
	{
	public:
		void *Result;
		int IsOperationCompleted;
		int Reserved;

		void SetZeros();
		void SetResult(void *result);
	};

	//------------------------------------------------------------------------------
	inline void UplayOverlapped::SetZeros()
	{
		memset(this, NULL, sizeof(UplayOverlapped));
	}

	//------------------------------------------------------------------------------
	inline void UplayOverlapped::SetResult(void *outResult)
	{
		Result = outResult;
		IsOperationCompleted = 1;
	}
#endif
} // namespace UplayR1Loader
