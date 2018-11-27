/*
 * PB.h
 *
 *  Created on: 27 Nov 2018
 *      Author: cal
 */

#ifndef PB_H_
#define PB_H_
#include <stdint.h>
#include "stm32f0xx.h" /* include peripheral declarations */
void init_push_buttons(void);
uint8_t get_button_state(uint8_t button);

#endif /* PB_H_ */
