#include "stdint.h"
#include "D:/tassnem/tm4c123gh6pm.h"

void SystemInit(){}
	
void lcdInit();
void lcdCommands(char byte);
void lcdData(char Data){};
//void distance();
void delayMilli(int t);
	
	int main(){
	lcdInit();
	lcdCommands(0x01);                 //Clear the screen by each time we start
	                                
	lcdCommands(0x80);                 //force curse
		
		lcdData('A');                    //Send any dummy data to display
	//distanceTaken=analogRead(SensorPin for example port e pin 2);
			delayMilli(0);
	}
void lcdInit(){
	
	  lcdCommands(0x38);		           //8-bits,2 display lines
	  lcdCommands(0x06);               //icrements cursor auto
		lcdCommands(0x01);               //clear screen
		lcdCommands(0x0F);               //Display On
		
};


void delayMilli(int n){
int i,j;

}

