#include <REGX52.H>

sbit _RCLK = P3^5;
sbit _SRCLK = P3^6;
sbit _SER = P3^4;

void _74HC595_WriteByte(unsigned char Byte){
	unsigned char i;
	for(i = 0; i < 8; i++){
		_SER = Byte&(0x80>>i);	// 非0即1
		// _SRCLK在低电平才会进行操作，所以先赋高再赋低
		_SRCLK = 1;
		_SRCLK = 0;
	}
	// 执行完for循环后，数据就已经全部放入移位寄存器中了
	_RCLK = 1;
	_RCLK = 0;	// 把数据8位数据移到右边输出
//	P2 = ~Byte;
	
}

void MatrixLED_ShowColumn(unsigned char Column, Data)
{
	_74HC595_WriteByte(Data);
	P0 = ~(0x80>>Column);
}

void main(){
	_SRCLK = 0; //单片机启动时，移位寄存器所有的口都是高电平
	_SER = 0;	//先赋值低电平可以方便后面操作
	
//	_74HC595_WriteByte(0xf0);
	MatrixLED_ShowColumn(0, 0x84);
	
	while(1){
//		MatrixLED_ShowColumn(0, 0x84);
	}
}