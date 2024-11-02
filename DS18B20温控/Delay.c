#include <INTRINS.H>

void Delay(unsigned int time)
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
