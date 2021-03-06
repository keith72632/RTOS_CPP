/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include <string>
#include "tasks.h"
#include "stack.h"
#include "systick.h"
#include "faults.h"
#include "led.h"
#include "timers.h"
#include "usart.h"
#include "stm32f407xx.h"

int main(void)
{
	Usart usart3 = Usart(USART3);
	usart3.puts("Usart3 enabled\n\r");
	Led::init_all_leds();
//	Timer::init_tim4();
	Faults::enable_faults();

	Stacks::init_scheduler_stack(SCHED_STACK_START);
	Stacks::init_task_stack();

	Systick::init(TICK_HZ);

	switch_to_psp();
	Tasks::tasks_uart(USART3);
	Tasks::task_one_handler();
    /* Loop forever */
	for(;;);
}


