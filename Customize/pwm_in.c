/*
 * pwm_in.c
 *
 *  Created on: Mar 5, 2024
 *      Author: wolf.long
 */
#include "pwm_in.h"
#include "led.h"
#include <stdio.h>
#include <main.h>

uint32_t Cap_val1,Cap_val2;
float Frequency,Duty;
unsigned char end_flag = 0;
unsigned char trip_flag = 0;
unsigned int trip_time = 0;
/* USER CODE BEGIN 4 */
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{

/*判断中断来源*/
	if(htim ->Channel == HAL_TIM_ACTIVE_CHANNEL_1 )
	{
		Cap_val1=HAL_TIM_ReadCapturedValue (&htim1 ,TIM_CHANNEL_1 );

		if(Cap_val1!=0)
		{
			Cap_val2=HAL_TIM_ReadCapturedValue (&htim1 ,TIM_CHANNEL_2 );
			Frequency=(float)(72000000 / 72)/(Cap_val1+1);
			Duty=(float)(Cap_val2+1)*100/(Cap_val1+1);
			end_flag=1;
		}
		else
		{
			Frequency=0;
			Duty=0;
		}
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) //10mm
{
	static unsigned char delay_tim = 10;
	if(htim == &htim2  && work_normol)
	{
		if(HAL_GPIO_ReadPin(GPIOA, TRIP_INPUT_Pin) == 1)		//Trip信�?�
		{
			trip_time++;
			trip_flag = 1;
		}

		if(trip_time > 200)
		{
			Frequency=0;
			Duty=0;
		}

		else if(trip_time > 0)
		{
			SelectLedLight(TripLed,Red,0);
//			SelectLedLight(TripLed,Green,0);
			SelectLedLight(TripLed,Blue,0);
			delay_tim--;
			if(delay_tim == 0)
			{
				HAL_GPIO_TogglePin(GPIOB, TRIP_GREEN_Pin);
				delay_tim = 5;
			}

			if(test_in_flag == 1)
				test_in_flag = 2;
		}

		else
		{
			SelectLedLight(TripLed,Red,0);
			SelectLedLight(TripLed,Green,0);
			SelectLedLight(TripLed,Blue,0);
		}
//		if(trip_time > 120 && trip_time < 140 && test_in_flag == 1)
//		{
//			SelectLedLight(TripLed,Red,0);
////			SelectLedLight(TripLed,Green,0);
//			SelectLedLight(TripLed,Blue,0);
//			delay_tim--;
//			if(delay_tim == 0)
//			{
//				HAL_GPIO_TogglePin(GPIOB, TRIP_GREEN_Pin);
//				delay_tim = 10;
//			}
//			test_in_flag = 2;
//		}
	}
	else
	{
		SelectLedLight(TripLed,Red,0);
		SelectLedLight(TripLed,Green,0);
		SelectLedLight(TripLed,Blue,0);
	}
}
/* USER CODE END 4 */

