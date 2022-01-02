/*
 * led.h
 *
 *  Created on: Dec 31, 2021
 *      Author: khorton
 */

#ifndef LED_H_
#define LED_H_

#include <stdint.h>
#include <stdlib.h>

#define GREEN     12
#define ORANGE    13
#define RED       14
#define BLUE      15

namespace Led {
	void init_all_leds(void);
	void led_on(uint32_t color);
	void delay(uint32_t divisor);
}



#endif /* LED_H_ */
