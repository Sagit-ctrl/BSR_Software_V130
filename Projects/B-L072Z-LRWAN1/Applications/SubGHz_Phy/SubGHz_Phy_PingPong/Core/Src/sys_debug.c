#include "platform.h"
#include "sys_debug.h"

void DBG_Disable(void)
{
	DBG_ConfigForLpm(1);
}

void DBG_ConfigForLpm(uint8_t enableDbg)
{
	uint8_t enable_dbg = enableDbg;
	#if defined (DEBUGGER_ENABLED) && ( DEBUGGER_ENABLED == 0 )
		enable_dbg = 0;
	#elif !defined (DEBUGGER_ENABLED)
		#error "DEBUGGER_ENABLED not defined or out of range <0,1>"
	#endif /* DEBUGGER_OFF */

	if (enable_dbg == 1)
	{
		__HAL_RCC_DBGMCU_CLK_ENABLE();

		HAL_DBGMCU_EnableDBGSleepMode();
		HAL_DBGMCU_EnableDBGStopMode();
		HAL_DBGMCU_EnableDBGStandbyMode();
	}
	else
	{
		__HAL_RCC_DBGMCU_CLK_ENABLE();
		HAL_DBGMCU_DisableDBGSleepMode();
		HAL_DBGMCU_DisableDBGStopMode();
		HAL_DBGMCU_DisableDBGStandbyMode();
		__HAL_RCC_DBGMCU_CLK_DISABLE();
	}
}

void DBG_ProbesInit(void)
{
	#if defined (PROBE_PINS_ENABLED) && ( PROBE_PINS_ENABLED == 1 )
		GPIO_InitTypeDef  GPIO_InitStruct = {0};

		/* Configure the GPIO pin */
		GPIO_InitStruct.Mode   = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Pull   = GPIO_PULLUP;
		GPIO_InitStruct.Speed  = GPIO_SPEED_FREQ_VERY_HIGH;

		/* Enable the GPIO Clock */
		PROBE_LINE1_CLK_ENABLE();
		PROBE_LINE2_CLK_ENABLE();
		PROBE_LINE3_CLK_ENABLE();
		PROBE_LINE4_CLK_ENABLE();

		GPIO_InitStruct.Pin    = PROBE_LINE1_PIN;
		HAL_GPIO_Init(PROBE_LINE1_PORT, &GPIO_InitStruct);
		GPIO_InitStruct.Pin    = PROBE_LINE2_PIN;
		HAL_GPIO_Init(PROBE_LINE2_PORT, &GPIO_InitStruct);
		GPIO_InitStruct.Pin    = PROBE_LINE3_PIN;
		HAL_GPIO_Init(PROBE_LINE3_PORT, &GPIO_InitStruct);
		GPIO_InitStruct.Pin    = PROBE_LINE4_PIN;
		HAL_GPIO_Init(PROBE_LINE4_PORT, &GPIO_InitStruct);

		/* Reset probe Pins */
		HAL_GPIO_WritePin(PROBE_LINE1_PORT, PROBE_LINE1_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(PROBE_LINE2_PORT, PROBE_LINE2_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(PROBE_LINE3_PORT, PROBE_LINE3_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(PROBE_LINE4_PORT, PROBE_LINE4_PIN, GPIO_PIN_RESET);

	#elif !defined (PROBE_PINS_ENABLED)
		#error "PROBE_PINS_ENABLED not defined or out of range <0,1>"
	#endif /* PROBE_PINS_ENABLED */
}
