#include <STC89C5xRC.H>
#include "AT24C02.h"
#include "DS18B20.h"
#include "LCD1602.h"
#include "Timer0.h"
#include "Key.h"

float T, Temp;
unsigned char KeyNumber;
char TH, TL;

void main()
{
	LCD_Init();
	Timer0_Init();
	LCD_ShowChar(1, 7, '.');
	LCD_ShowChar(1, 10, 0xDF);
	LCD_ShowChar(1, 11, 'C');
	LCD_ShowString(1, 1, "T:");
	LCD_ShowString(2, 1, "TH:");
	LCD_ShowString(2, 9, "TL:");
	TH = AT24C02_ReadByte(10);
	TL = AT24C02_ReadByte(11);
	if(TH >= 120 || TH < TL)
		TH = 50;
	if(TL <= -55 || TL > TH)
		TL = 0;
	while(1)
	{
		//温度显示模块
		LCD_ShowSignedNum(2, 4, TH, 3);
		LCD_ShowSignedNum(2, 12, TL, 2);
		DS18B20_Convert_T();
		T = DS18B20_Read_Scratchpad();
		if(T < 0)
		{
			LCD_ShowChar(1, 3, '-');
			Temp = -T;
		}
		else
		{
			LCD_ShowChar(1, 3, '+');
			Temp = T;
		}
		LCD_ShowNum(1, 4, T, 3);
		LCD_ShowNum(1, 8, (unsigned long)(T * 10000) % 10000, 2);
		//按键修改模块
		KeyNumber = Key();
		if(KeyNumber)
		{
			if(KeyNumber == 1)
			{
				TH ++;
				if(TH >= 120)
					TH --;
			}
			if(KeyNumber == 2)
			{
				TH --;
				if(TH <= TL)
					TH ++;
			}
			if(KeyNumber == 3)
			{
				TL ++;
				if(TL >= TH)
					TL --;
			}
			if(KeyNumber == 4)
			{
				TL --;
				if(TL <= -55)
					TL ++;
			}
			AT24C02_WriteByte(10, TH);
			AT24C02_WriteByte(11, TL);
		}
		//报警显示模块
		if(T > TH || T < TL)
		{
			LCD_ShowString(1, 13, "OV:");
			if(T > TH)
				LCD_ShowChar(1, 16, 'H');
			if(T < TL)
				LCD_ShowChar(1, 16, 'L');
		}
		if(T < TH && T > TL)
			LCD_ShowString(1, 13, "    ");
	}
}

void Timer0_Routine()	interrupt 1
{
	static unsigned char i = 0;
	i ++;
	TL0 = 0x66;
	TH0 = 0xFC;
	if(i == 20)
	{
		i = 0;
		Key_Loop();
	}
}
