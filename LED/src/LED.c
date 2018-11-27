/*
 * LED.c
 *
 *  Created on: 27 Nov 2018
 *      Author: cal
 */
#include "LED.h"

void init_LEDs(void)
{
	GPIOB->MODER |= (GPIO_MODER_MODER0_0 | GPIO_MODER_MODER1_0 | GPIO_MODER_MODER2_0 | GPIO_MODER_MODER3_0 |
	        GPIO_MODER_MODER4_0 | GPIO_MODER_MODER5_0 | GPIO_MODER_MODER6_0 | GPIO_MODER_MODER7_0);
}



void light_on(uint8_t LED)
{
	switch(LED){
		case 0:
			GPIOB->ODR=GPIOB->ODR|0b1;
			break;
		case 1:
			GPIOB->ODR=GPIOB->ODR|0b10;
			break;
		case 2:
			GPIOB->ODR=GPIOB->ODR|0b100;
			break;
		case 3:
			GPIOB->ODR=GPIOB->ODR|0b1000;
			break;
		case 4:
			GPIOB->ODR=GPIOB->ODR|0b10000;
			break;
		case 5:
			GPIOB->ODR=GPIOB->ODR|0b100000;
			break;
		case 6:
			GPIOB->ODR=GPIOB->ODR|0b1000000;
			break;
		case 7:
			GPIOB->ODR=GPIOB->ODR|0b10000000;
			break;
		default:
			break;
	}

}

void light_off(uint8_t LED)
{
	switch(LED){
		case 0:
			GPIOB->ODR=GPIOB->ODR&0b11111110;
			break;
		case 1:
			GPIOB->ODR=GPIOB->ODR&0b11111101;
			break;
		case 2:
			GPIOB->ODR=GPIOB->ODR&0b11111011;
			break;
		case 3:
			GPIOB->ODR=GPIOB->ODR&0b11110111;
			break;
		case 4:
			GPIOB->ODR=GPIOB->ODR&0b11101111;
			break;
		case 5:
			GPIOB->ODR=GPIOB->ODR&0b11011111;
			break;
		case 6:
			GPIOB->ODR=GPIOB->ODR&0b10111111;
			break;
		case 7:
			GPIOB->ODR=GPIOB->ODR&0b01111111;
			break;
		default:
			break;

	}
}

void light_toggle(uint8_t LED)
{
	switch(LED){
			case 0:
				GPIOB->ODR=GPIOB->ODR ^ (1 << 0);
				break;
			case 1:
				GPIOB->ODR=GPIOB->ODR ^ (1 << 1);
				break;
			case 2:
				GPIOB->ODR=GPIOB->ODR ^ (1 << 2);
				break;
			case 3:
				GPIOB->ODR=GPIOB->ODR ^ (1 << 3);
				break;
			case 4:
				GPIOB->ODR=GPIOB->ODR ^ (1 << 4);
				break;
			case 5:
				GPIOB->ODR=GPIOB->ODR ^ (1 << 5);
				break;
			case 6:
				GPIOB->ODR=GPIOB->ODR ^ (1 << 6);
				break;
			case 7:
				GPIOB->ODR=GPIOB->ODR ^ (1 << 7);
				break;
			default:
				break;

		}
}
