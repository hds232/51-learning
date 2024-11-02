#include <STC89C5xRC.H>

#define LCD_DATA	P0

sbit EN = P2^7;
sbit RS = P2^6;
sbit WR = P2^5;

void Delay_LCD()
{
	unsigned char data i, j;

	_nop_();
	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
}

void LCD_WriteCommand(unsigned char Command)
{
	
}
