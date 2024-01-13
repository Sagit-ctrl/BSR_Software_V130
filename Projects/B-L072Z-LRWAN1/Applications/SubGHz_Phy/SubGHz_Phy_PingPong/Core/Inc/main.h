#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32l0xx_hal.h"

#ifdef DEVICE_TYPE_STATION
	#define DEBUG_TX_Pin 			GPIO_PIN_2
	#define DEBUG_TX_GPIO_Port 		GPIOA
	#define DEBUG_RX_Pin 			GPIO_PIN_3
	#define DEBUG_RX_GPIO_Port 		GPIOA
	#define LED_BLUE_Pin 			GPIO_PIN_2
	#define LED_BLUE_GPIO_Port 		GPIOB
	#define MCU_TX_Pin 				GPIO_PIN_9
	#define MCU_TX_GPIO_Port 		GPIOA
	#define MCU_RX_Pin 				GPIO_PIN_10
	#define MCU_RX_GPIO_Port 		GPIOA
#else
	#define RTC_INT_Pin 			GPIO_PIN_0
	#define RTC_INT_GPIO_Port 		GPIOA
	#define RTC_INT_EXTI_IRQn 		EXTI0_1_IRQn
	#define ADC_VNA_Pin 			GPIO_PIN_2
	#define ADC_VNA_GPIO_Port 		GPIOA
	#define ADC_VP_Pin 				GPIO_PIN_3
	#define ADC_VP_GPIO_Port 		GPIOA
	#define ADC_BAT_Pin 			GPIO_PIN_4
	#define ADC_BAT_GPIO_Port 		GPIOA
	#define RTC_RST_Pin 			GPIO_PIN_2
	#define RTC_RST_GPIO_Port 		GPIOB
	#define DEBUG_TX_Pin 			GPIO_PIN_9
	#define DEBUG_TX_GPIO_Port 		GPIOA
	#define DEBUG_RX_Pin 			GPIO_PIN_10
	#define DEBUG_RX_GPIO_Port 		GPIOA

	#define LED_GREEN_Pin 			GPIO_PIN_5
	#define LED_GREEN_GPIO_Port 	GPIOB
	#define LED_BLUE_Pin 			GPIO_PIN_6
	#define LED_BLUE_GPIO_Port 		GPIOB
	#define RTC_SCL_Pin 			GPIO_PIN_8
	#define RTC_SCL_GPIO_Port 		GPIOB
	#define RTC_SDA_Pin 			GPIO_PIN_9
	#define RTC_SDA_GPIO_Port 		GPIOB
#endif

void Error_Handler(void);

#define RTC_N_PREDIV_S 10
#define RTC_PREDIV_S ((1<<RTC_N_PREDIV_S)-1)
#define RTC_PREDIV_A ((1<<(15-RTC_N_PREDIV_S))-1)
#define USART_BAUDRATE 115200

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
