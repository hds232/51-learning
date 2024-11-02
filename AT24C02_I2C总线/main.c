#include <STC89C5xRC.H>
#include "AT24C02.h"
#include "LCD1602.h"

unsigned char Data;

void main()
{
	LCD_Init();
	AT24C02_WriteByte(1, 88);
	Data = AT24C02_ReadByte(1);
	LCD_ShowNum(1, 1, Data, 3);
	while(1)
	{
		
	}
}