#ifndef INC_USER_PACKET_H_
#define INC_USER_PACKET_H_

#include "user_internal_mem.h"
#include "user_event_drive.h"
#include "user_util.h"

/* Define --------------------------------------------------------------------*/
#define  USING_APP_PACKET

/* Exported types ------------------------------------------------------------*/
typedef enum
{
    _EVENT_ENTRY_PACKET,
	_EVENT_PACKET_SINGLE,
	_EVENT_PACKET_MULTI,
	_EVENT_PACKET_MODE,
	_EVENT_PACKET_RTC_MODE,
	_EVENT_END_PACKET,
}sTypeEventWM;

/* External variables --------------------------------------------------------*/
extern sEvent_struct sEventAppPacket[];

/* Exported functions prototypes ---------------------------------------------*/
void        AppPacket_Init (void);
uint8_t     AppPacket_Task(void);

void 		Packet_Single_Message (void);
void 		Packet_Multiple_Message (void);
void 		Packet_Mode_Message (void);
void 		Packet_RTC_Mode_Message (void);

#endif /* INC_USER_PACKET_H_ */
