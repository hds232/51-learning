#include <STC89C5xRC.H>
#include "Timer0.h"
#include "Delay.h"
#include "CMusic.h"

#define	SPEED 600

sbit BEEP=P2^5;

unsigned int code Reload[]={63777,63872,63969,64054,64140,64216,64291,64360,64426,64489,64547,64603,
							64655,64704,64751,64795,64837,64876,64913,64948,64981,65012,65042,65068,
							65103,65120,65144,65166,65186,65206,65225,65242,65259,65274,65289,65303,
							0};
unsigned char code Music[]={
	M3,8,
	P,4,
	P,1,
	M1,1,
	M2,1,
	M1,1,
	M3,8,
	P,3,
	M1,2,
	M2,1,
	M1,1,
	M2,1,
	M3,1,
	L6,3,
	M1,2,
	L6,3,
	M1,2,
	L6,3,
	M1,2,
	M2,2,
	M1,2,
	L7,8,
	P,4,
	P,4,
	M3,8,
	P,4,
	P,1,
	M1,1,
	M2,1,
	M1,1,
	M3,8,
	P,3,
	M1,1,
	M2,1,
	M1,1,
	M2,1,
	M3,1,
	L6,3,
	M1,1,
	L6,3,
	M1,1,
	L6,3,
	M1,1,
	M3,2,
	M2,2,
	L7,8,
	P,4,
	P,4,
	L6,1,
	M1,1,
	M6,3,
	M6,1,
	M6,1,
	M5,1,
	M6,2,
	M6,1,
	M5,1,
	M6,1,
	M5,1,
	M6,1,
	M5,3,
	M3,8,
	P,4,
	P,2,
	L6,1,
	M1,1,
	M6,3,
	M6,1,
	M6,1,
	M5,1,
	M6,1,
	M5,1,
	M7,3,
	M7,1,
	M7,1,
	M6,1,
	M7,3,
	M6,2,
	M3,9,
	P,1,
	M3,1,
	M5,1,
	M3,1,
	M2,3,
	M3,1,
	M2,3,
	M3,1,
	M2,3,
	M3,1,
	M5,1,
	M3,1,
	M5,1,
	M3,1,
	M2,3,
	M3,1,
	M2,3,
	M3,1,
	M2,4,
	P,2,
	M1,1,
	M2,1,
	M3,2,
	L6,2,
	M1,2,
	M3,2,
	M2,3,
	M3,1,
	M2,1,
	M1,1,
	M1,2,
	L6,8,
	P,4,
};
unsigned char Musiccount,Reloadcount;

void main()
{
	unsigned int number=sizeof(Music)/sizeof(char)-1;
	Timer0_Init();
	while(1)
	{
		if(Musiccount>number)
			Musiccount=0;
		Reloadcount=Music[Musiccount];
		Musiccount++;
		Delay(SPEED/4*Music[Musiccount]);
		Musiccount++;
		TR0=0;
		Delay(2);
		TR0=1;
	}
}

void Timer0_Routine()		interrupt 1
{
	if(Reload[Reloadcount])
	{
		TL0 = Reload[Reloadcount]%256;
		TH0 = Reload[Reloadcount]/256;
		BEEP=!BEEP;
	}
}