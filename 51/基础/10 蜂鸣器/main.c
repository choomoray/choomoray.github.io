#include <REGX52.H>
#include "Delay.h"

sbit Buzzer = P2^5;


void main(){
	unsigned int i;
	while(1){
		for(i = 0; i < 500; i++){
			Buzzer = !Buzzer;
			Delay(1);
		}
	}
}