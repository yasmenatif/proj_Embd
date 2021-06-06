#include "stdint.h"
#include "C:/Keil/tm4c123gh6pm.h"

void SystemInit() {};
void delayMilli(int Time);
void delayMicro(int Time);
void lcdInit(void);
void lcdCommands(unsigned char Commands);
void lcdData(unsigned char data);
void lcdInit(void){

delayMilli(20);
lcdCommands(0x30); 
delayMilli(5);
lcdCommands(0x30); 
delayMicro(100);
lcdCommands(0x30); 
lcdCommands(0x38); //8-bits,2 display lines
lcdCommands(0x06); //increments cursor auto
lcdCommands(0x01); //Turn on display
lcdCommands(0x0F); //cursor blinking
}	

int main()
{
lcdInit();
 while(1)
{
	
  lcdCommands(0x01);
  lcdCommands(0x80);
  
}
}