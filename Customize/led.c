/*
 * led.c
 *
 *  Created on: Mar 5, 2024
 *      Author: wolf.long
 */
#include "led.h"



void SelectLedLight(unsigned char signal,unsigned char color,unsigned char state)
{
	if(state)
		state = 0;
	else
		state = 1;
	switch(signal)
	{
	case CalibrateLed:
		switch(color)
		{
		case Red:
			HAL_GPIO_WritePin(GPIOA, Calibration_RED_Pin, state);
			break;
		case Green:
			HAL_GPIO_WritePin(GPIOA, Calibration_GREEN_Pin, state);
			break;
		case Blue:
			HAL_GPIO_WritePin(GPIOA, Calibration_BLUE_Pin, state);
			break;
		}
		break;
	case HeartLed:
		switch(color)
		{
		case Red:
			HAL_GPIO_WritePin(GPIOA, HEART_RED_Pin, state);
			break;
		case Green:
			HAL_GPIO_WritePin(GPIOA, HEART_GREEN_Pin, state);
			break;
		case Blue:
			HAL_GPIO_WritePin(GPIOC, HEART_BLUE_Pin, state);
			break;
		}
		break;
	case TripLed:
		switch(color)
		{
		case Red:
			HAL_GPIO_WritePin(GPIOB, TRIP_RED_Pin, state);
			break;
		case Green:
			HAL_GPIO_WritePin(GPIOB, TRIP_GREEN_Pin, state);
			break;
		case Blue:
			HAL_GPIO_WritePin(GPIOB, TRIP_BLUE_Pin, state);
			break;
		}
		break;
	case TestLed:
			switch(color)
			{
			case Red:
				HAL_GPIO_WritePin(GPIOB, TEST_IN_RED_Pin, state);
				break;
			case Green:
				HAL_GPIO_WritePin(GPIOB, TEST_IN_GREEN_Pin, state);
				break;
			case Blue:
				HAL_GPIO_WritePin(GPIOB, TEST_IN_BLUE_Pin, state);
				break;
			}
			break;
	}

}


