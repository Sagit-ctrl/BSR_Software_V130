#include "user_common.h"
#include "user_uart.h"
#include "user_define.h"
#include "user_modem.h"
#include "adc.h"
#include "gpio.h"
#include "i2c.h"
#include "user_lpm.h"
#include "user_timer.h"
#include "user_payload.h"
#include "radio.h"

/* Private function prototypes -----------------------------------------------*/
static uint8_t _Cb_Timer_Start(uint8_t event);
static uint8_t _Cb_Timer_Lora_Tx(uint8_t event);
static uint8_t _Cb_Uart_Debug(uint8_t event);
static uint8_t _Cb_Idle_Handler(uint8_t event);

void    _Cb_Active_Lora_Tx_Event(void *context);

/* Private typedef -----------------------------------------------------------*/
sEvent_struct sEventAppCom[] =
{
	{ _EVENT_TIMER_START, 		    0, 0, 0, 	    _Cb_Timer_Start },
	{ _EVENT_TIMER_LORA_TX, 		0, 0, 0, 	    _Cb_Timer_Lora_Tx },
	{ _EVENT_UART_DEBUG, 		    0, 0, 5, 	    _Cb_Uart_Debug },
	#ifdef DEVICE_TYPE_STATION
		{ _EVENT_IDLE_HANDLER, 		    0, 0, 1000, 	_Cb_Idle_Handler },
	#else
		{ _EVENT_IDLE_HANDLER, 		    0, 0, 100000, 	_Cb_Idle_Handler },
	#endif
};

UTIL_TIMER_Object_t TimerLoraTx;

/* Exported functions --------------------------------------------------------*/
void AppCom_Init (void)
{
	#ifdef DEVICE_TYPE_STATION
    	sModem.TypeModem_u8 = _LORA_STATION;
	#else
    	sModem.TypeModem_u8 = _LORA_NODE_VP;
	#endif
    pModemProcessIRQTimer = AppCom_IRQ_Timer_CallBack;
    sLPMFeatureHandler = &sModemLPMHandler;
    AppCom_Cacul_Random_Delay();
    LOG_Array(LOG_INFOR, sModem.sDCU_id.Data_a8, sModem.sDCU_id.Length_u16, "DCU ID:");
    LOG_Array(LOG_INFOR, sModem.sNET_id.Data_a8, sModem.sNET_id.Length_u16, "NET ID:");
}

void AppCom_IRQ_Timer_CallBack (void)
{
    fevent_active(sEventAppCom, _EVENT_TIMER_START);
}

uint8_t AppCom_Task(void)
{
	uint8_t i = 0;
	uint8_t Result = 0;
	for (i = 0; i < _EVENT_END_COMM; i++)
	{
		if (sEventAppCom[i].e_status == 1)
		{
            Result = 1;
			if ((sEventAppCom[i].e_systick == 0) ||
					((HAL_GetTick() - sEventAppCom[i].e_systick)  >=  sEventAppCom[i].e_period))
			{
                sEventAppCom[i].e_status = 0;  //Disable event
				sEventAppCom[i].e_systick = HAL_GetTick();
				sEventAppCom[i].e_function_handler(i);
			}
		}
	}
	return Result;
}

void AppCom_Cacul_Random_Delay (void)
{
    uint16_t Index = sModem.sDCU_id.Length_u16 - 1;
    sModem.TimeDelayTx_u32 = (*(sModem.sDCU_id.Data_a8 + Index) - 0x30);
	sModem.TimeDelayTx_u32 = sModem.TimeDelayTx_u32 % sFreqInfor.FreqWakeup_u32;
	if(sModem.TimeDelayTx_u32 == 0){
		sModem.TimeDelayTx_u32 += 10;
	}
	sModem.TimeDelayTx_u32 *= 1000;
	sModem.TimeDelaySingle_u32 = sModem.TimeDelayTx_u32 * DEFAULT_TIME_SINGLE_DELAY;
	sModem.TimeDelayCalib_u32 = sModem.TimeDelayTx_u32 * DEFAULT_TIME_CALIB_DELAY;
	sModem.TimeDelayNetwork_u32 = (*(sModem.sNET_id.Data_a8 + Index) - 0x30) * 1000 * DEFAULT_TIME_NETWORK_DELAY;
	LOG(LOG_INFOR, "Network delay: %d", sModem.TimeDelayNetwork_u32);
}

