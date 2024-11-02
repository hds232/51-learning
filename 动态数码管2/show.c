#include "pu.h"

void show(unsigned char x, y, z)
{
	nixie(7,x);
	nixie(6,y);
	nixie(5,z);
}