/*
 * stack.cpp
 *
 *  Created on: Dec 29, 2021
 *      Author: khorton
 */

#include "stack.h"
#include "tasks.h"

#define MAX_TASKS    4

std::array<uint32_t, MAX_TASKS> psp_of_tasks = {
		T1_STACK_START,
		T2_STACK_START,
		T3_STACK_START,
		T4_STACK_START
};

std::array<uint32_t, MAX_TASKS> task_handlers = {
		(uint32_t)Tasks::task_one_handler,
		(uint32_t)Tasks::task_two_handler,
		(uint32_t)Tasks::task_three_handler,
		(uint32_t)Tasks::task_four_handler
};

uint8_t current_task = 0;

#ifdef __cplusplus
extern "C" {

	uint32_t get_psp_value(void)
	{
		return psp_of_tasks[current_task];
	}

	void save_psp_value(uint32_t current_psp)
	{
		psp_of_tasks[current_task] = current_psp;
	}

	void update_next_task(void)
	{
		current_task++;
		current_task = current_task % MAX_TASKS;
		printf("current task: %d\n", current_task);
	}

	__attribute__((naked)) void switch_to_psp()
	{
		//Save Link register
		__asm volatile ("PUSH {LR}");

		//get psp value
		__asm volatile ("BL get_psp_value");
		//return value of get_psp_value is in R0. Initializes PSP to address of task
		__asm volatile ("MSR PSP,R0");

		//restore link register value to be able to return from this functions
		__asm volatile("POP {LR}");

		//change stack pointer from MSP to PSP
		__asm volatile ("MOV R0,#0X02");
		__asm volatile ("MSR CONTROL,R0");

		//return
		__asm volatile("BX LR");
	}

}
#endif

namespace Stacks {
	__attribute__((naked)) void init_scheduler_stack(uint32_t sched_stack_start)
	{
		__asm volatile("MSR MSP,%0" : : "r"(sched_stack_start) : );
		__asm volatile("BX LR");
	}

	void init_task_stack(void)
	{
		uint32_t *pPSP = NULL;

		for(size_t i = 0; i < MAX_TASKS; i++)
		{
			//stack is full descending, so set register then decremement
			pPSP = (uint32_t*)psp_of_tasks[i];    //stack pointer. No dereference, because this is the location in memory of task stack

			pPSP--;
			*pPSP = DUMMY_XPSR;

			pPSP--;// Program Counter
			*pPSP = task_handlers[i]; //must be odd number address

			pPSP--; //Link Register
			*pPSP = 0xFFFFFFFD;

			for(size_t j = 0; j < 13; j++){
				pPSP--; //Set R0-R12 to zero
				*pPSP = 0;
			}

			//save value of psp
			psp_of_tasks[i] = (uint32_t)pPSP;
		}
	}
}

