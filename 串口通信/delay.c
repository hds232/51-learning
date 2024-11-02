#include <INTRINS.H>

void delay(unsigned int time)
{
	unsigned char data i, j;
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