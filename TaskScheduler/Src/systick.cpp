/*
 * systick.cpp
 *
 *  Created on: Dec 28, 2021
 *      Author: khorton
 */




#include "systick.h"
#include "stack.h"

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

extern "C" {
	__attribute__((naked)) void SysTick_Handler()
	{
		//get current running tasks psp value
		__asm volatile("MRS R0,PSP");

		//store decremnt before. Starts at R0 (which has psp value currently) and stores registers
		__asm volatile("STMDB R0!,{R4-R11}");

		//save content of LR
		__asm volatile("PUSH {LR}");

		//save the current value of psp. stack is stored in previous instruction, psp value in in R0
		__asm volatile("BL save_psp_value");


		/**************************************************
		 *               CONTEXT SWITCHED                 *
		 * ************************************************/

		//retrive context of next task
		__asm volatile("BL update_next_task");

		//get next tasks past psp value
		__asm volatile("BL get_psp_value");

		//using next task psp value retreive new stack frame from R4-R11
		__asm volatile("LDMIA R0!,{R4-R11}");

		//update psp with value in r0
		__asm volatile("MSR PSP,R0");

		//restore LR
		__asm volatile("POP {LR}");

		//return
		__asm volatile("BX LR");
	}
}
