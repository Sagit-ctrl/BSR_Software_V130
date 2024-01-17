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
static uint8_t _Cb_Meas_Single(uint8_t event);
static uint8_t _Cb_Meas_Multi(uint8_t event);
static uint8_t _Cb_Set_RTC (uint8_t event);
static uint8_t _Cb_Idle_Handler(uint8_t event);
static uint8_t _Cb_Interrupt(uint8_t event);

void    _Cb_Active_Lora_Tx_Event(void *context);

/* Private typedef -----------------------------------------------------------*/
sEvent_struct sEventAppCom[] =
{
	{ _EVENT_TIMER_START, 		    0, 0, 0, 	    _Cb_Timer_Start },
	{ _EVENT_TIMER_LORA_TX, 		0, 0, 0, 	    _Cb_Timer_Lora_Tx },
	{ _EVENT_UART_DEBUG, 		    0, 0, 5, 	    _Cb_Uart_Debug },
	{ _EVENT_MEAS_SINGLE, 		    0, 0, 100, 	    _Cb_Meas_Single },
	{ _EVENT_MEAS_MULTI, 		    0, 0, 100, 	    _Cb_Meas_Multi },
    { _EVENT_SET_RTC, 				0, 0, 0, 	    _Cb_Set_RTC },
	#ifdef DEVICE_TYPE_STATION
		{ _EVENT_IDLE_HANDLER, 		    0, 0, 1000, 	_Cb_Idle_Handler },
	#else
		{ _EVENT_IDLE_HANDLER, 		    0, 0, 100000, 	_Cb_Idle_Handler },
	#endif
	{ _EVENT_INTERRUPT, 		    0, 0, 0, 	    _Cb_Interrupt },
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
	sModem.TimeDelayTx_u32 *= 1000;
	LOG(LOG_INFOR, "Time delay = %dms", sModem.TimeDelayTx_u32);
}

/* Private function prototypes -----------------------------------------------*/
static uint8_t _Cb_Timer_Start(uint8_t event)
{
	UTIL_TIMER_IRQ_Handler();
	return 1;
}

static uint8_t _Cb_Timer_Lora_Tx(uint8_t event)
{
	UTIL_TIMER_SetPeriod (&TimerLoraTx, sFreqInfor.FreqWakeup_u32 * 1000);
	UTIL_TIMER_Start (&TimerLoraTx);
	USER_Payload_Node_Single(0);
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
//			DCU_Response_AT((uint8_t*)"", 0);
//			DCU_Response_AT(sUartDebug.Data_a8, sUartDebug.Length_u16);
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

static uint8_t _Cb_Meas_Single(uint8_t event)
{
	if (sModem.CountMeasure_u8 < 10)
	{
		switch(sModem.TypeModem_u8)
		{
			case _LORA_NODE_VNA:
				sModem.ValueMeasure_u8 += Get_Vol_VNA();
			case _LORA_NODE_VP:
				sModem.ValueBattery_u8 += Get_Vol_VP();
		}
		sModem.CountMeasure_u8++;
		sEventAppCom[event].e_period = 100;
		fevent_enable(sEventAppCom, event);
	} else
	{
		sModem.ValueMeasure_u8 /= 10;
		fevent_enable(sEventAppPacket, _EVENT_PACKET_SINGLE);
	}
	return 1;
}

static uint8_t _Cb_Meas_Multi(uint8_t event)
{
	if (sModem.CountMeasure_u8 <6)
	{
		sModem.CountMeasure_u8++;
		sEventAppCom[event].e_period = 100;
		fevent_enable(sEventAppCom, event);
	} else if ((sModem.CountMeasure_u8 >= 6) && (sModem.CountMeasure_u8 < 150))
	{
		switch(sModem.TypeModem_u8)
		{
			case _LORA_NODE_VNA:
				sModem.ValueMeasure_u8 = Get_Vol_VNA();
			case _LORA_NODE_VP:
				sModem.ValueMeasure_u8 = Get_Vol_VP();
		}

		*(sModem.strMultiRespond.Data_a8 + sModem.strMultiRespond.Length_u16++) = (uint8_t) (sModem.ValueMeasure_u8 >> 8);
		*(sModem.strMultiRespond.Data_a8 + sModem.strMultiRespond.Length_u16++) = (uint8_t) sModem.ValueMeasure_u8;

		sModem.CountMeasure_u8++;
		sEventAppCom[event].e_period = 100;
		fevent_enable(sEventAppCom, event);
	} else
	{
		fevent_enable(sEventAppPacket, _EVENT_PACKET_MULTI);
		sModem.CountMeasure_u8 = 0;
	}
	return 1;
}

static uint8_t _Cb_Set_RTC (uint8_t event)
{
    UTIL_Set_RTC(sRTCSet);
    fevent_enable(sEventAppCom, _EVENT_IDLE_HANDLER);
	return 1;
}

static uint8_t _Cb_Idle_Handler(uint8_t event)
{
	#ifdef DEVICE_TYPE_STATION
		fevent_enable(sEventAppCom, _EVENT_IDLE_HANDLER);
		LED_TOGGLE(__LED_MODE);
	#else
		LED_TOGGLE(__LED_MODE);
		sModem.CountSleep ++;
		if(sModem.CountSleep <= 100){
			if (sModem.CheckInit == 0){
				if (sModem.CheckJoin == 0)
				{
					USER_Payload_Node_Join(sModem.TimeDelayTx_u32 * DEFAULT_TIME_SINGLE_DELAY);
				}
			}
			fevent_enable(sEventAppCom, event);
			Radio.Rx(RX_TIMEOUT_VALUE_ACTIVE);
		} else
		{
			sModem.CountSleep = 0;
			sModem.Mode_Node = 0;
			UTIL_TIMER_Start(&TimerLoraTx);
		}
	#endif
	return 1;
}

static uint8_t _Cb_Interrupt(uint8_t event)
{
	fevent_enable(sEventAppCom, _EVENT_TIMER_LORA_TX);
	return 1;
}

void _Cb_Active_Lora_Tx_Event(void *context)
{
    fevent_active(sEventAppCom, _EVENT_TIMER_LORA_TX);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    switch(GPIO_Pin)
    {
    #ifdef DEVICE_TYPE_STATION
    #else
       case GPIO_PIN_6:
    	   fevent_enable(sEventAppCom, _EVENT_INTERRUPT);
           break;
        default:
            break;
    #endif
    }
}











