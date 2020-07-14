#pragma once

#include "../stdafx.h"

namespace UplayR1Loader::UplayTypes
{
#ifdef UPLAY_API_2014_NEXT_GEN
	struct UplayOverlapped
	{
		int* result;
		int isOperationCompleted;
		int reserved;

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
		this->result++;
		this->isOperationCompleted = 1;
		this->reserved = 0;
	}
#else
	struct UplayOverlapped
	{
		void* result;
		int isOperationCompleted;
		int reserved;

		void SetZeros();
		void SetResult(void* result);
	};

	//------------------------------------------------------------------------------
	inline void UplayOverlapped::SetZeros()
	{
		memset(this, NULL, sizeof(UplayOverlapped));
	}

	//------------------------------------------------------------------------------
	inline void UplayOverlapped::SetResult(void* result)
	{
		this->result = result;
		this->isOperationCompleted = 1;
	}
#endif
}
