/*
 * timers.cpp
 *
 *  Created on: Dec 31, 2021
 *      Author: khorton
 */

#include "timers.h"

uint32_t my_ticks = 0;

namespace Timer {
	typedef struct TIM4 {
		uint32_t CR1;
		uint32_t CR2;
		uint32_t SMCR;
		uint32_t EGR;
		uint32_t CCMR1;
		uint32_t CCMR2;
		uint32_t CNT;
		uint32_t PSC;
		uint32_t ARR;
		uint32_t CCR1;
		uint32_t CCR2;
		uint32_t CCR3;
		uint32_t CCR4;
		uint32_t DCR;
		uint32_t DMAR;

	}__attribute__((packed))TIM4_t;
	void init_tim4(void)
	{
		uint32_t volatile *rcc = (uint32_t*)0x40023840;
		uint32_t volatile *pISER0 = (uint32_t*)0xE000E100;
//		TIM4_t volatile *tim4 = (TIM4_t*)0x40000800;
		uint32_t volatile *pPSC = (uint32_t*)0x40000828;
		uint32_t volatile *pARR = (uint32_t*)0x4000082C;
		uint32_t volatile *pCR1 = (uint32_t*)0x40000800;
		uint32_t volatile *pDIER = (uint32_t*)0x4000080C;
		uint32_t volatile *pEGR = (uint32_t*)0x40000814;
		*rcc |= (1 << 2);
		*pPSC = 0;
		*pARR = 72;
		*pCR1 |= 1 << 2;
		*pDIER |= 1 << 0;
		*pEGR |= 1 << 0;
		*pCR1 |= 1 << 0;

		*pISER0 |= 1 << 30;

	}

	void dMs(uint32_t ms)
	{
		uint32_t volatile *pCR1 = (uint32_t*)0x40000800;
		my_ticks = 0;
		*pCR1 |= 1 << 0;
		while(my_ticks < (ms * 10));

		*pCR1 &= ~ 1 << 0;
	}
}

extern "C" void TIM4_IRQHandler()
{
	uint32_t volatile *pSR = (uint32_t*)0x40002010;
	my_ticks++;

	*pSR &= ~(1 << 0);
}
