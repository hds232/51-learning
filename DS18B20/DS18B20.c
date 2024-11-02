#include "BUS.h"
#include "Delay.h"

void DS18B02_Init()
{
	BUS_Init();
	BUS_SendByte(0xCC);
	BUS_SendByte(0x44);
	Delay(100);
}

float DS18B02_ReadTem()
{
	unsigned char LSB, MSB;
	int Temp;
	float T;
	BUS_Init();
	BUS_SendByte(0xCC);
	BUS_SendByte(0xBE);
	LSB = BUS_ReadByte();
	MSB = BUS_ReadByte();
	Temp = (MSB << 8) | LSB;
	T = Temp / 16.0;
	return T;
}