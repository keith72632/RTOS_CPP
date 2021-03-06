/*
 * tasks.h
 *
 *  Created on: Dec 28, 2021
 *      Author: khorton
 */

#ifndef TASKS_H_
#define TASKS_H_

#include <stdio.h>
#include <stdint.h>
#include "usart.h"

namespace Tasks {
	void tasks_uart(USART_t usart);
	void task_one_handler();
	void task_two_handler();
	void task_three_handler();
	void task_four_handler();
}


#endif /* TASKS_H_ */
