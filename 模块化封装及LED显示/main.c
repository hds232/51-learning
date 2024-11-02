#include <REGX52.H>
#include "lcd1602.h"
#include "public.h"
#include "puyuxin.h"

void main()
{
	u8 string[11], words[]={"Birthday!"};
	u8 i=0, j=0, sign=0;
	lcd1602_init();
	for(i=0;i<9;i++)
	{
		while(!(j==0))
		{
			j=i;
			string[j]=words[8-sign];
			j--;
			sign++;
		}
		lcd1602_show_string(0, 0, string);
		delay(50);
	}
	while(1);
}