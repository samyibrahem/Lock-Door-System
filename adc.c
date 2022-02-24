/*
 * adc.c
 *
 *  Created on: Feb 15, 2022
 *      Author: Samy
 */

#include "adc.h"
#include "avr/io.h"
#include "common_macros.h"

void ADC_init (void){
	ADCSRA =0;
	ADCSRA |= (1<<ADEN) | (1<<ADPS1) | (1<<ADPS0);
    ADMUX =0 ;

}

uint16 ADC_readChannel(uint8 pin_num){
	pin_num &= 0x07;
	ADMUX &= 0XE0;
	SET_BIT(ADCSRA,ADSC);
	while(BIT_IS_CLEAR(ADCSRA,ADIF));
	SET_BIT(ADCSRA,ADIF);
	return ADC;
}
