#include "stdint.h"
#include "C:/keil/tm4c123gh6pm.h"
void SystemInit(){}
void init_PortA_PortB (){
SYSCTL_RCGCGPIO_R |= 0x01; //Enable PORTA clock
while((SYSCTL_PRGPIO_R & 0x01)==0){};
SYSCTL_RCGCGPIO_R |= 0x02; //Enable PORT B clock
while((SYSCTL_PRGPIO_R & 0x02)==0){};
GPIO_PORTA_DIR_R |=0xE0; //PORTA pins 5-6-7 controls RS,E and R/W
GPIO_PORTA_DEN_R |=0xE0;
GPIO_PORTA_AMSEL_R =0; //disable analog 
GPIO_PORTA_AFSEL_R =0;
GPIO_PORTA_PCTL_R = 0;
GPIO_PORTB_DIR_R |=0xFF; //PORTB 0-7
GPIO_PORTB_DEN_R |=0xFF; //PORTB 0-7corresponds to D0-D7
GPIO_PORTB_AMSEL_R =0;   //disable analog 
GPIO_PORTB_AFSEL_R =0;
GPIO_PORTB_PCTL_R = 0;
}
int main(){
}
