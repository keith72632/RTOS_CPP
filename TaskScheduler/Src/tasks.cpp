/*
 * tasks.cpp
 *
 *  Created on: Dec 28, 2021
 *      Author: khorton
 */


#include "tasks.h"
#include "led.h"
#include "timers.h"

namespace Tasks {
	Usart *usart;
	void tasks_uart(USART_t usart)
	{
		Tasks::usart = new Usart(usart);
	}

	void task_one_handler()
	{
		while(1)
		{
			Led::delay(10);
			Led::led_on(RED);
			Tasks::usart->puts("Task One\n\r");
			printf("Task one\n");
		}
	}

	void task_two_handler()
	{
		while(1)
		{
			Led::delay(8);
			Led::led_on(GREEN);
			Tasks::usart->puts("Task Two\n\r");
			printf("Task two\n");
		}
	}

	void task_three_handler()
	{
		while(1)
		{
			Led::delay(6);
			Led::led_on(BLUE);
			Tasks::usart->puts("Task Three\n\r");
			printf("Task three\n");
		}
	}

	void task_four_handler()
	{
		while(1)
		{
			Led::delay(4);
			Led::led_on(ORANGE);
			Tasks::usart->puts("Task Four\n\r");
			printf("Task four\n");
		}
}

}


