/*
 * interrupt.h
 *
 *  Created on: Feb 16, 2022
 *      Author: Samy
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

typedef enum {
	INTERRUPT_0,INTERRUPT_1,INTERRUPT_2
}INTERRUPT_type;

typedef enum{
	LOW_LEVEL,LOGICAL_CHANGE,FALLING_EDGE,RISING_EDGE
}INTERRUPT_mode;

typedef struct{
	INTERRUPT_type INTERRUPT_number;
	INTERRUPT_mode mode;
}INTERRUPT_config;
void INTERRUPT_init(const INTERRUPT_config *config_ptr);
void INTERRUPT_callback(const INTERRUPT_config *config_ptr,void (*a_ptr)(void));

#endif /* INTERRUPT_H_ */
