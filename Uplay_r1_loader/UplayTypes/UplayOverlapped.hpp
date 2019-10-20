#pragma once

#include "../stdafx.h"

namespace UplayR1Loader::UplayTypes
{
	struct UplayOverlapped
	{
		void* result;
		DWORD isOperationCompleted;
		DWORD reserved;

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
		this->isOperationCompleted = 1L;
	}
}