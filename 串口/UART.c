#include <STC89C5xRC.H>

void UART_Init()
{
	SCON=0x50;
	PCON&=0x3F;
	TMOD&=0x0F;
	TMOD|=0x20;
	TR1=1;
	TH1=0XFD;
	TL1=0xFD;
	EA=1;
	ET1=0;
	ES=1;
}

void UART_Send(unsigned char byte)
{
	SBUF=byte;
	while(TI==0);
	TI=0;
}