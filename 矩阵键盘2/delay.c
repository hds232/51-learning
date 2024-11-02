#include <INTRINS.H>

void delay(unsigned int time)
{
	unsigned char  data i, j;
	while(time--)
	{
		i=11; j=190;
		_nop_();
		_nop_();
		_nop_();
		do
		{
			while(--j);
		}while(--i);
	}
}