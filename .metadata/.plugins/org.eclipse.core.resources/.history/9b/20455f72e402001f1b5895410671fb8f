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
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include "oledbmp.h"
#include "bmp.h"
#include "oled_drive.h"
#include "led.h"
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
#define FALSE 0
#define TRUE 1

#define SCL_H HAL_GPIO_WritePin(GPIOC, SCL_Pin, GPIO_PIN_SET)
#define SCL_L HAL_GPIO_WritePin(GPIOC, SCL_Pin, GPIO_PIN_RESET)

#define SDA_H HAL_GPIO_WritePin(GPIOC, SDA_Pin, GPIO_PIN_SET)
#define SDA_L HAL_GPIO_WritePin(GPIOC, SDA_Pin, GPIO_PIN_RESET)

#define SDA_read HAL_GPIO_ReadPin(GPIOC, SDA_Pin)

#define OLED_CMD 0
#define OLED_DATA 1
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
__IO float usDelayBase;
void PY_usDelayTest(void)
{
  __IO uint32_t firstms, secondms;
  __IO uint32_t counter = 0;

  firstms = HAL_GetTick()+1;
  secondms = firstms+1;

  while(uwTick!=firstms) ;

  while(uwTick!=secondms) counter++;

  usDelayBase = ((float)counter)/1000;
}

void PY_Delay_us_t(uint32_t Delay)
{
  __IO uint32_t delayReg;
  __IO uint32_t usNum = (uint32_t)(Delay*usDelayBase);

  delayReg = 0;
  while(delayReg!=usNum) delayReg++;
}

void PY_usDelayOptimize(void)
{
  __IO uint32_t firstms, secondms;
  __IO float coe = 1.0;

  firstms = HAL_GetTick();
  PY_Delay_us_t(1000000) ;
  secondms = HAL_GetTick();

  coe = ((float)1000)/(secondms-firstms);
  usDelayBase = coe*usDelayBase;
}

void PY_Delay_us(uint32_t Delay)
{
  __IO uint32_t delayReg;

  __IO uint32_t msNum = Delay/1000;
  __IO uint32_t usNum = (uint32_t)((Delay%1000)*usDelayBase);

  if(msNum>0) HAL_Delay(msNum);

  delayReg = 0;
  while(delayReg!=usNum) delayReg++;
}
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void IIC_Init(void);
void IIC_Start(void);
void IIC_Stop(void);
void IIC_Send_Byte(uint8_t txd);
uint8_t IIC_Read_Byte(unsigned char ack);
uint8_t IIC_Wait_Ack(void);
void IIC_Ack(void);
void IIC_NAck(void);

#define SDA_IN()  my_SDA_IN()
#define SDA_OUT() my_SDA_OUT()


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
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
  OLED_Init();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  PY_usDelayTest();
  PY_usDelayOptimize();

  OnOffLedLight(1,2,0);
  OnOffLedLight(2,2,0);
  OnOffLedLight(3,2,0);
  OnOffLedLight(4,2,0);
  OnOffLedLight(5,2,0);
  OnOffLedLight(6,2,0);

	OLED_Init();
	OLED_Clear();
	OLED_ShowString(0,0,"Current ",16);
	OLED_ShowString(0,2,"        XX.XXMA",12);

  printf("init success\r\n");

  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  if(HAL_GPIO_ReadPin(GPIOC, ERROR_INPUT_Pin))
	  {
		  OnOffLedLight(4,2,1);
	  }
	  else if(HAL_GPIO_ReadPin(GPIOC, ERROR_INPUT_Pin) == 0)
	  {
		  OnOffLedLight(4,2,0);
	  }

	  if(HAL_GPIO_ReadPin(GPIOB, Calibrate_KEY_Pin) == 0)
	  {
		  HAL_msDelay(100);
		  while(HAL_GPIO_ReadPin(GPIOB, Calibrate_KEY_Pin) == 0);
		  HAL_GPIO_WritePin(GPIOA, TEST_IN_Pin, GPIO_PIN_RESET);
		  HAL_msDelay(100);
		  HAL_GPIO_WritePin(GPIOA, TEST_IN_Pin, GPIO_PIN_SET);
	  }
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



void my_SDA_IN(void)
{
	GPIO_InitTypeDef GPIO_InitStruct= {0};
	GPIO_InitStruct.Pin = SDA_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}
