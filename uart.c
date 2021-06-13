#include "C:/Keil/Labware/inc/tm4c123gh6pm.h"
#include "stdint.h"
void SystemInit() {}
	
//Port D intialization (Used for UART2)
	void PortDInit(void){
		
	SYSCTL_RCGCGPIO_R |= 0x08;
	while((SYSCTL_PRGPIO_R & 0x08)==0){};
		
	GPIO_PORTD_LOCK_R = 0x4C4F434B;
	GPIO_PORTD_CR_R = 0xFF;
	GPIO_PORTD_AFSEL_R = 0xC0;
	GPIO_PORTD_PCTL_R = 0x11110000;
	GPIO_PORTD_DIR_R = 0xC0;
	GPIO_PORTD_DEN_R = 0xC0;                  //Pins 6 and 7 -> UART2.
	}
	
	
//UART2 initialization and functions
void UART2_INIT(void){
  SYSCTL_RCGCUART_R |= 0x04;
  SYSCTL_RCGCGPIO_R |= 0x08;
  UART2_CTL_R = 0;
  UART2_IBRD_R = 104;
  UART2_FBRD_R = 11;
  UART2_LCRH_R = (UART_LCRH_WLEN_8 | UART_LCRH_FEN);UART2_CTL_R |= (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);
  GPIO_PORTD_AFSEL_R |= 0xC0;
  GPIO_PORTD_PCTL_R = (GPIO_PORTD_PCTL_R&0xFFFFFF00) | (GPIO_PCTL_PD7_U2TX | GPIO_PCTL_PD6_U2RX);
  GPIO_PORTD_DEN_R |= 0xFF;
	}

	
uint8_t UART2_Available(void){
return ((UART2_FR_R&UART_FR_RXFE) == UART_FR_RXFE) ? 0 : 1;
}

uint8_t UART2_Read(void){
while(UART2_Available() != 1);
return (uint8_t)(UART2_DR_R&0xFF);
}

