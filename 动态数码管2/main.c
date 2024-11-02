#include <REGX52.H>
#include "pu.h"

void main()
{
	unsigned char x=6, y=6, z=6;
	unsigned char sign=0;
	while(1)
	{
		if(P3_3==0)
		{
			delay(15);
			while(P3_3==0);
			delay(15);
			if(z==9)
			{
				z=0;
				if(y==9)
				{
					y=0;
					x++;
				}
				else
					y++;
			}
			else
				z++;
		}
		if(P3_1==0)
		{
			delay(15);
			while(P3_1==0);
			delay(15);
			if(z==0)
			{
				z=9;
				if(y==0)
				{
					y=9;
					x--;
				}
				else
					y--;
			}
			else
				z--;
		}
		if(P3_2==0)
		{
			delay(15);
			while(P3_2==0);
			delay(15);
			sign=0;
			while(1)
			{
				unsigned char i=50;
				while(i--)
				{
					show(x, y, z);
					if(P3_0==0)
					{
						delay(15);
						while(P3_0==0);
						sign=1;
						break;
					}
				}
				if(z==0)
				{
					z=9;
					if(y==0)
					{
						y=9;
						x--;
					}
					else
						y--;
				}
				else
					z--;
				if(sign==1)
					break;
			}
		}
		show(x, y, z);
	}
}