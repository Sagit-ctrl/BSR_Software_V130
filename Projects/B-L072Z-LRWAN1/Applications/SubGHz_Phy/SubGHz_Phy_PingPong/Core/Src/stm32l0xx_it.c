#include "main.h"
#include "stm32l0xx_it.h"
#include "radio_board_if.h"

#include "user_util.h"
#include "user_define.h"

extern RTC_HandleTypeDef hrtc;
extern DMA_HandleTypeDef hdma_usart1_tx;
extern UART_HandleTypeDef huart1;
extern DMA_HandleTypeDef hdma_usart2_tx;
extern UART_HandleTypeDef huart2;

void NMI_Handler(void){ while (1){}}
void HardFault_Handler(void){ while (1){}}
void MemManage_Handler(void){ while (1){}}
void BusFault_Handler(void){ while (1){}}
void UsageFault_Handler(void){ while (1){}}
void SVC_Handler(void){}
void DebugMon_Handler(void){}
void PendSV_Handler(void){}
void SysTick_Handler(void)
{
	RtCountSystick_u32++;
	HAL_IncTick();
}

void EXTI0_1_IRQHandler(void)
{
	#if (defined(CMWX1ZZABZ0XX))
		HAL_EXTI_IRQHandler(&H_EXTI_0);
		HAL_EXTI_IRQHandler(&H_EXTI_1);
	#endif
}

void EXTI2_3_IRQHandler(void)
{
	#if (defined(SX1276MB1MAS) | defined(SX1276MB1LAS) | defined(SX1272MB2DAS))
		HAL_EXTI_IRQHandler(&H_EXTI_3);
	#endif
}

void EXTI4_15_IRQHandler(void)
{
	HAL_EXTI_IRQHandler(&H_EXTI_4);

	#if (defined(SX1276MB1MAS) | defined(SX1276MB1LAS) | defined(SX1272MB2DAS))
		HAL_EXTI_IRQHandler(&H_EXTI_5);
	#endif

	#if (defined(SX1276MB1MAS) | defined(SX1276MB1LAS) | defined(SX1272MB2DAS))
		HAL_EXTI_IRQHandler(&H_EXTI_10);
	#endif

	#if (defined(CMWX1ZZABZ0XX))
		HAL_EXTI_IRQHandler(&H_EXTI_13);
	#endif

	HAL_GPIO_EXTI_IRQHandler( GPIO_PIN_4 );
	HAL_GPIO_EXTI_IRQHandler( GPIO_PIN_5 );
	HAL_GPIO_EXTI_IRQHandler( GPIO_PIN_6 );
	HAL_GPIO_EXTI_IRQHandler( GPIO_PIN_7 );
	HAL_GPIO_EXTI_IRQHandler( GPIO_PIN_8 );
	HAL_GPIO_EXTI_IRQHandler( GPIO_PIN_9 );
	HAL_GPIO_EXTI_IRQHandler( GPIO_PIN_10 );
	HAL_GPIO_EXTI_IRQHandler( GPIO_PIN_11 );
	HAL_GPIO_EXTI_IRQHandler( GPIO_PIN_12 );
	HAL_GPIO_EXTI_IRQHandler( GPIO_PIN_13 );
	HAL_GPIO_EXTI_IRQHandler( GPIO_PIN_14 );
	HAL_GPIO_EXTI_IRQHandler( GPIO_PIN_15 );
}

void DMA1_Channel2_3_IRQHandler(void)
{
	HAL_DMA_IRQHandler(&hdma_usart1_tx);
}

void DMA1_Channel4_5_6_7_IRQHandler(void)
{
	HAL_DMA_IRQHandler(&hdma_usart2_tx);
}

void USART1_IRQHandler(void)
{
	#ifdef DEVICE_TYPE_STATION
		uint8_t	TempRecieve_u8 = 0;
		TempRecieve_u8 = (uint8_t)(huart2.Instance->RDR & 0x00FF);
		*(sUartDebug.Data_a8 + sUartDebug.Length_u16++) = TempRecieve_u8;
		if (sUartDebug.Length_u16 > (sizeof (UartDebugBuff) - 1))
		sUartDebug.Length_u16 = 0;
		sEventAppCom[_EVENT_UART_DEBUG].e_status = 1;
	#else
		uint8_t	TempRecieve_u8 = 0;
		TempRecieve_u8 = (uint8_t)(huart1.Instance->RDR & 0x00FF);
		*(sUartDebug.Data_a8 + sUartDebug.Length_u16++) = TempRecieve_u8;
		if (sUartDebug.Length_u16 > (sizeof (UartDebugBuff) - 1))
		sUartDebug.Length_u16 = 0;
		sEventAppCom[_EVENT_UART_DEBUG].e_status = 1;
	#endif
	HAL_UART_IRQHandler(&huart1);
}

void USART2_IRQHandler(void)
{
	#ifdef DEVICE_TYPE_STATION
		uint8_t	TempRecieve_u8 = 0;
		TempRecieve_u8 = (uint8_t)(huart2.Instance->RDR & 0x00FF);
		*(sUartDebug.Data_a8 + sUartDebug.Length_u16++) = TempRecieve_u8;
		if (sUartDebug.Length_u16 > (sizeof (UartDebugBuff) - 1))
		sUartDebug.Length_u16 = 0;
		sEventAppCom[_EVENT_UART_DEBUG].e_status = 1;
	#else
	#endif
	HAL_UART_IRQHandler(&huart2);
}

void RTC_IRQHandler(void)
{
	HAL_RTC_AlarmIRQHandler(&hrtc);
}
