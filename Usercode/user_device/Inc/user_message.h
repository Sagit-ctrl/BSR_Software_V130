#ifndef USER_MESSAGE_H
#define USER_MESSAGE_H

#include "user_util.h"

/* Define --------------------------------------------------------------------*/
#define MAX_LENGTH_PAYLOAD      			256
#define MAX_RETRY_SEND_LORA                 0x02          // 0xFF: Send Util Send OK
#define MAX_RETRY_WITHOUT_SKIP              2             // Retry and not skip mess

/* Exported types ------------------------------------------------------------*/
typedef enum {
    _MESS_CONNECT,
	_MESS_SINGLE,
	_MESS_MULTI,
	_MESS_MODE,
	_MESS_RTC,
	_MESS_END,
} eKindMessLora;

typedef uint8_t (*pFunCallBackSend)(int Kind_Send);

typedef struct {
	int 				idMark;
	pFunCallBackSend 	CallBack;
	sData		        sKind;
} structMessTypeSend;

typedef void (*pFunCallBackRecv)(sData *str_Receiv, int16_t Pos);

typedef struct {
	int 			    idMark;
	pFunCallBackRecv	CallBack;
	sData	            sKind;
} structMessTypeReceive;

typedef struct
{
    uint8_t 	aMARK[32];
    sData   	sPayload;
    int8_t  	DataType_u8;
    uint8_t 	Retry_u8[10];
    uint8_t 	MessType_u8[10];
}structMessVariable;

typedef enum eDataDeviceType
{
    _DATA_NONE = 0x00,
	_DATA_JOIN,
	_DATA_ACCEPT,
	_DATA_SINGLE,
	_DATA_MULTI,
	_DATA_MODE,
	_DATA_RTC,
	_DATA_CONFIRM,
}eDataDeviceType_t;

typedef struct
{
	uint8_t TypeResp_u8;
}StructMasterTx;

/* External variables --------------------------------------------------------*/
extern const structMessTypeSend 	sMessSend[];
extern const structMessTypeReceive 	sMessRecv[];
extern structMessVariable 			sMessVar;
extern uint8_t aPAYLOAD[MAX_LENGTH_PAYLOAD];

/* Exported functions prototypes ---------------------------------------------*/
int8_t 			mCheck_Mess_Mark (void);
void 			mMess_Handle_Reset (uint8_t DataType);
uint8_t 		mCallback_Send_Fail (void);
void 			mCallback_Send_OK (void);

#endif /* USER_MESSAGE_H */










