#include <STC89C5xRC.H>
#include "UART.h"

void main()
{
	UART_Init();
	while(1);
}

void UART_Routine()		interrupt 4
{
	if(RI==1)
	{
		
	}
}