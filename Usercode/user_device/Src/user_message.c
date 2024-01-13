#include "user_message.h"

#include "radio.h"

#include "user_internal_mem.h"
#include "user_define.h"

/* Private function prototypes -----------------------------------------------*/
static uint8_t _mDATA_SINGLE(int Kind_Send);
static uint8_t _mDATA_MULTI(int Kind_Send);
static uint8_t _mDATA_MODE(int Kind_Send);
static uint8_t _mDATA_RTC_MODE(int Kind_Send);

/* External variables --------------------------------------------------------*/
const structMessTypeSend     sMessSend[] =
{
    { _MESS_CONNECT,			    NULL,           				{NULL}},
    { _MESS_SINGLE,				    _mDATA_SINGLE,				    {NULL}},
    { _MESS_MULTI,				    _mDATA_MULTI,				    {NULL}},
    { _MESS_MODE,				    _mDATA_MODE,				    {NULL}},
	{ _MESS_RTC, 					_mDATA_RTC_MODE,                {NULL}},
    { _MESS_END,				    NULL,				            {NULL}},
};

const structMessTypeReceive	sMessRecv[] =
{
    {_MESS_END,						NULL,							{NULL}},
};

uint8_t aPAYLOAD[MAX_LENGTH_PAYLOAD];

structMessVariable 			sMessVar =
{
    .sPayload = {&aPAYLOAD[0], 0},
};

/* Private function prototypes -----------------------------------------------*/
static uint8_t _mDATA_SINGLE(int Kind_Send)
{
	uint16_t    i = 0;
	uint8_t     IndexMess = 0;
	uint16_t    IndexRead = 0;
	uint8_t     TempCrC = 0;

	sMessVar.sPayload.Data_a8 = aPAYLOAD;
	sMessVar.sPayload.Length_u16 = 0;

	sRecSingle.CountMessPacket_u16 = 0;
	while (sRecSingle.CountMessPacket_u16 < MAX_MESS_IN_PACKET)
	{
		IndexRead = (sRecSingle.IndexSend_u16 + sRecSingle.CountMessPacket_u16) % sRecSingle.MaxRecord_u16;
		if (IndexRead == sRecSingle.IndexSave_u16)
			break;
		if (Flash_Read_Record_Without_Index ((uint32_t)(sRecSingle.AddStart_u32 + sRecSingle.SizeRecord_u16 * IndexRead), &sMessVar.sPayload) == 1)
			IndexMess++;
		sRecSingle.CountMessPacket_u16++;
		break;
	}

	if (IndexMess != 0)
	{
		if (IndexMess > 1)
		{
			sMessVar.sPayload.Length_u16++;
			for (i = 0; i < (sMessVar.sPayload.Length_u16 - 1); i++)
				TempCrC ^= *(sMessVar.sPayload.Data_a8 + i);
			*(sMessVar.sPayload.Data_a8 + sMessVar.sPayload.Length_u16 - 1) = TempCrC;
		}
		return 1;
	}

	if (sRecSingle.CountMessPacket_u16 != 0)
	{
		sRecSingle.IndexSend_u16 = (sRecSingle.IndexSend_u16 + sRecSingle.CountMessPacket_u16) % sRecSingle.MaxRecord_u16;
		Flash_Save_Index(sRecSingle.AddIndexSend_u32, sRecSingle.IndexSend_u16);
		sRecSingle.CountMessPacket_u16 = 0;
	}
	return 0;
}

