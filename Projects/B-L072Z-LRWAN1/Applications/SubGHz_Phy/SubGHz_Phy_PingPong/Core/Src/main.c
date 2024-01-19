#include "main.h"
#include "app_subghz_phy.h"
#include "user_main.h"
#include "sys_app.h"
#include "gpio.h"
#include "user_util.h"
#include "user_adc.h"

void SystemClock_Config(void);
void SystemClock_Config_MSI(void);

int main(void)
{
	HAL_Init();

	#ifdef DEVICE_TYPE_STATION
		SystemClock_Config();
	#else
		SystemClock_Config_MSI();
	#endif

	MX_SubGHz_Phy_Init();
	Main_Task();
//	STM32_MX_ADC1_Init();
//	MX_GPIO_Init();
//	uint8_t adc_BAT;
//	while (1){
//		HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_6);
//		adc_VNA = Get_Vol_VNA();
//		adc_VP = Get_Vol_VP();
//		adc_BAT	= Get_Vol_BAT();
//		LOG(LOG_INFOR, "ADC_VNA: %d", adc_VNA);
//		LOG(LOG_INFOR, "ADC_VP : %d", adc_VP);
//		LOG(LOG_INFOR, "ADC_VBAT : %d", adc_BAT);
//		HAL_Delay(1000);
//	}
}

void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = {0};
	RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
	RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

	/* Enable HSE Oscillator and Activate PLL with HSE as source */
	RCC_OscInitStruct.OscillatorType      = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSEState            = RCC_HSE_OFF;
	RCC_OscInitStruct.HSIState            = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState        = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource       = RCC_PLLSOURCE_HSI;
	RCC_OscInitStruct.PLL.PLLMUL          = RCC_PLLMUL_6;
	RCC_OscInitStruct.PLL.PLLDIV          = RCC_PLLDIV_3;

	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	{
		Error_Handler();
	}

	/* Set Voltage scale1 as MCU will run at 32MHz */
	__HAL_RCC_PWR_CLK_ENABLE();
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	/* Poll VOSF bit of in PWR_CSR. Wait until it is reset to 0 */
	while (__HAL_PWR_GET_FLAG(PWR_FLAG_VOS) != RESET) {};

	/* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
	clocks dividers */
	RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
	{
		Error_Handler();
	}

	PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_LPTIM1|RCC_PERIPHCLK_USART1|RCC_PERIPHCLK_USART2
					  	  	  	  	  	  |RCC_PERIPHCLK_I2C1|RCC_PERIPHCLK_RTC;
	PeriphClkInit.LptimClockSelection = RCC_LPTIM1CLKSOURCE_LSE;
	PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK2;
	PeriphClkInit.Usart2ClockSelection = RCC_USART2CLKSOURCE_SYSCLK;
	PeriphClkInit.I2c1ClockSelection = RCC_I2C1CLKSOURCE_PCLK1;
	PeriphClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSE;
	if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
	{
		Error_Handler();
	}
}

/* USER CODE BEGIN 4 */
void SystemClock_Config_MSI(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = {0};
	RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
	RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

	/** Configure the main internal regulator output voltage
	*/
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	/** Configure LSE Drive Capability
	*/
	HAL_PWR_EnableBkUpAccess();
	__HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_LOW);

	/** Initializes the RCC Oscillators according to the specified parameters
	* in the RCC_OscInitTypeDef structure.
	*/
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSE|RCC_OSCILLATORTYPE_MSI;
	RCC_OscInitStruct.LSEState = RCC_LSE_ON;
	RCC_OscInitStruct.MSIState = RCC_MSI_ON;
	RCC_OscInitStruct.MSICalibrationValue = 0;
	RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	{
		Error_Handler();
	}

	/** Initializes the CPU, AHB and APB buses clocks
	*/
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
				  	  	  |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_MSI;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
	{
		Error_Handler();
	}

	PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_LPTIM1|RCC_PERIPHCLK_USART1|RCC_PERIPHCLK_USART2
				  	  	  |RCC_PERIPHCLK_I2C1|RCC_PERIPHCLK_RTC;
	PeriphClkInit.LptimClockSelection = RCC_LPTIM1CLKSOURCE_LSE;
	PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK2;
	PeriphClkInit.Usart2ClockSelection = RCC_USART2CLKSOURCE_SYSCLK;
	PeriphClkInit.I2c1ClockSelection = RCC_I2C1CLKSOURCE_PCLK1;
	PeriphClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSE;
	if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
	{
		Error_Handler();
	}
}

void Error_Handler(void)
{
	__disable_irq();
	MX_GPIO_Init();
	LOG(LOG_INFOR, "Error");
	while (1){}
}

#ifdef  USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line){while (1){}}
#endif /* USE_FULL_ASSERT */
