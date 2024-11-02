#include <STC89C5xRC.H>
#include "UART.h"
#include "delay.h"

char a='a';

void main()
{
	UART_Init();
	while(1)
	{
		UART_SendData(a);
		a++;
		delay(250);
	}
}