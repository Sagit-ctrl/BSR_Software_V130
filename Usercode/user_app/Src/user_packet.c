#include "user_packet.h"

#include "user_time.h"
#include "sys_app.h"
#include "user_define.h"
#include "user_message.h"
#include "user_modem.h"
#include "user_time.h"

/* Private function prototypes -----------------------------------------------*/
static uint8_t _Cb_Packet_Entry (uint8_t event);
static uint8_t _Cb_Packet_Single (uint8_t event);
static uint8_t _Cb_Packet_Multi (uint8_t event);
static uint8_t _Cb_Packet_Mode (uint8_t event);
static uint8_t _Cb_Packet_RTC_Mode (uint8_t event);

/* External variables ---------------------------------------------------------*/
sEvent_struct sEventAppPacket[] =
{
    { _EVENT_ENTRY_PACKET, 		        0, 0, 0, 	    _Cb_Packet_Entry },
	{ _EVENT_PACKET_SINGLE, 		    0, 0, 0, 	    _Cb_Packet_Single },
	{ _EVENT_PACKET_MULTI, 		        0, 0, 0, 	    _Cb_Packet_Multi },
	{ _EVENT_PACKET_MODE, 		        0, 0, 0, 	    _Cb_Packet_Mode },
	{ _EVENT_PACKET_RTC_MODE, 		    0, 0, 0, 	    _Cb_Packet_RTC_Mode },
};

/* Exported functions --------------------------------------------------------*/
void AppPacket_Init (void)
{
}

uint8_t AppPacket_Task(void)
{
	uint8_t i = 0;
	uint8_t Result = 0;
	for (i = 0; i < _EVENT_END_PACKET; i++)
	{
		if (sEventAppPacket[i].e_status == 1)
		{
            Result = 1;
			if ((sEventAppPacket[i].e_systick == 0) ||
					((HAL_GetTick() - sEventAppPacket[i].e_systick)  >=  sEventAppPacket[i].e_period))
			{
                sEventAppPacket[i].e_status = 0;  //Disable event
				sEventAppPacket[i].e_systick = HAL_GetTick();
				sEventAppPacket[i].e_function_handler(i);
			}
		}
	}
	return Result;
}

/* Private function prototypes -----------------------------------------------*/
static uint8_t _Cb_Packet_Entry (uint8_t event)
{
	#ifdef DEVICE_TYPE_STATION
		fevent_active(sEventAppPacket, _EVENT_PACKET_RTC_MODE);
	#else
		switch (sModem.Mode_Node)
		{
			case _MODE_SLEEP:
				APP_LOG(TS_OFF, VLEVEL_L, "user_packet.c: Entry measure single\n\r");
				fevent_active(sEventAppCom, _EVENT_MEAS_SINGLE);
				break;
			case _MODE_WAKEUP:
				break;
			case _MODE_MEASURE:
				APP_LOG(TS_OFF, VLEVEL_L, "user_packet.c: Entry measure multiple\n\r");
				fevent_active(sEventAppCom, _EVENT_MEAS_MULTI);
				break;
			default:
				break;
		}
	#endif
	return 1;
}

static uint8_t _Cb_Packet_Single (uint8_t event)
{
	#ifdef DEVICE_TYPE_STATION
	#else
    	APP_LOG(TS_OFF, VLEVEL_L, "user_packet.c: Packeting single message.\n\r");
    	Packet_Single_Message();
	    sModem.ValueMeasure_u8 = 0;
		sModem.CountMeasure_u8 = 0;

		#ifdef USING_APP_LORA
			sMessVar.aMARK[_MESS_SINGLE] = TRUE;
			AppLora_Set_Tx_Again(sModem.TimeDelayTx_u32);
		#endif
	#endif
    return 1;
}

static uint8_t _Cb_Packet_Multi (uint8_t event)
{
	#ifdef DEVICE_TYPE_STATION
	#else
		APP_LOG(TS_OFF, VLEVEL_L, "user_packet.c: Packeting multiple message.\n\r");
		Packet_Multiple_Message();
		Reset_Buff(&sModem.strMultiRespond);
		sModem.CountMeasure_u8 = 0;

		#ifdef USING_APP_LORA
			sMessVar.aMARK[_MESS_MULTI] = TRUE;
			AppLora_Set_Tx_Again(sModem.TimeDelayTx_u32);
		#endif
	#endif
    return 1;
}

static uint8_t _Cb_Packet_Mode (uint8_t event)
{
	#ifdef DEVICE_TYPE_STATION
	#else
		APP_LOG(TS_OFF, VLEVEL_L, "user_packet.c: Packeting mode message.\n\r");
		Packet_Mode_Message();

		#ifdef USING_APP_LORA
			sMessVar.aMARK[_MESS_MODE] = TRUE;
			AppLora_Set_Tx_Again(sModem.TimeDelayTx_u32);
		#endif
	#endif
	return 1;
}

static uint8_t _Cb_Packet_RTC_Mode (uint8_t event)
{
	#ifdef DEVICE_TYPE_STATION
		APP_LOG(TS_OFF, VLEVEL_L, "user_packet.c: Packeting RTC mode message.\n\r");
		Packet_RTC_Mode_Message();

		#ifdef USING_APP_LORA
			sMessVar.aMARK[_MESS_RTC] = TRUE;
			AppLora_Set_Tx_Again(0);
		#endif
	#else
	#endif
	return 1;
}

