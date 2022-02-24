/*
 * interrupt.c
 *
 *  Created on: Feb 16, 2022
 *      Author: Samy
 */
#include "interrupt.h"
#include "common_macros.h"
#include "avr/io.h"
#include <avr/interrupt.h>
#include "gpio.h"
static volatile void (*g_callBackPtr0)(void)= NULL_PTR;
static volatile void (*g_callBackPtr1)(void)= NULL_PTR;
static volatile void (*g_callBackPtr2)(void)= NULL_PTR;
ISR(INT0_vect){
 if(g_callBackPtr0 != NULL_PTR){
	 (*g_callBackPtr0)();
 }
}
ISR(INT1_vect){
 if(g_callBackPtr1 != NULL_PTR){
	 (*g_callBackPtr1)();
 }
}
ISR(INT2_vect){
 if(g_callBackPtr2 != NULL_PTR){
	 (*g_callBackPtr2)();
 }
}
void INTERRUPT_init(const INTERRUPT_config *config_ptr){
	SREG |= (1<<7);
	if((config_ptr->INTERRUPT_number)==INTERRUPT_0){
		GPIO_setupPinDirection(PORTD_ID,PIN2_ID,PIN_INPUT);
		SET_BIT(GICR,INT0);
		MCUCR = (MCUCR & 0xFC) | ((config_ptr->mode));
	}
	else if((config_ptr->INTERRUPT_number)==INTERRUPT_1){
		GPIO_setupPinDirection(PORTD_ID,PIN3_ID,PIN_INPUT);
		SET_BIT(GICR,INT1);
		MCUCR = (MCUCR & 0xF3) | ((config_ptr->mode)<<2);
	}
	else if ((config_ptr->INTERRUPT_number)==INTERRUPT_2){
		GPIO_setupPinDirection(PORTB_ID,PIN2_ID,PIN_INPUT);
		SET_BIT(GICR,INT2);
		if((config_ptr->mode)==FALLING_EDGE){
			CLEAR_BIT(MCUCSR,ISC2);
		}else if ((config_ptr->mode)==RISING_EDGE){
			CLEAR_BIT(MCUCSR,ISC2);
		}
	}
}

void INTERRUPT_callback(const INTERRUPT_config *config_ptr,void (*a_ptr)(void)){
	if((config_ptr->INTERRUPT_number)==INTERRUPT_0){
		g_callBackPtr0=a_ptr;
	}
	else if((config_ptr->INTERRUPT_number)==INTERRUPT_1){
			g_callBackPtr1=a_ptr;
		}
	else if((config_ptr->INTERRUPT_number)==INTERRUPT_2){
				g_callBackPtr2=a_ptr;
			}

}
