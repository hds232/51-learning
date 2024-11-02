#include <STC89C5xRC.H>
#include "Mscreen.h"

void main()
{
	Mscreen_Init();
	while(1)
	{
		Mscreen(0, 0x3C);
		Mscreen(1, 0x42);
		Mscreen(2, 0xA9);
		Mscreen(3, 0x85);
		Mscreen(4, 0x85);
		Mscreen(5, 0xA9);
		Mscreen(6, 0x42);
		Mscreen(7, 0x3C);
	}
}