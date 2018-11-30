/*
 * ADC.h
 *
 *  Created on: 30 Nov 2018
 *      Author: cal
 */

#ifndef ADC_H_
#define ADC_H_
#include <stdint.h>
#include "stm32f0xx.h" /* include peripheral declarations */

void init_ADC(void);
uint8_t adc_read(void);


#endif /* ADC_H_ */
