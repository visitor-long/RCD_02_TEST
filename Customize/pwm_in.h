/*
 * pwm_in.h
 *
 *  Created on: Mar 5, 2024
 *      Author: wolf.long
 */

#ifndef PWM_IN_H_
#define PWM_IN_H_

#include "main.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_tim.h"

extern float Frequency;
extern float Duty;

extern unsigned char end_flag;

extern uint32_t Cap_val1;
extern uint32_t Cap_val2;
extern unsigned int trip_time;
extern unsigned char trip_flag;
#endif /* PWM_IN_H_ */