static uint8_t _mDATA_MULTI(int Kind_Send)
{
    uint16_t    i = 0;
    uint8_t     IndexMess = 0;
    uint16_t    IndexRead = 0;
    uint8_t     TempCrC = 0;

	APP_LOG(TS_OFF, VLEVEL_L, "user_message.c: _mDATA_MULTI\n\r");
    sMessVar.sPayload.Data_a8 = aPAYLOAD;
    sMessVar.sPayload.Length_u16 = 0;

	sRecMultiple.CountMessPacket_u16 = 0;
    while (sRecMultiple.CountMessPacket_u16 < MAX_MESS_IN_PACKET)
    {
        IndexRead = (sRecMultiple.IndexSend_u16 + sRecMultiple.CountMessPacket_u16) % sRecMultiple.MaxRecord_u16;
    	APP_LOG(TS_OFF, VLEVEL_L, "user_message.c: _mDATA_MULTI: IndexSend: %02d\n\r", sRecMultiple.IndexSend_u16);
    	APP_LOG(TS_OFF, VLEVEL_L, "user_message.c: _mDATA_MULTI: IndexSave: %02d\n\r", sRecMultiple.IndexSave_u16);
    	APP_LOG(TS_OFF, VLEVEL_L, "user_message.c: _mDATA_MULTI: IndexRead: %02d\n\r", IndexRead);
        if (IndexRead == sRecMultiple.IndexSave_u16)
        {
        	break;
        }
        if (Flash_Read_Record_Without_Index ((uint32_t)(sRecMultiple.AddStart_u32 + sRecMultiple.SizeRecord_u16 * IndexRead), &sMessVar.sPayload) == 1)
        {
        	APP_LOG(TS_OFF, VLEVEL_L, "user_message.c: _mDATA_MULTI: IndexMess++\n\r");
        	IndexMess++;
        }
        sRecMultiple.CountMessPacket_u16++;
        break;
    }

    if (IndexMess != 0)
    {
        if (IndexMess > 1)
        {
            sMessVar.sPayload.Length_u16++;
            for (i = 0; i < (sMessVar.sPayload.Length_u16 - 1); i++)
                TempCrC ^= *(sMessVar.sPayload.Data_a8 + i);
            *(sMessVar.sPayload.Data_a8 + sMessVar.sPayload.Length_u16 - 1) = TempCrC;
        }
        return 1;
    }

    if (sRecMultiple.CountMessPacket_u16 != 0)
    {
    	sRecMultiple.IndexSend_u16 = (sRecMultiple.IndexSend_u16 + sRecMultiple.CountMessPacket_u16) % sRecMultiple.MaxRecord_u16;
        Flash_Save_Index(sRecMultiple.AddIndexSend_u32, sRecMultiple.IndexSend_u16);
        sRecMultiple.CountMessPacket_u16 = 0;
    }
    return 0;
}

static uint8_t _mDATA_MODE(int Kind_Send)
{
	uint16_t    i = 0;
	uint8_t     IndexMess = 0;
	uint16_t    IndexRead = 0;
	uint8_t     TempCrC = 0;

	sMessVar.sPayload.Data_a8 = aPAYLOAD;
	sMessVar.sPayload.Length_u16 = 0;

	sRecMessage.CountMessPacket_u16 = 0;
	while (sRecMessage.CountMessPacket_u16 < MAX_MESS_IN_PACKET)
	{
		IndexRead = (sRecMessage.IndexSend_u16 + sRecMessage.CountMessPacket_u16) % sRecMessage.MaxRecord_u16;
		if (IndexRead == sRecMessage.IndexSave_u16)
			break;
		if (Flash_Read_Record_Without_Index ((uint32_t)(sRecMessage.AddStart_u32 + sRecMessage.SizeRecord_u16 * IndexRead), &sMessVar.sPayload) == 1)
			IndexMess++;
		sRecMessage.CountMessPacket_u16++;
		break;
	}

	if (IndexMess != 0)
	{
		if (IndexMess > 1)
		{
			sMessVar.sPayload.Length_u16++;
			for (i = 0; i < (sMessVar.sPayload.Length_u16 - 1); i++)
				TempCrC ^= *(sMessVar.sPayload.Data_a8 + i);
			*(sMessVar.sPayload.Data_a8 + sMessVar.sPayload.Length_u16 - 1) = TempCrC;
		}
		return 1;
	}

	if (sRecMessage.CountMessPacket_u16 != 0)
	{
		sRecMessage.IndexSend_u16 = (sRecMessage.IndexSend_u16 + sRecMessage.CountMessPacket_u16) % sRecMessage.MaxRecord_u16;
		Flash_Save_Index(sRecMessage.AddIndexSend_u32, sRecMessage.IndexSend_u16);
		sRecMessage.CountMessPacket_u16 = 0;
	}
	return 0;
}

