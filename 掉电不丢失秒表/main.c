#include <STC89C5xRC.H>
#include "AT24C02.h"
#include "Ntube.h"
#include "Key.h"

unsigned char KeyNum;
unsigned char Min, Sec, TenMsec;
unsigned char Flag;

void Timer0_Init()
{
	TMOD &= 0xF0;
	TMOD |= 0x01;
	TL0 = 0x66;
	TH0 = 0xFC;
	TF0 = 0;
	TR0 = 1;
	EA = 1;
	ET0 = 1;
}

void main()
{
	Timer0_Init();
	while(1)
	{
		KeyNum = Key();
		if(KeyNum == 1)
			Flag = !Flag;
		if(KeyNum == 2)
		{
			Min = 0;
			Sec = 0;
			TenMsec = 0;
		}
		if(KeyNum == 3)
		{
			AT24C02_WriteByte(1, TenMsec);
			AT24C02_WriteByte(2, Sec);
			AT24C02_WriteByte(3, Min);
		}
		if(KeyNum == 4)
		{
			TenMsec = AT24C02_ReadByte(1);
			Sec = AT24C02_ReadByte(2);
			Min = AT24C02_ReadByte(3);
		}
		Ntube(1, Min / 10);
		Ntube(2, Min % 10);
		Ntube(3, 10);
		Ntube(4, Sec / 10);
		Ntube(5, Sec % 10);
		Ntube(6, 10);
		Ntube(7, TenMsec / 10);
		Ntube(8, TenMsec % 10);
	}
}

void Sec_Inter()
{
	if(Flag)
	{
		TenMsec ++;
		if(TenMsec == 100)
		{
			TenMsec = 0;
			Sec ++;
			if(Sec == 60)
			{
				Sec = 0;
				Min ++;
				if(Min == 100)
					Min = 0;
			}
		}
	}
}

void Timer0_Routine()	interrupt 1
{
	static unsigned char count1 = 0, count2 = 0, count3 = 0;
	count1 ++;
	count2 ++;
	count3 ++;
	TL0 = 0x66;
	TH0 = 0xFC;
	if(count1 >= 2)
	{
		count1 = 0;
		Ntube_Inter();
	}
	if(count2 >= 20)
	{
		count2 = 0;
		Key_Inter();
	}
	if(count3 >= 10)
	{
		count3 = 0;
		Sec_Inter();
	}
}