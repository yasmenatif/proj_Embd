
#include "stdint.h"
#include "C:/Users/hp/Desktop/ARM/EE319Kware/inc/tm4c123gh6pm.h"
void SystemInit (){}
void inti(void)
{
	SYSCTL_RCGCGPIO_R|=0x20;
 while((SYSCTL_PRGPIO_R&0x20)==0){};
  GPIO_PORTF_LOCK_R=0x4C4F434B;
  GPIO_PORTF_CR_R|=0x04;
		GPIO_PORTF_DIR_R|=0x04;
    GPIO_PORTF_DEN_R|=0x04;
		GPIO_PORTF_AMSEL_R=0x00;
		GPIO_PORTF_PCTL_R=0x00000000;
} 
	

