#include <REGX52.H>
#include "mine.h"

void main()
{
	unsigned char x=0, n=0, m=0;	
	while(1)
	{
		display(x, n, m);
		if(m==9)
		{
			m=0;
			n++;
		}
		else
			m++;
		if(m==9&&n==9)
		{
			display(x, n, m);
			m=0;
			n=0;
			x++;
		}
	}
}