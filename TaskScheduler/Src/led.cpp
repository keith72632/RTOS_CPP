/*
 * led.cpp
 *
 *  Created on: Dec 31, 2021
 *      Author: khorton
 */


#include "led.h"

namespace Led {
	void init_all_leds()
	{
		uint32_t volatile *rcc = (uint32_t*)0x40023830;
		uint32_t volatile *mode = (uint32_t*)0x40020C00;

		*rcc |= (1 << 3);
		*mode |= (1 << 24) | (1 << 26) | (1 << 28) | (1 << 30);
	}

	void led_on(uint32_t color)
	{
		uint32_t volatile *led = (uint32_t*)0x40020C14;
		*led ^= 1 << color ;
	}

	void delay(uint32_t divisor)
	{
		for(size_t i = 0; i < (divisor * 100000); i++);
	}
}
