#include <REGX52.H>

unsigned char KeyNumber;


unsigned char Key_ReturnNumber;
unsigned char Nixie_Buf[9] = {0, 10, 10, 10, 10, 10, 10, 10, 10};
unsigned char NixieTable[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x00};

unsigned char Key_GetState();
void Timer_Key(void);
unsigned char Key(void);

void Nixie(unsigned char Location, Number);
void Nixie_Loop(void);
void Nixie_SetBuf(unsigned char Location, Number);

void Timer_Init()
{
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
//	TH0 = 64535/256;
//	TL0 = 64535%256;
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	ET0 = 1;
	EA = 1;
	PT0 = 0;
}


void main(void)
{
	Timer_Init();
	while(1)
	{
		KeyNumber = Key();
		if (KeyNumber) Nixie_SetBuf(1, KeyNumber);
	}
}

void Timer_Routine() interrupt 1
{
	static unsigned int TimerKeyCount,TimerNixieCount;
	
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	TimerKeyCount++;	
	TimerNixieCount++;	
	
	if(TimerKeyCount>=20)
	{
		Timer_Key();
		TimerKeyCount=0;		
	}
	
	if(TimerNixieCount>=2)
	{
		Nixie_Loop();
		TimerNixieCount=0;
	}
}

unsigned char Key(void)
{
	unsigned char tmp;
	tmp = Key_ReturnNumber;
	Key_ReturnNumber = 0;
	return tmp;
}

void Timer_Key(void)
{
	static unsigned char NowState, LastState;
	LastState = NowState;
	NowState = Key_GetState();
	
	if (LastState == 1 && NowState == 0)
	{
		Key_ReturnNumber = 1;
	}
	if (LastState == 2 && NowState == 0)
	{
		Key_ReturnNumber = 2;
	}
	if (LastState == 3 && NowState == 0)
	{
		Key_ReturnNumber = 3;
	}
	if (LastState == 4 && NowState == 0)
	{
		Key_ReturnNumber = 4;
	}
}

unsigned char Key_GetState()
{
	unsigned char key=0;
	
	if(P3_1 == 0){key = 1;}
	if(P3_0 == 0){key = 2;}
	if(P3_2 == 0){key = 3;}
	if(P3_3 == 0){key = 4;}
	
	return key;
}



void Nixie(unsigned char Location, Number)
{
	P0 = 0x00;
	switch(Location){
		case 1:P2_4 = 1;P2_3 = 1;P2_2 = 1;break;
		case 2:P2_4 = 1;P2_3 = 1;P2_2 = 0;break;
		case 3:P2_4 = 1;P2_3 = 0;P2_2 = 1;break;
		case 4:P2_4 = 1;P2_3 = 0;P2_2 = 0;break;
		case 5:P2_4 = 0;P2_3 = 1;P2_2 = 1;break;
		case 6:P2_4 = 0;P2_3 = 1;P2_2 = 0;break;
		case 7:P2_4 = 0;P2_3 = 0;P2_2 = 1;break;
		case 8:P2_4 = 0;P2_3 = 0;P2_2 = 0;break;
	}
	P0 = NixieTable[Number];
}

void Nixie_Loop(void)
{
	static unsigned char i;
	Nixie(i, Nixie_Buf[i]);
	i++;
	if(i>=9) i=1;
}

void Nixie_SetBuf(unsigned char Location, Number)
{
	Nixie_Buf[Location] = Number;
}