/* Private function prototypes -----------------------------------------------*/
static uint8_t _Cb_Timer_Start(uint8_t event)
{
	UTIL_TIMER_IRQ_Handler();
	return 1;
}

static uint8_t _Cb_Timer_Lora_Tx(uint8_t event)
{
	#ifdef DEVICE_TYPE_STATION
		sModem.Mode = _MODE_SLEEP;
	#else
		UTIL_TIMER_Stop (&TimerLoraTx);
		UTIL_TIMER_SetPeriod (&TimerLoraTx, sFreqInfor.FreqWakeup_u32 * 1000);
		UTIL_TIMER_Start (&TimerLoraTx);
		USER_Payload_Node_Single(sModem.TimeDelaySingle_u32);
	#endif
    return 1;
}

static uint8_t _Cb_Uart_Debug(uint8_t event)
{
	static uint8_t  MarkFirstRecvUart = 0;
	static uint16_t LastLengthRecv = 0;
	if (MarkFirstRecvUart == 0)
	{
		MarkFirstRecvUart = 1;
		LastLengthRecv = sUartDebug.Length_u16;
		fevent_enable(sEventAppCom, event);
	} else
	{
		if (sUartDebug.Length_u16 == LastLengthRecv)
		{
			MarkFirstRecvUart = 0;
			Check_AT_User(&sUartDebug);
			Reset_Buff(&sUartDebug);
		} else
		{
			LastLengthRecv = sUartDebug.Length_u16;
			fevent_enable(sEventAppCom, event);
		}
	}
	return 1;
}

static uint8_t _Cb_Idle_Handler(uint8_t event)
{
	#ifdef DEVICE_TYPE_STATION
		fevent_enable(sEventAppCom, _EVENT_IDLE_HANDLER);
		LED_TOGGLE(__LED_MODE);
	#else
		if (sModem.CheckInit == 0){
			if (sModem.CheckJoin == 0)
			{
				sModem.CountSleep ++;
				if(sModem.CountSleep <= 2){
					USER_Payload_Node_Join(sModem.TimeDelaySingle_u32);
					fevent_enable(sEventAppCom, event);
				} else
				{
					LED_OFF(__LED_MODE);
					sModem.CheckInit = 1;
					sModem.CheckJoin = 1;
					sModem.CountSleep = 0;
					sModem.Mode = 0;
					USER_Payload_Node_Mode(sModem.TimeDelaySingle_u32);
					UTIL_TIMER_SetPeriod (&TimerLoraTx, sFreqInfor.FreqWakeup_u32 * 1000 - sModem.TimeDelaySingle_u32);
					UTIL_TIMER_Start(&TimerLoraTx);
				}
			} else {
				sModem.CountSleep ++;
				if(sModem.CountSleep < 100){
					LED_TOGGLE(__LED_MODE);
					Radio.Rx(RX_TIMEOUT_VALUE_ACTIVE);
					fevent_enable(sEventAppCom, event);
				} else
				{
					LED_OFF(__LED_MODE);
					sModem.CheckInit = 1;
					sModem.CheckJoin = 1;
					sModem.CountSleep = 0;
					sModem.Mode = 0;
					Radio.Sleep();
					USER_Payload_Node_Mode(sModem.TimeDelaySingle_u32);
					UTIL_TIMER_SetPeriod (&TimerLoraTx, sFreqInfor.FreqWakeup_u32 * 1000 - sModem.TimeDelaySingle_u32);
					UTIL_TIMER_Start(&TimerLoraTx);
				}
			}
		}
	#endif
	return 1;
}

void _Cb_Active_Lora_Tx_Event(void *context)
{
	 fevent_active(sEventAppCom, _EVENT_TIMER_LORA_TX);
}