void Packet_Single_Message (void)
{
	uint8_t     pData[128] = {0};
	uint8_t     length = 0;
	uint8_t     TempCrc = 0;
	uint16_t	i = 0;

    sModem.ValueBattery_u8 = Get_Vol_BAT();

	pData[length++] = OBIS_ID_SENSOR;
	pData[length++] = sModem.sDCU_id.Length_u16;

	for (i = 0; i < sModem.sDCU_id.Length_u16; i++)
		pData[length++] = *(sModem.sDCU_id.Data_a8 + i);

	if (sModem.TypeModem_u8 == _LORA_NODE_VNA)
	{
		pData[length++] = OBIS_VOL_VNA;
	} else if (sModem.TypeModem_u8 == _LORA_NODE_VP)
	{
		pData[length++] = OBIS_VOL_VNA;
	}
	pData[length++] = 0x02;
	pData[length++] = (sModem.ValueMeasure_u8 >> 8) & 0xFF;
	pData[length++] = sModem.ValueMeasure_u8 & 0xFF;

	pData[length++] = OBIS_VOL_BAT;
	pData[length++] = 0x02;
	pData[length++] = (sModem.ValueBattery_u8 >> 8) & 0xFF;
	pData[length++] = sModem.ValueBattery_u8 & 0xFF;
	pData[length++] = 0x00;

	length++;
	for (i = 0; i < (length - 1); i++)
		TempCrc ^= pData[i];

	pData[length-1] = TempCrc;

	Flash_Save_Record (&sRecSingle, &pData[0], length);
}

void Packet_Multiple_Message (void){
	uint8_t        pData[128] = {0};
	uint8_t        length = 0;
	uint8_t        TempCrc = 0;
	uint8_t        iRecord, iID, iData, iCRC;

	for (iRecord = 0; iRecord < 3; iRecord++)
	{
		length = 0;
		TempCrc = 0;
		pData[length++] = OBIS_ID_SENSOR;
		pData[length++] = sModem.sDCU_id.Length_u16;

		for (iID = 0; iID < sModem.sDCU_id.Length_u16; iID++)
			pData[length++] = *(sModem.sDCU_id.Data_a8 + iID);

		if (sModem.TypeModem_u8 == _LORA_NODE_VNA)
		{
			pData[length++] = OBIS_VOL_VNA;
		} else if (sModem.TypeModem_u8 == _LORA_NODE_VP)
		{
			pData[length++] = OBIS_VOL_VNA;
		}
		pData[length++] = 0x64;
		for (iData = 0; iData < 100; iData++)
		{
			pData[length++] = *(sModem.strMultiRespond.Data_a8 + iRecord * 100 + iData);
		}
		pData[length++] = 0x00;

		length++;
		for (iCRC = 0; iCRC < (length - 1); iCRC++)
			TempCrc ^= pData[iCRC];

		pData[length-1] = TempCrc;

		Flash_Save_Record (&sRecMultiple, &pData[0], length);
        APP_LOG(TS_OFF, VLEVEL_L, "user_packet.c: Save multi record\r\n");
        for (iID = 0; iID < length; iID++)
            APP_LOG(TS_OFF, VLEVEL_L, "%02X", pData[iID]);
        APP_LOG(TS_OFF, VLEVEL_L, "\n\r");
	}
}

void Packet_Mode_Message (void)
{
	uint8_t     pData[128] = {0};
	uint8_t     length = 0;
	uint8_t     TempCrc = 0;
	uint16_t	i = 0;

	pData[length++] = OBIS_ID_SENSOR;
	pData[length++] = sModem.sDCU_id.Length_u16;

	for (i = 0; i < sModem.sDCU_id.Length_u16; i++)
		pData[length++] = *(sModem.sDCU_id.Data_a8 + i);

	pData[length++] = OBIS_MODE;
	pData[length++] = 0x01;
	pData[length++] = sModem.Mode_Node & 0xFF;
	pData[length++] = 0x00;

	length++;
	for (i = 0; i < (length - 1); i++)
		TempCrc ^= pData[i];

	pData[length-1] = TempCrc;

	Flash_Save_Record (&sRecMessage, &pData[0], length);
}

void Packet_RTC_Mode_Message (void)
{
	uint8_t     pData[128] = {0};
    uint8_t     length = 0;
    uint16_t	i = 0;
    uint8_t     TempCrc = 0;

    Get_RTC();

    pData[length++] = OBIS_ID_STATION;
    pData[length++] = sModem.sDCU_id.Length_u16;

    for (i = 0; i < sModem.sDCU_id.Length_u16; i++)
        pData[length++] = *(sModem.sDCU_id.Data_a8 + i);

    pData[length++] = OBIS_TIME;
    pData[length++] = 0x06;
    pData[length++] = sRTC.year;
    pData[length++] = sRTC.month;
    pData[length++] = sRTC.date;
    pData[length++] = sRTC.hour;
    pData[length++] = sRTC.min;
    pData[length++] = sRTC.sec;

    pData[length++] = OBIS_MODE;
    pData[length++] = 0x01;
    pData[length++] = sModem.Mode_Station & 0xFF;
    pData[length++] = 0x00;

    length++;
	for (i = 0; i < (length - 1); i++)
		TempCrc ^= pData[i];

    pData[length-1] = TempCrc;

	Flash_Save_Record (&sRecMessage, &pData[0], length);
}