void my_SDA_OUT(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.Pin = SDA_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

void IIC_Init(void)
{
	my_SDA_OUT();
	SDA_L;
	SCL_L;
//	SDA_H;
//	SCL_H;
}

void IIC_Start(void)
{
	SDA_OUT();
	SDA_H;
	SCL_H;
	HAL_usDelay(5);
 	SDA_L;
 	HAL_usDelay(5);
	SCL_L;
}

void IIC_Stop(void)
{
	SDA_OUT();
	SCL_L;
	SDA_L;
	HAL_usDelay(4);
	SCL_H;
	SDA_H;
	HAL_usDelay(4);
}

uint8_t IIC_Wait_Ack(void)
{
	uint8_t ucErrTime=0;
	SDA_IN();
	SDA_H;HAL_usDelay(1);
	SCL_H;HAL_usDelay(1);
	while(SDA_read)
	{
		ucErrTime++;
		if(ucErrTime>250)
		{
			IIC_Stop();
			return 1;
		}
	}
	SCL_L;
	return 0;
}

void IIC_Ack(void)
{
	SCL_L;
	SDA_OUT();
	SDA_L;
	HAL_usDelay(2);
	SCL_H;
	HAL_usDelay(2);
	SCL_L;
}

void IIC_NAck(void)
{
	SCL_L;
	SDA_OUT();
	SDA_H;
	HAL_usDelay(2);
	SCL_H;
	HAL_usDelay(2);
	SCL_L;
}

void IIC_Send_Byte(uint8_t txd)
{
    uint8_t t;
	SDA_OUT();
    SCL_L;
    for(t=0;t<8;t++)
    {
		if((txd&0x80)>>7)
			SDA_H;
		else
			SDA_L;
		txd<<=1;
		HAL_usDelay(2);
		SCL_H;
		HAL_usDelay(2);
		SCL_L;
		HAL_usDelay(2);
    }
}

uint8_t IIC_Read_Byte(unsigned char ack)
{
	unsigned char i,receive=0;
	SDA_IN();
    for(i=0;i<8;i++ )
	{
        SCL_L;
        HAL_usDelay(2);
		SCL_H;
        receive<<=1;
        if(SDA_read)receive++;
        HAL_usDelay(1);
    }
    if (!ack)
        IIC_NAck();
    else
        IIC_Ack();
    return receive;
}

void OLED_WR_Byte(uint8_t dat,uint8_t mode)
{
	IIC_Start();
	IIC_Send_Byte(0x78);
	IIC_Wait_Ack();
	if(mode)
		IIC_Send_Byte(0x40);
	else
		IIC_Send_Byte(0x00);
	IIC_Wait_Ack();
	IIC_Send_Byte(dat);
	IIC_Wait_Ack();
	IIC_Stop();
}

// fill_Picture
void fill_picture(unsigned char fill_Data)
{
	unsigned char m,n;
	for(m=0;m<8;m++)
	{
		OLED_WR_Byte(0xb0+m,0);		//page0-page1
		OLED_WR_Byte(0x00,0);		//low column start address
		OLED_WR_Byte(0x10,0);		//high column start address
		for(n=0;n<128;n++)
			{
				OLED_WR_Byte(fill_Data,1);
			}
	}
}
void OLED_Set_Pos(unsigned char x, unsigned char y)
{ 	OLED_WR_Byte(0xb0+y,OLED_CMD);
	OLED_WR_Byte(((x&0xf0)>>4)|0x10,OLED_CMD);
	OLED_WR_Byte((x&0x0f),OLED_CMD);
}

void OLED_Display_On(void)
{
	OLED_WR_Byte(0X8D,OLED_CMD);  //SET DCDC
	OLED_WR_Byte(0X14,OLED_CMD);  //DCDC ON
	OLED_WR_Byte(0XAF,OLED_CMD);  //DISPLAY ON
}

void OLED_Display_Off(void)
{
	OLED_WR_Byte(0X8D,OLED_CMD);  //SET DCDC
	OLED_WR_Byte(0X10,OLED_CMD);  //DCDC OFF
	OLED_WR_Byte(0XAE,OLED_CMD);  //DISPLAY OFF
}

void OLED_Clear(void)
{
	uint8_t i,n;
	for(i=0;i<8;i++)
	{
		OLED_WR_Byte(0xb0+i,OLED_CMD);
		OLED_WR_Byte(0x00,OLED_CMD);
		OLED_WR_Byte(0x10,OLED_CMD);
		for(n=0;n<128;n++)OLED_WR_Byte(0,OLED_DATA);
	}
}
void OLED_On(void)
{
	uint8_t i,n;
	for(i=0;i<8;i++)
	{
		OLED_WR_Byte (0xb0+i,OLED_CMD);
		OLED_WR_Byte (0x00,OLED_CMD);
		OLED_WR_Byte (0x10,OLED_CMD);
		for(n=0;n<128;n++)OLED_WR_Byte(1,OLED_DATA);
	}
}

void OLED_ShowChar(uint8_t x,uint8_t y,uint8_t chr,uint8_t Char_Size)
{
	unsigned char c=0,i=0;
		c=chr-' ';
		if(x>Max_Column-1){x=0;y=y+2;}
		if(Char_Size ==16)
			{
			OLED_Set_Pos(x,y);
			for(i=0;i<8;i++)
			OLED_WR_Byte(F8X16[c*16+i],OLED_DATA);
			OLED_Set_Pos(x,y+1);
			for(i=0;i<8;i++)
			OLED_WR_Byte(F8X16[c*16+i+8],OLED_DATA);
			}
			else {
				OLED_Set_Pos(x,y);
				for(i=0;i<6;i++)
				OLED_WR_Byte(F6x8[c][i],OLED_DATA);

			}
}

uint32_t oled_pow(uint8_t m,uint8_t n)
{
	uint32_t result=1;
	while(n--)result*=m;
	return result;
}

void OLED_ShowNum(uint8_t x,uint8_t y,uint32_t num,uint8_t len,uint8_t size2)
{
	uint8_t t,temp;
	uint8_t enshow=0;
	for(t=0;t<len;t++)
	{
		temp=(num/oled_pow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				OLED_ShowChar(x+(size2/2)*t,y,' ',size2);
				continue;
			}else enshow=1;

		}
	 	OLED_ShowChar(x+(size2/2)*t,y,temp+'0',size2);
	}
}

