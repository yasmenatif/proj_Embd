#include "stdint.h"
#include "C:/Users/hp/Desktop/ARM/EE319Kware/inc/tm4c123gh6pm.h"
void SystemInit (){}
void inti(void)
{
	SYSCTL_RCGCGPIO_R|=0x01;
 while((SYSCTL_PRGPIO_R&0x20)==0){};
	 SYSCTL_RCGCUART_R|=0x01; 
  UART0_CTL_R&=~0x01;
	 UART0_IBRD_R=104;
	 UART0_FBRD_R=11;
	 UART0_LCRH_R|=0x70;
	   UART0_CTL_R|=0x0301;
	 GPIO_PORTA_AFSEL_R|=0x03;
	 GPIO_PORTA_PCTL_R=(GPIO_PORTA_PCTL_R&0xffffff00)+0x00000011;
    GPIO_PORTA_DEN_R|=0x03;
		GPIO_PORTA_AMSEL_R&=~0x03;
		
} 
 int main()
{
	int c;
while((UART0_FR_R&0x02)!=0){} // transmitt
 UART0_DR_R='A';
	while((UART0_FR_R&0x10)!=0){} // recive
	UART0_DR_R= c;	


}