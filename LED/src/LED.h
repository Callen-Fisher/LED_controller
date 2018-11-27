/*
 * LED.h
 *
 *  Created on: 27 Nov 2018
 *      Author: cal
 */

#ifndef LED_H_
#define LED_H_
#include <stdint.h>
#include "stm32f0xx.h" /* include peripheral declarations */

void init_LEDs(void);

void light_on(uint8_t LED);
void light_off(uint8_t LED);
void light_toggle(uint8_t LED);



#endif /* LED_H_ */
