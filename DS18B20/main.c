#include <STC89C5xRC.H>
#include "DS18B20.h"
#include "LCD1602.h"

float T;

void main()
{
	DS18B02_Init();
	LCD_Init();
	LCD_ShowChar(1, 5, '.');
	while(1)
	{
		DS18B02_Init();
		T = DS18B02_ReadTem();
		if(T < 0)
		{
			LCD_ShowChar(1, 1, '-');
			T = -T;
		}
		LCD_ShowNum(1, 2, T, 3);
		LCD_ShowNum(1, 6, (unsigned long)(T * 10000) % 10000, 4);
	}
}
