#include "usart_if.h"

extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart1;
uint8_t charRx;

const UTIL_ADV_TRACE_Driver_s UTIL_TraceDriver =
{
	vcom_Init,
	vcom_DeInit,
	vcom_ReceiveInit,
	vcom_Trace_DMA,
};

static void (*TxCpltCallback)(void *);
static void (*RxCpltCallback)(uint8_t *rxChar, uint16_t size, uint8_t error);

UTIL_ADV_TRACE_Status_t vcom_Init(void (*cb)(void *))
{
	TxCpltCallback = cb;
	#ifdef DEVICE_TYPE_STATION
		MX_USART1_UART_Init();
		MX_USART2_UART_Init();
	#else
		MX_USART1_UART_Init();
	#endif
	return UTIL_ADV_TRACE_OK;
}

UTIL_ADV_TRACE_Status_t vcom_DeInit(void)
{
#ifdef DEVICE_TYPE_STATION
	__HAL_RCC_USART1_FORCE_RESET();
	__HAL_RCC_USART1_RELEASE_RESET();
	HAL_UART_MspDeInit(&huart1);
	__HAL_RCC_USART2_FORCE_RESET();
	__HAL_RCC_USART2_RELEASE_RESET();
	HAL_UART_MspDeInit(&huart2);
#else
	__HAL_RCC_USART1_FORCE_RESET();
	__HAL_RCC_USART1_RELEASE_RESET();
	HAL_UART_MspDeInit(&huart1);
#endif
	return UTIL_ADV_TRACE_OK;
}

void vcom_Trace(uint8_t *p_data, uint16_t size)
{
	#ifdef DEVICE_TYPE_STATION
		HAL_UART_Transmit(&huart1, p_data, size, 1000);
		HAL_UART_Transmit(&huart2, p_data, size, 1000);
	#else
		HAL_UART_Transmit(&huart1, p_data, size, 1000);
	#endif
}

UTIL_ADV_TRACE_Status_t vcom_Trace_DMA(uint8_t *p_data, uint16_t size)
{
	#ifdef DEVICE_TYPE_STATION
		HAL_UART_Transmit(&huart1, p_data, size, 1000);
		HAL_UART_Transmit(&huart2, p_data, size, 1000);
	#else
		HAL_UART_Transmit(&huart1, p_data, size, 1000);
	#endif
	TxCpltCallback(NULL);
	return UTIL_ADV_TRACE_OK;
}

UTIL_ADV_TRACE_Status_t vcom_ReceiveInit(void (*RxCb)(uint8_t *rxChar, uint16_t size, uint8_t error))
{
	RxCpltCallback = RxCb;
	#ifdef DEVICE_TYPE_STATION
		while (__HAL_UART_GET_FLAG(&huart1, USART_ISR_BUSY) == SET);
		while (__HAL_UART_GET_FLAG(&huart1, USART_ISR_REACK) == RESET);
		HAL_UART_Receive_IT(&huart1, &charRx, 1);
		while (__HAL_UART_GET_FLAG(&huart2, USART_ISR_BUSY) == SET);
		while (__HAL_UART_GET_FLAG(&huart2, USART_ISR_REACK) == RESET);
		HAL_UART_Receive_IT(&huart2, &charRx, 1);
	#else
		while (__HAL_UART_GET_FLAG(&huart1, USART_ISR_BUSY) == SET);
		while (__HAL_UART_GET_FLAG(&huart1, USART_ISR_REACK) == RESET);
		HAL_UART_Receive_IT(&huart1, &charRx, 1);
	#endif

	return UTIL_ADV_TRACE_OK;
}

void vcom_Resume(void)
{

	if (HAL_UART_Init(&huart1) != HAL_OK)
	{
		Error_Handler();
	}
	if (HAL_UART_Init(&huart2) != HAL_OK)
	{
		Error_Handler();
	}
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart2)
{
}
