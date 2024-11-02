#include <STC89C5xRC.H>

unsigned char KeyNumber;

unsigned char Key()
{
	unsigned char Temp;
	Temp = KeyNumber;
	KeyNumber = 0;
	return Temp;
}

unsigned char Key_State()
{
	unsigned char Number = 0;
	if(P31 == 0)
		Number = 1;
	if(P30 == 0)
		Number = 2;
	if(P32 == 0)
		Number = 3;
	if(P33 == 0)
		Number =4;
	return Number;
}

void Key_Inter()
{
	static unsigned char LastState, NowState;
	LastState = NowState;
	NowState = Key_State();
	if(LastState == 1 && NowState == 0)
		KeyNumber = 1;
	if(LastState == 2 && NowState == 0)
		KeyNumber = 2;
	if(LastState == 3 && NowState == 0)
		KeyNumber = 3;
	if(LastState == 4 && NowState == 0)
		KeyNumber = 4;
}