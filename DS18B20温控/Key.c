#include <STC89C5xRC.H>

unsigned KeyNum;

unsigned char Key()
{
	unsigned char Temp;
	Temp = KeyNum;
	KeyNum = 0;
	return Temp;
}

unsigned char Key_State()
{
	unsigned char Sign = 0;
	if(P31 == 0)
		Sign = 1;
	if(P30 == 0)
		Sign = 2;
	if(P32 == 0)
		Sign = 3;
	if(P33 == 0)
		Sign = 4;
	return Sign;
}

void Key_Loop()
{
	static unsigned char LastState, NowState;
	LastState = NowState;
	NowState = Key_State();
	if(LastState == 1 && NowState == 0)
		KeyNum = 1;
	if(LastState == 2 && NowState == 0)
		KeyNum = 2;
	if(LastState == 3 && NowState == 0)
		KeyNum = 3;
	if(LastState == 4 && NowState == 0)
		KeyNum = 4;
}
