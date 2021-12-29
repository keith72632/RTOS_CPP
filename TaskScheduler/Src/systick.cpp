/*
 * systick.cpp
 *
 *  Created on: Dec 28, 2021
 *      Author: khorton
 */




#include "systick.h"

namespace Systick {
	void init(uint32_t tick_hz)
	{
		uint32_t *pSRVR = (uint32_t*)0xE000E014;
		uint32_t *pCSR  = (uint32_t*)0xE000E010;
		uint32_t count_value = (SYSTICK_TIM_CLK / tick_hz) - 1;

		*pSRVR &= ~0xFFFFFF;
		*pSRVR |= count_value;

		*pCSR |= 1 << 2 | 1 << 1 | 1 << 0;
	}
}

extern "C" void SysTick_Handler()
{
	printf("tick\n");
}
