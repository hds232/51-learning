#include <REGX52.H>
#include "time0_init.h"
#include "delay.h"

void main()
{
	time0_init();
	P2=~0x01;
	while(1)
	{
		
	}
}