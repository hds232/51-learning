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
/**@brief  利用74HC595写入变量byte的二进制值
  *@param  byte 用户使用变量
  *@retval 无
  */
void Mscreen(unsigned char column, Data)
{
	_74HC595_Write(Data);
	P0=~(0x80>>column);
	Delay(1);
	P0=0xFF;
}
/**@brief  点阵屏按列显示
  *@param  column 此次显示列数；Data控制每列LED灯显示
  *@retval 无
  */