#include <STC89C5xRC.H>

sbit SCLK = P3^6;
sbit IO = P3^4;
sbit CE = P3^5;

void DS1302_WriteByte(unsigned char Command, Data)
{
	unsigned char i;
	Data = Data / 10 * 16 + Data % 10;
	CE = 1;
	for(i = 0; i < 8; i++)
	{
		IO = Command & (0x01 << i);
		SCLK = 1;
		SCLK = 0;
	}
	for(i = 0; i < 8; i++)
	{
		IO = Data & (0x01 << i);
		SCLK = 1;
		SCLK = 0;
	}
	CE = 0;
}

unsigned char DS1302_ReadByte(unsigned char Command)
{
	unsigned char i, Byte = 0x00;
	CE = 1;
	for(i = 0; i < 8; i++)
	{
		IO = Command & (0x01 << i);
		SCLK = 0;
		SCLK = 1;
	}
	for(i = 0; i < 8; i++)
	{
		SCLK = 1;
		SCLK = 0;
		if(IO)
			Byte |= (0x01 << i);
	}
	CE = 0;
	IO = 0;
	Byte = Byte / 16 * 10 + Byte % 16;
	return Byte;
}

void DS1302_Init()
{
	CE = 0;
	SCLK = 0;
	DS1302_WriteByte(0x8E, 0x00);
}