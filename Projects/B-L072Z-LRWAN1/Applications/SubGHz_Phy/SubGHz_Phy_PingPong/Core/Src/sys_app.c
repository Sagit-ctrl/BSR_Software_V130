#include <stdio.h>
#include "platform.h"
#include "sys_app.h"
#include "radio_board_if.h"
#include "stm32_seq.h"
#include "stm32_systime.h"

#include "utilities_def.h"
#include "sys_debug.h"

#include "user_lpm.h"
#include "user_rtc.h"

#define MAX_TS_SIZE (int) 16
static void Gpio_PreInit(void);
static void TimestampNow(uint8_t *buff, uint16_t *size);
static void tiny_snprintf_like(char *buf, uint32_t maxsize, const char *strFormat, ...);
void SystemApp_Init(void)
{
	UTIL_TIMER_Init();
	Gpio_PreInit();
	DBG_Disable();
	DBG_ProbesInit();
	UTIL_ADV_TRACE_Init();
	UTIL_ADV_TRACE_RegisterTimeStampFunction(TimestampNow);
	UTIL_ADV_TRACE_SetVerboseLevel(VERBOSE_LEVEL);
	Sx_Board_Bus_Init();
	Sx_Board_IoInit();
	UTIL_LPM_Init();
	#if defined (LOW_POWER_DISABLE) && (LOW_POWER_DISABLE == 1)
		UTIL_LPM_SetStopMode( UTIL_LPM_DISABLE );
	#elif !defined (LOW_POWER_DISABLE)
		#error LOW_POWER_DISABLE not defined
	#endif /* LOW_POWER_DISABLE */
}

void UTIL_SEQ_Idle(void){}

static void TimestampNow(uint8_t *buff, uint16_t *size)
{
	SysTime_t curtime = SysTimeGet();
	tiny_snprintf_like((char *)buff, MAX_TS_SIZE, "%ds%03d:", curtime.Seconds, curtime.SubSeconds);
	*size = strlen((char *)buff);
}

static void Gpio_PreInit(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOH_CLK_ENABLE();

	GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Pin = GPIO_PIN_All & (~(GPIO_PIN_13 | GPIO_PIN_14));
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = GPIO_PIN_All;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
	HAL_GPIO_Init(GPIOH, &GPIO_InitStruct);

	__HAL_RCC_GPIOA_CLK_DISABLE();
	__HAL_RCC_GPIOB_CLK_DISABLE();
	__HAL_RCC_GPIOC_CLK_DISABLE();
	__HAL_RCC_GPIOH_CLK_DISABLE();
}

void UTIL_ADV_TRACE_PreSendHook(void)
{
	UTIL_LPM_SetStopMode(UTIL_LPM_DISABLE);
}

void UTIL_ADV_TRACE_PostSendHook(void)
{
	UTIL_LPM_SetStopMode(UTIL_LPM_ENABLE);
}

static void tiny_snprintf_like(char *buf, uint32_t maxsize, const char *strFormat, ...)
{
	va_list vaArgs;
	va_start(vaArgs, strFormat);
	UTIL_ADV_TRACE_VSNPRINTF(buf, maxsize, strFormat, vaArgs);
	va_end(vaArgs);
}
