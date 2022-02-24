/*
 * pwm.h
 *
 *  Created on: Feb 16, 2022
 *      Author: Samy
 */

#ifndef PWM_H_
#define PWM_H_
#include "std_types.h"
extern uint8 g_initialCount_T0;
extern uint16 g_initialCount_T1;
extern uint8 g_initialCount_T2;

typedef enum {
	TIMER_0,TIMER_1,TIMER_2
}PWM_TIMER;

typedef enum{
	NORMAL,RESERVED,NON_INVERTING,INVERTING
}PWM_MODE;

typedef enum{
	NO_CLOCK,CPU_CLOCK,CPU_8,CPU_64,CPU_256,CPU_1024,EXTERNAL_CLOCK_FALL,EXTERNAL_CLOCK_RISE
}PWM_CLOCK;

typedef struct {
	PWM_TIMER timer;
	PWM_MODE mode;
	PWM_CLOCK clock;
}PWM_CONFIG;

void PWM_init(const PWM_CONFIG *config_ptr );
void PWM_changeDuty(const PWM_CONFIG *config_ptr , uint8 a_duty);
#endif /* PWM_H_ */
