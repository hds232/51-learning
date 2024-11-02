#include <STC89C5xRC.H>
#include "time.h"

unsigned char sec=3, min=6, hou=16;

void Timer0_Init()
{
	TMOD&=0xF0;
	TMOD|=0x01;
	TF0=0;
	TR0=1;
	TL0=0x00;
	TH0=0xDC;
	EA=1;
	ET0=1;
}

void main()
{
	Timer0_Init();
	while(1)
	{
		Ntube(1, sec%10, 0);
		Ntube(2, sec/10, 0);
		Ntube(3, min%10, 1);
		Ntube(4, min/10, 0);
		Ntube(5, hou%10, 1);
		Ntube(6, hou/10, 0);
	}
}

void Timer0_Routine()	interrupt 1
{
	static unsigned int i=0;
	i++;
	
	TL0=0x00;
	TH0=0xDC;
	
	if(i==100)
	{
		i=0;
		sec++;
		if(sec==60)
		{
			sec=0;
			min++;
			if(min==60)
			{
				min=0;
				hou++;
				if(hou==24)
					hou=0;
			}
		}
	}
}