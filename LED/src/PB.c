/*
 * PB.c
 *
 *  Created on: 27 Nov 2018
 *      Author: cal
 */

#include "PB.h"

void init_push_buttons(void) {
  RCC->AHBENR |= RCC_AHBENR_GPIOAEN; //enable clock for push-buttons
  // set pins to inputs
  GPIOA->MODER &= ~GPIO_MODER_MODER0; //set PA0 to input
  GPIOA->MODER &= ~GPIO_MODER_MODER1; //set PA1 to input
  GPIOA->MODER &= ~GPIO_MODER_MODER2; //set PA2 to input
  GPIOA->MODER &= ~GPIO_MODER_MODER3; //set PA3 to input
  // enable pull-down resistors
  GPIOA->PUPDR |= GPIO_PUPDR_PUPDR0_0; //enable pull up for PA0
  GPIOA->PUPDR |= GPIO_PUPDR_PUPDR1_0; //enable pull up for PA1
  GPIOA->PUPDR |= GPIO_PUPDR_PUPDR2_0; //enable pull up for PA2
  GPIOA->PUPDR |= GPIO_PUPDR_PUPDR3_0; //enable pull up for PA3
}

uint8_t get_button_state(uint8_t button)
{
	uint8_t val=0;
	switch(button){
		case 0:
			if((GPIOA->IDR & GPIO_IDR_0)==0)
				val=1;
			break;
		case 1:
			if((GPIOA->IDR & GPIO_IDR_1)==0)
				val=1;
			break;
		case 2:
			if((GPIOA->IDR & GPIO_IDR_2)==0)
				val=1;
			break;
		case 3:
			if((GPIOA->IDR & GPIO_IDR_3)==0)
				val=1;
			break;
		default:
			break;
	}
	return val;
}
