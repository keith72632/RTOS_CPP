/*
 * faults.cpp
 *
 *  Created on: Dec 30, 2021
 *      Author: khorton
 */




#include "faults.h"


namespace Faults {
	void enable_faults()
	{
		uint32_t volatile *pSHCSR = (uint32_t*)0xE000ED24;
		*pSHCSR |= (1 << 16) | (1 << 17) | (1 << 18);
	}

	void gen_usage_fault()
	{
		void (*addr)(void);
		uint32_t *SRAM = (uint32_t*)0x20010000;
		addr = (void(*)())SRAM;
		addr();
	}

	void gen_memory_fault()
	{
		void (*addr)(void);
		uint32_t *SRAM = (uint32_t*)0x40020000;
		addr = (void(*)())SRAM;
		addr();
	}
}

#ifdef __cplusplus
	extern "C" {
		void HardFault_Handler()
		{
			printf("Hardfault\n");
			while(1);
		}

		void MemManage_Handler()
		{
			printf("Memory Manage Fault\n");
			while(1);
		}

		void BusFault_Handler()
		{
			printf("Bus Fault\n");
			while(1);
		}

		void UsageFault_Handler()
		{
			printf("Usage Fault\n");
			while(1);
		}
	}

#endif
