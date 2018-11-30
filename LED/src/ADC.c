/*
 * ADC.c
 *
 *  Created on: 30 Nov 2018
 *      Author: cal
 */

#include "ADC.h"

void init_ADC(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_ADCEN; //enable clock for ADC
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN; //enable clock for port which ADC samples from
	GPIOA->MODER |= GPIO_MODER_MODER5; //set PA5 to analogue mode
	ADC1->CHSELR |= ADC_CHSELR_CHSEL5; // select channel 5
	ADC1->CFGR1 |= ADC_CFGR1_RES_1;    // resolution to 8 bit
	ADC1->CR |= ADC_CR_ADCAL;         // set ADCAL high and wait for it to go low
	while( (ADC1->CR & ADC_CR_ADCAL) != 0);
	ADC1->CR |= ADC_CR_ADEN;           // set ADEN=1 in the ADC_CR register
	while((ADC1->ISR & ADC_ISR_ADRDY) == 0); //wait until ADRDY==1 in ADC_ISR
}
uint8_t adc_read(void)
{
	ADC1->CR |= ADC_CR_ADSTART;
	// wait for end of conversion: EOC == 1. Not necessary to clear EOC as we read from DR
	while((ADC1->ISR & ADC_ISR_EOC) == 0);
	uint8_t val=ADC1->DR;
	return val;
}
