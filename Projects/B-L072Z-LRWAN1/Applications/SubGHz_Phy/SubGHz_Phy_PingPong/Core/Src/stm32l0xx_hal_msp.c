#include "main.h"
#include "sys_debug.h"

#define ENABLE_FAST_WAKEUP
void HAL_MspInit(void)
{
	__HAL_RCC_PWR_CLK_ENABLE();
	HAL_PWR_DisablePVD();
	HAL_PWREx_EnableUltraLowPower();
	__HAL_FLASH_SLEEP_POWERDOWN_ENABLE();
	DBG(__HAL_FLASH_SLEEP_POWERDOWN_DISABLE(););

	#ifdef ENABLE_FAST_WAKEUP
		HAL_PWREx_EnableFastWakeUp();
	#else
		HAL_PWREx_DisableFastWakeUp();
	#endif
}
