#include "BUS.h"
#include "Delay.h"

#define	SKIP_ROM			0xCC
#define CONVERT_T			0x44
#define READ_SCRATCHPAD		0xBE

void DS18B20_Convert_T()
{
	BUS_Init();
	BUS_SendByte(SKIP_ROM);
	BUS_SendByte(CONVERT_T);
	Delay(400);
}

float DS18B20_Read_Scratchpad()
{
	float T;
	int Temp;
	unsigned char LSB, MSB;
	BUS_Init();
	BUS_SendByte(SKIP_ROM);
	BUS_SendByte(READ_SCRATCHPAD);
	LSB = BUS_ReceiveByte();
	MSB = BUS_ReceiveByte();
	Temp = (MSB << 8) | LSB;
	T = Temp / 16.0;
	return T;
}
