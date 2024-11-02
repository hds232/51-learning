#include <STC89C5xRC.H>

sbit DQ = P3^7;

void BUS_Init()
{
	unsigned char i;
	EA = 0;
	DQ = 1;
	DQ = 0;
	i = 230; while (--i);	//500US
	DQ = 1;
	i = 191; while (--i);	//370us
	EA = 1;
}

void BUS_SendBit(bit Bit)
{
	unsigned char i;
	EA = 0;
	DQ = 0;
	i = 4; while (--i);		//10us
	DQ = Bit;
	i = 22; while (--i);	//50us
	DQ = 1;
	EA = 1;
}

bit BUS_ReceiveBit()
{
	unsigned char i;
	bit Bit;
	EA = 0;
	DQ = 0;
	i = 2; while (--i);		//5us
	DQ = 1;
	i = 2; while (--i);		//5us
	Bit = DQ;
	i = 22; while (--i);	//50us
	EA = 1;
	return Bit;
}

void BUS_SendByte(unsigned char Data)
{
	unsigned char i;
	for(i = 0; i < 8; i ++)
	{
		BUS_SendBit(Data & (0x01 << i));
	}
}

unsigned char BUS_ReceiveByte()
{
	unsigned char i;
	unsigned char Data = 0x00;
	for(i = 0; i < 8; i ++)
	{
		if(BUS_ReceiveBit())
			Data |= (0x01 << i);
	}
	return Data;
}
