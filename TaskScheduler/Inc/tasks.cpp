/*
 * tasks.cpp
 *
 *  Created on: Dec 28, 2021
 *      Author: khorton
 */


#include "tasks.h"

#ifdef __cplusplus
extern "C" {
	void task_one_handler()
	{
		while(1)
		{
			printf("Task one\n");
		}
	}

	void task_two_handler()
	{
		while(1)
		{
			printf("Task two\n");
		}
	}

	void task_three_handler()
	{
		while(1)
		{
			printf("Task three\n");
		}
	}

	void task_four_handler()
	{
		while(1)
		{
			printf("Task four\n");
		}
	}
}
#endif
