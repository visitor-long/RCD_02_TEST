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

enum Signal{CalibrateLed=1, HeartLed=2, TripLed=3, TestLed=4};
enum Color{Red=1, Green=2, Blue=3};


void SelectLedLight(unsigned char signal,unsigned char color,unsigned char state);

#endif /* INC_LED_H_ */