void OLED_ShowString(uint8_t x,uint8_t y,uint8_t *chr,uint8_t Char_Size)
{
	unsigned char j=0;
	while (chr[j]!='\0')
	{		OLED_ShowChar(x,y,chr[j],Char_Size);
			x+=8;
		if(x>120){x=0;y+=2;}
			j++;
	}
}

void OLED_ShowCHinese(uint8_t x,uint8_t y,uint8_t no)
{
	uint8_t t;
	OLED_Set_Pos(x,y);
    for(t=0;t<16;t++)
	{
		OLED_WR_Byte(Hzk[2*no][t],OLED_DATA);

    }
		OLED_Set_Pos(x,y+1);
    for(t=0;t<16;t++)
	{
		OLED_WR_Byte(Hzk[2*no+1][t],OLED_DATA);
    }
}

void OLED_DrawBMP(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,unsigned char BMP[])
{
 unsigned int j=0;
 unsigned char x,y;

  if(y1%8==0) y=y1/8;
  else y=y1/8+1;
	for(y=y0;y<y1;y++)
	{
		OLED_Set_Pos(x0,y);
    for(x=x0;x<x1;x++)
	    {
	    	OLED_WR_Byte(BMP[j++],OLED_DATA);
	    }
	}
}

void OLED_Init(void)
{
    PY_Delay_us_t(200000);
    OLED_WR_Byte(0xAE,OLED_CMD);

	OLED_WR_Byte(0x40,OLED_CMD);//---set low column address
	OLED_WR_Byte(0xB0,OLED_CMD);//---set high column address

	OLED_WR_Byte(0xC8,OLED_CMD);//-not offset

	OLED_WR_Byte(0x81,OLED_CMD);
	OLED_WR_Byte(0xff,OLED_CMD);

	OLED_WR_Byte(0xa1,OLED_CMD);

	OLED_WR_Byte(0xa6,OLED_CMD);

	OLED_WR_Byte(0xa8,OLED_CMD);
	OLED_WR_Byte(0x1f,OLED_CMD);

	OLED_WR_Byte(0xd3,OLED_CMD);
	OLED_WR_Byte(0x00,OLED_CMD);

	OLED_WR_Byte(0xd5,OLED_CMD);
	OLED_WR_Byte(0xf0,OLED_CMD);

	OLED_WR_Byte(0xd9,OLED_CMD);
	OLED_WR_Byte(0x22,OLED_CMD);

	OLED_WR_Byte(0xda,OLED_CMD);
	OLED_WR_Byte(0x02,OLED_CMD);

	OLED_WR_Byte(0xdb,OLED_CMD);
	OLED_WR_Byte(0x49,OLED_CMD);

	OLED_WR_Byte(0x8d,OLED_CMD);
	OLED_WR_Byte(0x14,OLED_CMD);

	OLED_WR_Byte(0xaf,OLED_CMD);
	OLED_Clear();
}

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
