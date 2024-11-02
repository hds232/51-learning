#include <REGX52.H>
#include <INTRINS.H>
#define uchar unsigned char  

void Delay(uchar time)
{
	uchar data i, j;
	while(time--)
	{
		_nop_();
		_nop_();
		_nop_();
		i = 11;
		j = 190;
		do
		{
			while (--j);
		} while (--i);
	}
}

void main()
{
	uchar i=0;
	P2=~0x80;
	while(1)
	{
		for(i=0;i<8;i++)
		{
			P2=~(0x80>>i);
			Delay(200);
		}
		P2=~0x80;
	}
}