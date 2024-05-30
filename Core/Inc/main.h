/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
extern unsigned char test_in_flag;
extern unsigned int pwm_time_flag;
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
extern unsigned char work_normol;
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
void test_in();


/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define SCL_Pin GPIO_PIN_2
#define SCL_GPIO_Port GPIOC
#define SDA_Pin GPIO_PIN_3
#define SDA_GPIO_Port GPIOC
#define CALIBRATION_RED_Pin GPIO_PIN_1
#define CALIBRATION_RED_GPIO_Port GPIOA
#define CALIBRATION_GREEN_Pin GPIO_PIN_2
#define CALIBRATION_GREEN_GPIO_Port GPIOA
#define CALIBRATION_BLUE_Pin GPIO_PIN_3
#define CALIBRATION_BLUE_GPIO_Port GPIOA
#define TEST_IN_Pin GPIO_PIN_4
#define TEST_IN_GPIO_Port GPIOA
#define HEART_RED_Pin GPIO_PIN_6
#define HEART_RED_GPIO_Port GPIOA
#define HEART_GREEN_Pin GPIO_PIN_7
#define HEART_GREEN_GPIO_Port GPIOA
#define HEART_BLUE_Pin GPIO_PIN_4
#define HEART_BLUE_GPIO_Port GPIOC
#define TRIP_RED_Pin GPIO_PIN_2
#define TRIP_RED_GPIO_Port GPIOB
#define TRIP_GREEN_Pin GPIO_PIN_10
#define TRIP_GREEN_GPIO_Port GPIOB
#define TRIP_BLUE_Pin GPIO_PIN_11
#define TRIP_BLUE_GPIO_Port GPIOB
#define TSET_IN_RED_Pin GPIO_PIN_12
#define TSET_IN_RED_GPIO_Port GPIOB
#define TEST_IN_GREEN_Pin GPIO_PIN_13
#define TEST_IN_GREEN_GPIO_Port GPIOB
#define TEST_IN_BLUE_Pin GPIO_PIN_14
#define TEST_IN_BLUE_GPIO_Port GPIOB
#define TRIP_RED1_Pin GPIO_PIN_15
#define TRIP_RED1_GPIO_Port GPIOB
#define TRIP_GREEN1_Pin GPIO_PIN_6
#define TRIP_GREEN1_GPIO_Port GPIOC
#define TRIP_BLUE1_Pin GPIO_PIN_7
#define TRIP_BLUE1_GPIO_Port GPIOC
#define ERROR_RED_Pin GPIO_PIN_8
#define ERROR_RED_GPIO_Port GPIOC
#define ERROR_GREEN_Pin GPIO_PIN_9
#define ERROR_GREEN_GPIO_Port GPIOC
#define ERROR_BLUE_Pin GPIO_PIN_8
#define ERROR_BLUE_GPIO_Port GPIOA
#define PWM_INT_Pin GPIO_PIN_10
#define PWM_INT_GPIO_Port GPIOC
#define PWM_INT_EXTI_IRQn EXTI15_10_IRQn
#define ERROR_INPUT_Pin GPIO_PIN_11
#define ERROR_INPUT_GPIO_Port GPIOC
#define TRIP_OUT2_Pin GPIO_PIN_12
#define TRIP_OUT2_GPIO_Port GPIOC
#define TRIP_OUT1_Pin GPIO_PIN_2
#define TRIP_OUT1_GPIO_Port GPIOD
#define TRIP_OUT1_EXTI_IRQn EXTI2_IRQn
#define Calibrate_KEY_Pin GPIO_PIN_3
#define Calibrate_KEY_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
