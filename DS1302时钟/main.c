#include <STC89C5xRC.H>
#include "Ntube.h"
#include "DS1302.h"

sbit BEEP = P2^5;

unsigned char Sec, Min, Hou;

void Timer0_Init(void)
{
	TMOD &= 0xF0;
	TMOD |= 0x01;
	TL0 = 0x66;
	TH0 = 0xFC;
	TF0 = 0;
	TR0 = 1;
	EA = 1;
	ET0 = 0;
}

void main()
{
	DS1302_Init();
	Timer0_Init();
	DS1302_WriteByte(0x80, 0);
	DS1302_WriteByte(0x82, 0);
	DS1302_WriteByte(0x84, 0);
	while(1)
	{
		Sec = DS1302_ReadByte(0x81);
		Min = DS1302_ReadByte(0x83);
		Hou = DS1302_ReadByte(0x85);
		Ntube(1, Sec % 10);
		Ntube(2, Sec / 10);
		Ntube(3, 10);
		Ntube(4, Min % 10);
		Ntube(5, Min / 10);
		Ntube(6, 10);
		Ntube(7, Hou % 10);
		Ntube(8, Hou / 10);
		if(Sec >= 10)
			ET0 = 1;
	}
}

void Timer0_Routine()	interrupt 1
{
	TL0 = 0x66;
	TH0 = 0xFC;
	BEEP = !BEEP;
}