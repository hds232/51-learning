#include "mine.h"

void display(unsigned char x, n, m)
{
	unsigned char i=20;
	while(i--)
	{
		nixie(3,x);
		nixie(2,n);
		nixie(1,m);
	}
}