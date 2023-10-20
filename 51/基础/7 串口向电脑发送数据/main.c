#include <REGX52.H>

unsigned char sec;

void Uart_Init(void)		//4800bps@11.0592MHz
{
	PCON &= 0x7F;		//波特率不倍速
	SCON = 0x50;		//8位数据,可变波特率
//	AUXR &= 0xBF;		//定时器1时钟为Fosc/12,即12T
//	AUXR &= 0xFE;		//串口1选择定时器1为波特率发生器
	TMOD &= 0x0F;		//清除定时器1模式位
	TMOD |= 0x20;		//设定定时器1为8位自动重装方式
	TL1 = 0xFA;		//设定定时初值
	TH1 = 0xFA;		//设定定时器重装值
	ET1 = 0;		//禁止定时器1中断
	TR1 = 1;		//启动定时器1
	
	EA = 1;	//启用中断
	ES = 1;
}



void UART_SendByte(unsigned char byte){
	SBUF=byte;
	while(TI==0);
	TI=0;
}

void UART_SendByte_PC(unsigned char byte){
	SBUF=byte;
	while(TI==0);
	TI=0;
}

void Delay(unsigned int xms)		//@11.0592MHz
{
	unsigned char i, j;
	while(xms--){
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
	}
}

void main()
{
	UART_Init();
	while(1){
		UART_SendByte(sec);
		sec++;
		Delay(1000);
	}
}

void UART_Routine() interrupt 4 //串口专用终端4
{
//	P2 = 0x00;
	if(RI == 1){
		P2 = SBUF;
		RI = 0;
		UART_SendByte_PC(SBUF);
	}
}