static uint8_t _mDATA_RTC_MODE(int Kind_Send)
{
	uint16_t    i = 0;
	uint8_t     IndexMess = 0;
	uint16_t    IndexRead = 0;
	uint8_t     TempCrC = 0;

	sMessVar.sPayload.Data_a8 = aPAYLOAD;
	sMessVar.sPayload.Length_u16 = 0;

	sRecMessage.CountMessPacket_u16 = 0;
	while (sRecMessage.CountMessPacket_u16 < MAX_MESS_IN_PACKET)
	{
		IndexRead = (sRecMessage.IndexSend_u16 + sRecMessage.CountMessPacket_u16) % sRecMessage.MaxRecord_u16;
		if (IndexRead == sRecMessage.IndexSave_u16)
			break;
		if (Flash_Read_Record_Without_Index ((uint32_t)(sRecMessage.AddStart_u32 + sRecMessage.SizeRecord_u16 * IndexRead), &sMessVar.sPayload) == 1)
			IndexMess++;
		sRecMessage.CountMessPacket_u16++;
		break;
	}

	if (IndexMess != 0)
	{
		if (IndexMess > 1)
		{
			sMessVar.sPayload.Length_u16++;
			for (i = 0; i < (sMessVar.sPayload.Length_u16 - 1); i++)
				TempCrC ^= *(sMessVar.sPayload.Data_a8 + i);
			*(sMessVar.sPayload.Data_a8 + sMessVar.sPayload.Length_u16 - 1) = TempCrC;
		}
		return 1;
	}

	if (sRecMessage.CountMessPacket_u16 != 0)
	{
		sRecMessage.IndexSend_u16 = (sRecMessage.IndexSend_u16 + sRecMessage.CountMessPacket_u16) % sRecMessage.MaxRecord_u16;
		Flash_Save_Index(sRecMessage.AddIndexSend_u32, sRecMessage.IndexSend_u16);
		sRecMessage.CountMessPacket_u16 = 0;
	}
	return 0;
}

/* Exported functions --------------------------------------------------------*/
int8_t mCheck_Mess_Mark (void)
{
    int8_t i = 0;
    for (i = _MESS_CONNECT; i < _MESS_END; i++)
    {
        if (sMessVar.aMARK[i] == TRUE)
        {
            if (sMessSend[i].CallBack != NULL)
            {
                if (sMessSend[i].CallBack(i) == TRUE)
                {
                    sMessVar.aMARK[i] = FALSE;
                    return i;
                }
            } else
            {
                sMessVar.aMARK[i] = FALSE;
            }
        }
    }
    return _MESS_END;
}

void mCallback_Send_OK (void)
{
    switch (sMessVar.DataType_u8)
    {
        case _MESS_SINGLE:
            sRecSingle.IndexSend_u16 = (sRecSingle.IndexSend_u16 + sRecSingle.CountMessPacket_u16) % sRecSingle.MaxRecord_u16;
            Flash_Save_Index(sRecSingle.AddIndexSend_u32, sRecSingle.IndexSend_u16);
            break;
        case _MESS_MULTI:
            sRecMultiple.IndexSend_u16 = (sRecMultiple.IndexSend_u16 + sRecMultiple.CountMessPacket_u16) % sRecMultiple.MaxRecord_u16;
			APP_LOG(TS_OFF, VLEVEL_L, "user_message.c: mCallback OK: _MESS_MULTI: IndexSend %02d\n\r", sRecMultiple.IndexSend_u16);
            Flash_Save_Index(sRecMultiple.AddIndexSend_u32, sRecMultiple.IndexSend_u16);
            break;
        case _MESS_MODE:
            sRecMessage.IndexSend_u16 = (sRecMessage.IndexSend_u16 + sRecMessage.CountMessPacket_u16) % sRecMessage.MaxRecord_u16;
            Flash_Save_Index(sRecMessage.AddIndexSend_u32, sRecMessage.IndexSend_u16);
            break;
        case _MESS_RTC:
            sRecMessage.IndexSend_u16 = (sRecMessage.IndexSend_u16 + sRecMessage.CountMessPacket_u16) % sRecMessage.MaxRecord_u16;
            Flash_Save_Index(sRecMessage.AddIndexSend_u32, sRecMessage.IndexSend_u16);
            break;
        default:
            break;
    }
}

void mMess_Handle_Reset (uint8_t DataType)
{
    sMessVar.Retry_u8[DataType] = 0;
    sMessVar.DataType_u8 = 0;
}

uint8_t mCallback_Send_Fail (void)
{
    if (MAX_RETRY_SEND_LORA == 0x02)
    {
        sMessVar.Retry_u8[sMessVar.DataType_u8]++;
        if (sMessVar.Retry_u8[sMessVar.DataType_u8] < MAX_RETRY_WITHOUT_SKIP)
        {
            return FALSE;
        } else
        {
            sMessVar.Retry_u8[sMessVar.DataType_u8] = 0;
            return TRUE;
        }
    } else
    {
        sMessVar.Retry_u8[sMessVar.DataType_u8]++;

        if (sMessVar.Retry_u8[sMessVar.DataType_u8] >= MAX_RETRY_SEND_LORA)
        {
            return TRUE;
        }
    }
    return FALSE;
}

/* End of file ----------------------------------------------------------------*/
