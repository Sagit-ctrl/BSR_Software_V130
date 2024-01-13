#ifndef INC_USER_COMMON_H_
#define INC_USER_COMMON_H_

#include "user_event_drive.h"
#include "user_timer.h"
#include "user_util.h"

typedef enum
{
	_EVENT_TIMER_START = 0,
    _EVENT_TIMER_LORA_TX,
	_EVENT_UART_DEBUG,
	_EVENT_MEAS_SINGLE,
	_EVENT_MEAS_MULTI,
    _EVENT_SET_RTC,
	_EVENT_IDLE_HANDLER,
	_EVENT_INTERRUPT,
	_EVENT_END_COMM,
}eKindEventAppMain;

extern sEvent_struct sEventAppCom[];
extern UTIL_TIMER_Object_t TimerLoraTx;
extern void _Cb_Active_Lora_Tx_Event(void *context);

/*=============Function=======================*/
void        AppCom_Init (void);
void 		AppCom_Start (void);
void 		AppCom_IRQ_Timer_CallBack (void);
uint8_t     AppCom_Task (void);
void 		AppCom_Cacul_Random_Delay (void);

#endif /* INC_USER_COMMON_H_ */
