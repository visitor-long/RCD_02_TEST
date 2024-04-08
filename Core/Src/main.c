/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dac.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "led.h"
#include <stdio.h>
#include "pwm_in.h"

unsigned char test_in_flag = 0;

unsigned char work_normol = 0;
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
void HAL_usDelay(uint32_t udelay);
void HAL_msDelay(uint32_t udelay);
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DAC_Init();
  MX_TIM1_Init();
  MX_USART1_UART_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */

  HAL_TIM_IC_Start_IT (&htim1,TIM_CHANNEL_1);
  HAL_TIM_IC_Start_IT (&htim1,TIM_CHANNEL_2);

  HAL_TIM_IC_Start_IT (&htim1,TIM_CHANNEL_4);
  HAL_TIM_Base_Start_IT(&htim2);
  HAL_DAC_Start(&hdac, DAC_CHANNEL_1);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  printf("init success\r\n");
  while (1)
  {
	if(HAL_GPIO_ReadPin(GPIOB, Calibration_START_Pin) == 0 && work_normol == 1)	//校准控制
	{
		HAL_msDelay(10);
		while(HAL_GPIO_ReadPin(GPIOB, Calibration_START_Pin) == 0);	//校准控制

		HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R, 4095);
		HAL_msDelay(200);
		HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R, 0);

		test_in_flag = 1;

		SelectLedLight(TestLed,Red,0);
		SelectLedLight(TestLed,Green,0);
		SelectLedLight(TestLed,Blue,0);
		SelectLedLight(TestLed,Green,1);

		SelectLedLight(CalibrateLed,Red,0);
		SelectLedLight(CalibrateLed,Green,0);
		SelectLedLight(CalibrateLed,Blue,0);
	}

	 if(end_flag)
	 {
//		printf ("Cap_val1 is :%ld ,  Cap_val2 is : %ld \r\n",Cap_val1 ,Cap_val2 );
//		printf ("Duty is :%0.2f%% Frequency is : %0.2f\r\n",Duty  ,Frequency  );
		end_flag=0;
	 }

	if(((int)Frequency >= 940 && (int)Frequency <= 1060) && ((int)Duty > 49 && (int)Duty < 51))//Heart beat信�?�
	{
		SelectLedLight(HeartLed,Red,0);
		SelectLedLight(HeartLed,Green,0);
		SelectLedLight(HeartLed,Blue,0);
		SelectLedLight(HeartLed,Green,1);
		work_normol = 1;
	}
	else if(test_in_flag == 0)
	{
		SelectLedLight(CalibrateLed,Red,0);
		SelectLedLight(CalibrateLed,Green,0);
		SelectLedLight(CalibrateLed,Blue,0);

		SelectLedLight(HeartLed,Red,0);
		SelectLedLight(HeartLed,Green,0);
		SelectLedLight(HeartLed,Blue,0);
		SelectLedLight(HeartLed,Red,1);
		work_normol = 0;
	}

	if(test_in_flag == 2)
	{
		trip_time = 0;
		HAL_msDelay(1700);
		if(((int)trip_time > 120 && (int)trip_time < 140) && work_normol == 1)
		{
			SelectLedLight(CalibrateLed,Red,0);
			SelectLedLight(CalibrateLed,Green,0);
			SelectLedLight(CalibrateLed,Blue,0);
			SelectLedLight(CalibrateLed,Green,1);
		}
		else
		{
			SelectLedLight(CalibrateLed,Red,0);
			SelectLedLight(CalibrateLed,Green,0);
			SelectLedLight(CalibrateLed,Blue,0);
			SelectLedLight(CalibrateLed,Red,1);
		}
		test_in_flag = 0;
		trip_time = 0;
		trip_flag = 0;
		SelectLedLight(TestLed,Red,0);
		SelectLedLight(TestLed,Green,0);
		SelectLedLight(TestLed,Blue,0);

		SelectLedLight(TripLed,Red,0);
		SelectLedLight(TripLed,Green,0);
		SelectLedLight(TripLed,Blue,0);

	}

	if(trip_flag == 1 && test_in_flag == 0)
	{
		HAL_msDelay(500);
		if(HAL_GPIO_ReadPin(GPIOA, TRIP_INPUT_Pin) == 0)
		{
			trip_flag = 0;
			trip_time = 0;
		}
	}
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void HAL_usDelay(uint32_t udelay)
{
  uint32_t startval,tickn,delays,wait;

  startval = SysTick->VAL;
  tickn = HAL_GetTick();

  delays =udelay * 72;
  if(delays > startval)
  {
    while(HAL_GetTick() == tickn);
    wait = 72000 + startval - delays;
    while(wait < SysTick->VAL);
  }
  else
  {
    wait = startval - delays;
    while(wait < SysTick->VAL && HAL_GetTick() == tickn);
  }
}

void HAL_msDelay(uint32_t udelay)
{
	uint16_t i = 0;
	for(i = 0;i < udelay;i++)
	{
		HAL_usDelay(1000);
	}
}

//HAL_msDelay(2000);
//	  SelectLedLight(CalibrateLed,Red,0);
//	  SelectLedLight(CalibrateLed,Green,0);
//	  SelectLedLight(CalibrateLed,Blue,0);
//	  SelectLedLight(CalibrateLed,Red,1);
//
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
