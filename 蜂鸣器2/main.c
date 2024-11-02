#include <STC89C5xRC.H>
#include "Public.h"

#define SPEED 690

sbit BEEP = P2^5;

unsigned int code Tone[] = {63777,63872,63969,64054,64140,64216,64291,64360,64426,64489,64547,64603,
						     64655,64704,64751,64795,64837,64876,64913,64948,64981,65012,65042,65068,
						     65103,65120,65144,65166,65186,65206,65225,65242,65259,65274,65289,65303,
						     0};
unsigned char code Music[] = {
	H1,3,
	M7,3,
	M5,4,
	M2,2,
	M3,12,
	H1,3,
	M7,3,
	M5,2,
	M2,6,
	M1,6,
	L7,2,
	L6,2,
	L7,1,
	M1,2,
	M5,3,
	L7,2,
	M1,1,
	M2,2,
	M7,3
};
unsigned char Tone_Select, Music_Select;

void main()
{
	unsigned int Number = sizeof (Music) / sizeof (char) - 1;
	
	Timer0_Init();
	while ( 1 )
	{
		if (Music_Select > Number)
			Music_Select = 0;
		Tone_Select = Music[ Music_Select ];
		Music_Select++;
		Delay( SPEED / 4 * Music[ Music_Select ] );
		Music_Select++;
		TR0 = 0;
		Delay( 2 );
		TR0 = 1;
	}
}

void Timer0_Routine()	interrupt 1
{
	if( Tone[ Tone_Select ] )
	{
		TH0 = Tone[ Tone_Select ] / 256;
		TL0 = Tone[ Tone_Select ] % 256;
		BEEP = !BEEP;
	}
}