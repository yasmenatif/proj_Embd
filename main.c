#include "stdint.h"
#include "E:/Keil/EE319KwareSpring2021/inc/tm4c123gh6pm.h"

int distance; 
int main(void){
	
	
	SYSCTL_RCGCGPIO_R |=0x20;
	while ((SYSCTL_PRGPIO_R&0x20)==0){};
	GPIO_PORTF_LOCK_R = 0x4C4F434B;
  GPIO_PORTF_CR_R |= 0x04;               
  GPIO_PORTF_AMSEL_R = 0x00;        
  GPIO_PORTF_PCTL_R = 0x00000000;  
  GPIO_PORTF_DIR_R |= 0x04;            
  GPIO_PORTF_AFSEL_R &= ~0x04;                     
  GPIO_PORTF_DEN_R |= 0x04; 	
	
	distance = 101;
	if (distance >= 100) {
	   GPIO_PORTF_DATA_R |= 0x04;  //turn blue LED on if distance is bigger than or equal to 10
	 } else if (distance < 100){                        
          GPIO_PORTF_DATA_R &= ~0x04;  //turn blue LED off otherwise
	 }
	 
}
	
	

