#include <STC89C5xRC.H>
#include "delay.h"

unsigned char num0[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
unsigned char num1[]={0xBF,0x86,0xDB,0xCF,0xE6,0xED,0xFD,0x87,0xFF,0xEF};

void Ntube(unsigned char location, number, sign)
{
	switch(location)
	{
		case 1:P24=0;P23=0;P22=0;break;
		case 2:P24=0;P23=0;P22=1;break;
		case 3:P24=0;P23=1;P22=0;break;
		case 4:P24=0;P23=1;P22=1;break;
		case 5:P24=1;P23=0;P22=0;break;
		case 6:P24=1;P23=0;P22=1;break;
		case 7:P24=1;P23=1;P22=0;break;
		case 8:P24=1;P23=1;P22=1;break;
	}
	if(sign)
		P0=num1[number];
	else
		P0=num0[number];
	delay(1);
	P0=0x00;
}
/**@brief  数码管显示函数
  *@param  location:显示位置
  *@param  number:显示数字
  *@param  sign:是否显示小数点--0不显示，1显示
  *@retval 无
  */