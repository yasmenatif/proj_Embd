#include "stdint.h"
#include "E:/Keil/EE319KwareSpring2021/inc/tm4c123gh6pm.h"

int distance; 
int main(void){
	
	
	
	distance = 101;
	if (distance >= 100) {
	   GPIO_PORTF_DATA_R |= 0x04;  //turn blue LED on if distance is bigger than or equal to 10
	 } else if (distance < 100){                        
          GPIO_PORTF_DATA_R &= ~0x04;  //turn blue LED off otherwise
	 }
	 
}
	
	

