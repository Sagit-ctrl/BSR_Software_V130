#include "user_main.h"
#include "user_payload.h"
#include "user_define.h"
#include "i2c.h"
#include "radio.h"

/*--- Version FW cua thiet bi -------*/
#ifdef DEVICE_TYPE_STATION
    sData   sFirmVersion = {(uint8_t *) "SVMM_LORA_GW_V1_1_0", 19};
#else
    sData   sFirmVersion = {(uint8_t *) "SVWM_LORA_NO_V1_1_0", 19};
#endif

/* Exported functions --------------------------------------------------------*/
void SysApp_Init (void)
{
	MX_GPIO_Init();

	#ifdef DEVICE_TYPE_STATION
		MX_USART1_UART_Init();
		MX_USART2_UART_Init();
	#else
		MX_USART1_UART_Init();
		MX_ADC_Init();
		MX_I2C1_Init();
	#endif

	#ifdef USING_APP_LORA
		AppLora_Init ();
	#endif

	Get_RTC();
	UTIL_LPM_Init();

	Init_Uart_Module();
	Init_Memory_Infor();
	AppCom_Init();

	#ifdef USING_APP_PACKET
		AppPacket_Init();
	#endif
}

void SysApp_Start(void)
{
	LOG(LOG_DEBUG, "Main task start");
	LOG(LOG_TRANS, "NETID: ");
	LOG_Array(LOG_INFOR, sModem.sNET_id.Data_a8, sModem.sNET_id.Length_u16);
	LOG(LOG_TRANS, "DCUID: ");
	LOG_Array(LOG_INFOR, sModem.sDCU_id.Data_a8, sModem.sDCU_id.Length_u16);

	UTIL_TIMER_Create(&TimerLoraTx,  0xFFFFFFFFU, UTIL_TIMER_ONESHOT, _Cb_Active_Lora_Tx_Event, NULL);
	UTIL_TIMER_SetPeriod (&TimerLoraTx, sFreqInfor.FreqWakeup_u32 * 1000);
	#ifdef DEVICE_TYPE_STATION
		HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, GPIO_PIN_SET);
	#else
		USER_Payload_Node_Join(sModem.TimeDelayTx_u32 * DEFAULT_TIME_SINGLE_DELAY);
//		UTIL_TIMER_Start (&TimerLoraTx);
	#endif
}

void Main_Task (void)
{
    uint8_t TaskStatus_u8 = 0;

    SysApp_Init();
    SysApp_Start();
	#ifdef DEVICE_TYPE_STATION
		fevent_enable(sEventAppCom, _EVENT_IDLE_HANDLER);
		LED_OFF(__LED_MODE);
	#else
		LED_OFF(__LED_MODE);
		LED_OFF(__LED_MEASURE);
		fevent_enable(sEventAppCom, _EVENT_IDLE_HANDLER);
	#endif

	for (;;)
	{
		TaskStatus_u8 = 0;

		TaskStatus_u8 |= AppCom_Task();

		#ifdef USING_APP_LORA
			TaskStatus_u8 |= AppLora_Task();
		#endif

		#ifdef USING_APP_PACKET
			TaskStatus_u8 |= AppPacket_Task();
		#endif

		#ifdef DEVICE_TYPE_STATION
		#else

			if ((TaskStatus_u8 == 0) && (sModem.Mode_Node == 0))
			{
//				LOG(LOG_DEBUG, "Low power mode");
				UTIL_LPM_SetStopMode((UTIL_LPM_State_t) LPM_FALSE);
				UTIL_LPM_EnterLowPower();
			}
		#endif
	}
}
