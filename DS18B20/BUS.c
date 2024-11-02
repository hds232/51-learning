#include <STC89C5xRC.H>
#include "INTRINS.H"

sbit DO = P3^7;

void BUS_Init()
{
	unsigned char i;
	DO = 1;
	DO = 0;
	i = 230; while (--i);   //500us
	DO = 1;
	i = 191; while (--i);	//150us
}

void BUS_SendBit(unsigned char Ack)
{
	unsigned char i;
	DO = 0;
	i = 4; while (--i);		//10us
	DO = Ack;
	i = 22; while (--i);	//50us
	DO = 1;
}

bit BUS_ReadBit()
{
	unsigned char i;
	bit Ack;
	DO = 0;
	i = 2; while (--i);		//5us
	DO = 1;
	i = 2; while (--i);		//5us
	Ack = DO;
	i = 22; while (--i);	//50us
	return Ack;
}

void BUS_SendByte(unsigned char Data)
{
	unsigned char i;
	for(i = 0; i < 8; i ++)
	{
		BUS_SendBit(Data & (0x01 << i));
	}
}

unsigned char BUS_ReadByte()
{
	unsigned char i, Data = 0x00;
	for(i = 0; i < 8; i ++)
	{
		if(BUS_ReadBit())
			Data |= (0x01 << i);
	}
	return Data;
}
