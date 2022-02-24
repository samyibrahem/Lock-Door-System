/*
 * adc.h
 *
 *  Created on: Feb 15, 2022
 *      Author: Samy
 */

#ifndef ADC_H_
#define ADC_H_
#include "std_types.h"

#define ADC_MAX_VALUE 1023
#define ADC_REF_VOLT 5
void ADC_init(void);
uint16 ADC_readChannel(uint8 pin_num);

#endif /* ADC_H_ */
