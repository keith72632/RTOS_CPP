/*
 * systick.h
 *
 *  Created on: Dec 28, 2021
 *      Author: khorton
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

#include <stdio.h>
#include <stdint.h>
/*
 * Processor Clock = 16MHz
 * Systick count clock = 16MHz (HSI)
 * 1ms = 1KHz in frequency domain. Use divisor
 * Reload value (count value) = 16000
 * Clock speed (16000000Hz) / count value = Tick Hz
 * */

#define TICK_HZ            1000
#define HSI_CLOCK          16000000U
#define SYSTICK_TIM_CLK    HSI_CLOCK

namespace Systick {
	void init(uint32_t tick_hz);
}

#endif /* SYSTICK_H_ */
