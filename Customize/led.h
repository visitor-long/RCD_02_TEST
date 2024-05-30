/*
 * led.h
 *
 *  Created on: Mar 5, 2024
 *      Author: wolf.long
 */

#ifndef INC_LED_H_
#define INC_LED_H_

#include "main.h"
#include "gpio.h"

enum Signal{TEST_IN_LED=1, TripLed1_LED =2, TripLed2_LED=3, ERROR_LED =4, PWM_LED=5, CALIBRATE_LED=6};
enum Color{Red=1, Green=2, Blue=3};


void OnOffLedLight(unsigned char signal,unsigned char color,unsigned char state);

#endif /* INC_LED_H_ */
