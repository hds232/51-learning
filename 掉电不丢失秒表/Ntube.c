#include <STC89C5xRC.H>

unsigned char Ntube_Buf[9] = {0, 11, 11 ,11, 11, 11, 11, 11, 11};

unsigned char code num[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x40, 0x00};

void Ntube(unsigned char location, number)
{
	Ntube_Buf[location] = number;
}

void Ntube_Show(unsigned char location, number)
{
	P0 = 0x00;
	switch (location)
	{
		case 8 : P24 = 0; P23 = 0; P22 = 0; break;
		case 7 : P24 = 0; P23 = 0; P22 = 1; break;
		case 6 : P24 = 0; P23 = 1; P22 = 0; break;
		case 5 : P24 = 0; P23 = 1; P22 = 1; break;
		case 4 : P24 = 1; P23 = 0; P22 = 0; break;
		case 3 : P24 = 1; P23 = 0; P22 = 1; break;
		case 2 : P24 = 1; P23 = 1; P22 = 0; break;
		case 1 : P24 = 1; P23 = 1; P22 = 1; break;
	}
	P0 = num[number];
}

void Ntube_Inter()
{
	static unsigned char i = 1;
	Ntube_Show(i, Ntube_Buf[i]);
	i++;
	if(i >= 9)
		i = 1;
}