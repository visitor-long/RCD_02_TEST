/*
 * led.c
 *
 *  Created on: Mar 5, 2024
 *      Author: wolf.long
 */
#include "led.h"


void OnOffLedLight(unsigned char signal,unsigned char color,unsigned char state)
{
	switch(signal){
	    case ERROR_LED :
	    	if(color == Green)
	    	{
	    		if(state)
	    		 HAL_GPIO_WritePin(GPIOC, ERROR_GREEN_Pin, GPIO_PIN_RESET);
	    		else
				 HAL_GPIO_WritePin(GPIOC, ERROR_GREEN_Pin, GPIO_PIN_SET);
	    	}
	    	else if(color == Red)
	    	{
	    		if(state)
	    			HAL_GPIO_WritePin(GPIOC, ERROR_RED_Pin, GPIO_PIN_RESET);
	    		else
	    			HAL_GPIO_WritePin(GPIOC, ERROR_RED_Pin, GPIO_PIN_SET);
	    	}
	       break; /* 可选的 */
	    case TEST_IN_LED :
	    	if(color == Green)
	    	{
	    		if(state)
	    			HAL_GPIO_WritePin(GPIOB, TEST_IN_GREEN_Pin, GPIO_PIN_RESET);
	    		else
	    			HAL_GPIO_WritePin(GPIOB, TEST_IN_GREEN_Pin, GPIO_PIN_SET);
	    	}
	    	else if(color == Red)
	    	{
	    		if(state)
	    			HAL_GPIO_WritePin(GPIOB, TSET_IN_RED_Pin, GPIO_PIN_RESET);
	    		else
	    			HAL_GPIO_WritePin(GPIOB, TSET_IN_RED_Pin, GPIO_PIN_SET);
	    	}
	       break; /* 可选的 */
	    case TripLed2_LED :
	    	if(color == Green)
			{
	    		if(state)
	    			HAL_GPIO_WritePin(GPIOC, TRIP_GREEN1_Pin, GPIO_PIN_RESET);
	    		else
	    			HAL_GPIO_WritePin(GPIOC, TRIP_GREEN1_Pin, GPIO_PIN_SET);
			}
			else if(color == Red)
			{
	    		if(state)
	    			HAL_GPIO_WritePin(GPIOB, TRIP_RED1_Pin, GPIO_PIN_RESET);
	    		else
	    			HAL_GPIO_WritePin(GPIOB, TRIP_RED1_Pin, GPIO_PIN_SET);
			}
		   break; /* 可选的 */
	    case TripLed1_LED :
	    	if(color == Green)
			{
	    		if(state)
	    			HAL_GPIO_WritePin(GPIOB, TRIP_GREEN_Pin, GPIO_PIN_RESET);
	    		else
	    			HAL_GPIO_WritePin(GPIOB, TRIP_GREEN_Pin, GPIO_PIN_SET);
			}
			else if(color == Red)
			{
	    		if(state)
	    			HAL_GPIO_WritePin(GPIOB, TRIP_RED_Pin, GPIO_PIN_RESET);
	    		else
	    			HAL_GPIO_WritePin(GPIOB, TRIP_RED_Pin, GPIO_PIN_SET);
			}
		   break; /* 可选的 */
	    case PWM_LED :
	    	if(color == Green)
			{
	    		if(state)
	    			HAL_GPIO_WritePin(GPIOA, HEART_GREEN_Pin, GPIO_PIN_RESET);
	    		else
	    			HAL_GPIO_WritePin(GPIOA, HEART_GREEN_Pin, GPIO_PIN_SET);
			}
			else if(color == Red)
			{
	    		if(state)
	    			HAL_GPIO_WritePin(GPIOA, HEART_RED_Pin, GPIO_PIN_RESET);
	    		else
	    			HAL_GPIO_WritePin(GPIOA, HEART_RED_Pin, GPIO_PIN_SET);
			}
		   break; /* 可选的 */
	    case CALIBRATE_LED :
	    	if(color == Green)
			{
	    		if(state)
	    			HAL_GPIO_WritePin(GPIOA, CALIBRATION_GREEN_Pin, GPIO_PIN_RESET);
	    		else
	    			HAL_GPIO_WritePin(GPIOA, CALIBRATION_GREEN_Pin, GPIO_PIN_SET);
			}
			else if(color == Red)
			{
	    		if(state)
	    			HAL_GPIO_WritePin(GPIOA, CALIBRATION_RED_Pin, GPIO_PIN_RESET);
	    		else
	    			HAL_GPIO_WritePin(GPIOA, CALIBRATION_RED_Pin, GPIO_PIN_SET);
			}
		   break; /* 可选的 */
	    /* 您可以有任意数量的 case 语句 */
	    default : /* 可选的 */
	    	break;
	}
}

