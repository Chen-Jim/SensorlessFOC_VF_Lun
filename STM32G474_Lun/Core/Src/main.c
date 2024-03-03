/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "dma.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include <stdio.h>
#include <string.h>
#include "FOC_Model.h"
#include "user_uploader.h" 
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

#define RXBUFFERSIZE  256   
char RxBuffer[RXBUFFERSIZE];  
uint8_t aRxBuffer;			   
uint8_t Uart1_Rx_Cnt = 0;	

 
uint16_t adc1_in1, adc1_in2, adc1_in3, adc1_in4, adc_vbus;
uint16_t IA_Offset,IB_Offset,IC_Offset;
uint8_t ADC_offset = 0;
uint16_t finalspeed = 0;
uint8_t Motor_state = 0;
/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;
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
  MX_ADC1_Init();
  MX_DMA_Init();
  MX_USART3_UART_Init();
  MX_TIM1_Init();
  MX_ADC2_Init();
  /* USER CODE BEGIN 2 */

	HAL_ADCEx_Calibration_Start( &hadc1, ADC_SINGLE_ENDED); 
	__HAL_ADC_CLEAR_FLAG( &hadc1, ADC_FLAG_JEOC);
	__HAL_ADC_CLEAR_FLAG( &hadc1, ADC_FLAG_EOC);
	HAL_ADCEx_InjectedStart_IT(&hadc1);
	HAL_TIM_Base_Start( &htim1);
	HAL_TIM_PWM_Start( &htim1, TIM_CHANNEL_4);
	rtU.Speed_ref = 1200;
	rtU.VDC = 24;
//	motor_svpwm
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */  
// 启动注入转换
		HAL_ADCEx_InjectedStart(&hadc2); 
		adc_vbus = hadc2.Instance->JDR2;
		rtU.VDC=adc_vbus*0.01359f; 
		
		adc1_in4 = hadc2.Instance->JDR1;
		finalspeed = (adc1_in4>>4) * 15;
		if(finalspeed >=0 && finalspeed <400)
		{
			finalspeed = 400;
		}
		if(finalspeed > 1200)
		{
			finalspeed = 1200;
		}
		rtU.Speed_ref = finalspeed;
		HAL_Delay(10);
		 
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
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Configure the main internal regulator output voltage
  */
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1_BOOST);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = RCC_PLLM_DIV1;
  RCC_OscInitStruct.PLL.PLLN = 40;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the peripherals clocks
  */
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART3|RCC_PERIPHCLK_ADC12;
  PeriphClkInit.Usart3ClockSelection = RCC_USART3CLKSOURCE_PCLK1;
  PeriphClkInit.Adc12ClockSelection = RCC_ADC12CLKSOURCE_SYSCLK;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */



////void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
////{
////  /* Prevent unused argument(s) compilation warning */
////  UNUSED(GPIO_Pin);
////	if(Button3_Pin == GPIO_Pin)
////	{ 
////		printf("78910\r\n");
////	}
////  /* NOTE: This function should not be modified, when the callback is needed,
////           the HAL_GPIO_EXTI_Callback could be implemented in the user file
////   */
////}
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(GPIO_Pin);
	unsigned int i=0;
	while(i++<=0x0FFF);
//	HAL_Delay(10);//消抖
	if(Button1_Pin == GPIO_Pin)
	{ 
		HAL_GPIO_TogglePin(LED1_GPIO_Port,LED1_Pin);
	}
	if(Button3_Pin == GPIO_Pin)
	{
		Motor_state = ~Motor_state;
		HAL_GPIO_TogglePin(LED2_GPIO_Port,LED2_Pin);
		if(0 == Motor_state)
		{
			rtU.MotorOnOff = 0;
			HAL_TIM_PWM_Stop( &htim1, TIM_CHANNEL_1);
			HAL_TIM_PWM_Stop( &htim1, TIM_CHANNEL_2);
			HAL_TIM_PWM_Stop( &htim1, TIM_CHANNEL_3);
			HAL_TIMEx_PWMN_Stop( &htim1, TIM_CHANNEL_1);
			HAL_TIMEx_PWMN_Stop( &htim1, TIM_CHANNEL_2);
			HAL_TIMEx_PWMN_Stop( &htim1, TIM_CHANNEL_3);
		}
		else
		{
			rtU.MotorOnOff = 1;
			HAL_TIM_PWM_Start( &htim1, TIM_CHANNEL_1);
			HAL_TIM_PWM_Start( &htim1, TIM_CHANNEL_2);
			HAL_TIM_PWM_Start( &htim1, TIM_CHANNEL_3);
			HAL_TIMEx_PWMN_Start( &htim1, TIM_CHANNEL_1);
			HAL_TIMEx_PWMN_Start( &htim1, TIM_CHANNEL_2);
			HAL_TIMEx_PWMN_Start( &htim1, TIM_CHANNEL_3);
		}
	}
  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_GPIO_EXTI_Callback could be implemented in the user file
   */
}
  
void HAL_ADCEx_InjectedConvCpltCallback(ADC_HandleTypeDef *hadc)
{
	static uint8_t cnt;
	static uint16_t obsever_cnt;
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hadc);
	if(hadc == &hadc1)
	{ 
		if(ADC_offset == 0)
		{
			cnt++;
			adc1_in1 = hadc1.Instance->JDR1;
			adc1_in2 = hadc1.Instance->JDR2;
			adc1_in3 = hadc1.Instance->JDR3;
			
			
			IA_Offset += adc1_in1;
			IB_Offset += adc1_in2;
			IC_Offset += adc1_in3;
			if(cnt >= 10)
			{
				ADC_offset = 1;
				IA_Offset = IA_Offset/10;
				IB_Offset = IB_Offset/10;
				IC_Offset = IC_Offset/10;
			}
		}
		else
		{
			adc1_in1 = hadc1.Instance->JDR1;
			adc1_in2 = hadc1.Instance->JDR2;
			adc1_in3 = hadc1.Instance->JDR3;
//			rtU.ic = (adc1_in1 - IA_Offset)*0.008f;
			rtU.ib = (adc1_in2 - IB_Offset)*0.008f;
			rtU.ia = (adc1_in3 - IC_Offset)*0.008f; 
			rtU.ic = -rtU.ia -rtU.ib;
			FOC_Model_step();
			TIM1->CCR1 = rtY.Tcmp1;
			TIM1->CCR2 = rtY.Tcmp2;
			TIM1->CCR3 = rtY.Tcmp3;
			Frame_Data_type.fdata[0]=rtU.VDC;
			Frame_Data_type.fdata[1]=rtY.LunTheta;
			Frame_Data_type.fdata[2]=rtY.LunWm;
			Frame_Data_type.fdata[3]=rtU.Speed_ref;
			Frame_Data_type.fdata[4]=rtU.ia;
			Frame_Data_type.fdata[5]=rtU.ib;
			Frame_Data_type.fdata[6]=rtU.ic; 
			Plot_Data_UpLoad();
		}
	}

  /* NOTE : This function should not be modified. When the callback is needed,
            function HAL_ADCEx_InjectedConvCpltCallback must be implemented in the user file.
  */
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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
