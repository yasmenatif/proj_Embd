#include "C:/Keil/labware/inc/tm4c123gh6pm.h"
#include "stdint.h"

void delayMicro(int Time);
void delayMilli(int Time);

void lcdCommands(unsigned char Commands)
{
GPIO_PORTA_DATA_R = 0x00; //RS =0 as command, E=0, RW=0
GPIO_PORTB_DATA_R =Commands;
GPIO_PORTA_DATA_R =0x80; //E=1
delayMicro(0);
GPIO_PORTA_DATA_R =0x00;
if(Commands <4) delayMilli(2); 
else delayMicro(40); }


