/*
 * timers.h
 *
 *  Created on: Dec 31, 2021
 *      Author: khorton
 */

#ifndef TIMERS_H_
#define TIMERS_H_

#include <stdint.h>
#include <stdio.h>

namespace Timer {
	void init_tim4(void);
	void dMs(uint32_t ms);
}



#endif /* TIMERS_H_ */
