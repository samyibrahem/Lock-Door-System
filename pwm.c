/*
 * pwm.c
 *
 *  Created on: Feb 16, 2022
 *      Author: Samy
 */

#include "pwm.h"
#include "avr/io.h"
#include "common_macros.h"
#include "gpio.h"
uint8 g_intialCount_T0=0;
uint16 g_intialCount_T1=0;
uint8 g_intialCount_T2=0;


void PWM_init(const PWM_CONFIG *config_ptr ){
	if((config_ptr->timer)==TIMER_0){
		GPIO_setupPinDirection(PORTB_ID,PIN3_ID,PIN_OUTPUT);
		TCNT0=g_intialCount_T0;
		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		TCCR0 = (TCCR0 & 0xCF) | ((config_ptr->mode)<<4);
		TCCR0 = (TCCR0 &0xF8) | ((config_ptr->clock));
	}
	else if((config_ptr->timer)==TIMER_2){
		GPIO_setupPinDirection(PORTD_ID,PIN7_ID,PIN_OUTPUT);
		TCNT2=g_intialCount_T2;
		SET_BIT(TCCR2,WGM21);
		SET_BIT(TCCR2,WGM20);
		TCCR2 =(TCCR2 & 0xCF) | ((config_ptr->mode)<<4);
		TCCR2 =(TCCR2 & 0xF8) | ((config_ptr->clock));
	}

}

void PWM_changeDuty(const PWM_CONFIG *config_ptr , uint8 a_duty){
	if((config_ptr->timer)==TIMER_0){
		OCR0=a_duty;
	}
	else if((config_ptr->timer)==TIMER_2){
		OCR2=a_duty;
	}
}

