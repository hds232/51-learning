#include <REGX52.H>

unsigned char i=0, j=0;

void time0_rountine()	interrupt 1
{
	TH0=56319/256;
	TL0=56319%256;
	i++; 
	if(i==100)
	{
		j++;
		if(j==8)
			j=0;
		P2=~(0x01<<j);
		i=1;
	}
}