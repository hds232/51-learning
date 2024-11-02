#include <REGX52.H>
#include "lcd1602.h"
#include "delay.h"
#include "matrixkey.h"
#include "public.h"

void main()
{
	unsigned char number[5]={"0000"};
	unsigned char sign=0, keynum=0;
	unsigned char i=0, j=0;
	lcd1602_init();
	lcd1602_show_string(0, 0, "key:");
	lcd1602_show_string(0, 1, number);
	for(i=0;i<4;i++)
	{
		j=3-i;
		while(1)
		{
			sign=matrixkey();
			if(sign<10)
				keynum=sign;
			if(sign==10)
				keynum=0;
			if(sign)
			{
				number[j]=keynum;
				lcd1602_show_string(0, 1, number);
				break;
			}
		}
	}
}