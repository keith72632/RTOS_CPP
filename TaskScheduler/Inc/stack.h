/*
 * stack.h
 *
 *  Created on: Dec 28, 2021
 *      Author: khorton
 */

#ifndef STACK_H_
#define STACK_H_

#include <stdint.h>
#include <stdlib.h>
#include <array>

#define SIZE_TASK_STACK        1024U
#define SIZE_SCHED_STACK       1024U

#define SRAM_START             0x20000000U
#define SRAM_SIZE              ( (128) * (1024) )
#define SRAM_END               ( (SRAM_START) + (SRAM_SIZE) )

#define T1_STACK_START         SRAM_END
#define T2_STACK_START         ( (SRAM_END) - (1 * SIZE_TASK_STACK) )
#define T3_STACK_START         ( (SRAM_END) - (2 * SIZE_TASK_STACK) )
#define T4_STACK_START         ( (SRAM_END) - (3 * SIZE_TASK_STACK) )
#define SCHED_STACK_START      ( (SRAM_END) - (4 * SIZE_TASK_STACK) )

#define DUMMY_XPSR             0x01000000U

extern "C" {
	__attribute__((naked)) void switch_to_psp();
	uint32_t get_psp_value(void);
	void save_psp_value(uint32_t current_psp);
	void update_next_task(void);
}

namespace Stacks {
	__attribute__((naked)) void init_scheduler_stack(uint32_t sched_stack_start);
	void init_task_stack(void);
}

#endif /* STACK_H_ */
