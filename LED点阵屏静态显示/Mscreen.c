#include <STC89C5xRC.H>
#include "Delay.h"

sbit SER=P3^4;
sbit RCK=P3^5;
sbit SCK=P3^6;

void Mscreen_Init()
{
	RCK=0;
	SCK=0;
}

void _74HC595_Write(unsigned char byte)
{
	unsigned char i=0;
	
	for(;i<8;i++)
	{
		SER=byte&(0x80>>i);
		SCK=1;
		SCK=0;
	}
	RCK=1;
	RCK=0;
}

void Mscreen(unsigned char column, Data)
{
	_74HC595_Write(Data);
	P0=~(0x80>>column);
	Delay(1);
	P0=0xFF;
}