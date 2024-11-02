#include <INTRINS.H>

void delay(unsigned char time)
{

	unsigned char data i, j;
	while(time--)
	{
		_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
	}
}