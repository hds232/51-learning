#include <STC89C5xRC.H>
#include "Delay.h"

unsigned char code num[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x40};

void Ntube(unsigned char location, number)
{
	switch (location)
	{
		case 1 : P24 = 0; P23 = 0; P22 = 0; break;
		case 2 : P24 = 0; P23 = 0; P22 = 1; break;
		case 3 : P24 = 0; P23 = 1; P22 = 0; break;
		case 4 : P24 = 0; P23 = 1; P22 = 1; break;
		case 5 : P24 = 1; P23 = 0; P22 = 0; break;
		case 6 : P24 = 1; P23 = 0; P22 = 1; break;
		case 7 : P24 = 1; P23 = 1; P22 = 0; break;
		case 8 : P24 = 1; P23 = 1; P22 = 1; break;
	}
	P0 = num[number];
	Delay(1);
	P0 = 0x00;
}
