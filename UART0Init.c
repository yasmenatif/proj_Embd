#include "E:\Keil\EE319KwareSpring2021\inc\tm4c123gh6pm.h"
#include "stdint.h"
void SystemInit() {}
	
//Port A intialization (Used for UART0 and LCD control)
	void PortAInit(void){
		
	SYSCTL_RCGCGPIO_R |= 0x01;
  while((SYSCTL_PRGPIO_R & 0x01)==0){};
		
	GPIO_PORTA_LOCK_R = 0x4C4F434B;
	GPIO_PORTA_CR_R = 0xFF;
	GPIO_PORTA_AFSEL_R = 0x03;
	GPIO_PORTA_PCTL_R = 0x00000011;
	GPIO_PORTA_DIR_R = 0xE2;
	GPIO_PORTA_DEN_R = 0xE2;                  //Pins 0 and 1 -> UART0. Pins 5, 6, and 7 -> LCD control.
	}
	
	
//UART0 initialization and functions
void UART0_INIT(void)
{
  SYSCTL_RCGCUART_R |= 0x01;
  SYSCTL_RCGCGPIO_R |= 0x01;
  UART0_CTL_R &= ~UART_CTL_UARTEN;
  UART0_IBRD_R = 104;
  UART0_FBRD_R = 11;
  UART0_LCRH_R = (UART_LCRH_WLEN_8 | UART_LCRH_FEN);
  UART0_CTL_R |= (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);
  GPIO_PORTA_AFSEL_R |= 0x03;
  GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R&0xFFFFFF00) |  (GPIO_PCTL_PA1_U0TX | GPIO_PCTL_PA0_U0RX);
  GPIO_PORTA_DEN_R |= 0x03;
}


uint8_t UART0_Available(void){
return ((UART0_FR_R&UART_FR_RXFE) == UART_FR_RXFE) ? 0 : 1;
}

uint8_t UART0_Read(void){
while(UART0_Available() != 1);
return (uint8_t)(UART0_DR_R&0xFF);
}

void UART0_Write(uint8_t data){
while((UART0_FR_R&UART_FR_TXFF) != 0);
UART0_DR_R = data;
}
