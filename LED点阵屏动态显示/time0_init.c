#include <REGX52.H>

void time0_init()
{
	TMOD=0x01;
	TF0=0;
	TR0=1;
	TH0=56319/256;
	TL0=56319%256;
	EA=1;
	ET0=1;
	PT0=0;
}