#include <STC89C5xRC.H>

void UART_Init()
{
	SCON=0x50;
	PCON&=0x0F;
	ET1=0;
	TL1=0xFD;
	TH1=0xFD;
	TMOD&=0x0F;
	TMOD|=0x20;
	TR1=1;
	ES=1;
	PS=1;
}

void UART_SendData(char byte)
{
	SBUF=byte;
	while(TI==0);
	TI=0;
}

void UATR_GetData()
{
	P2=~SBUF;
	while(RI==0);
	RI=0;
}