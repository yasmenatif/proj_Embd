#include "stdint.h"
#include "C:/keil/tm4c123gh6pm.h"
#define MAXSIZE    100		/* GPS at most, sends 80 or so chars per message string.  So set maximum to 100 */
#define COM_PORT   1		/* Serial device connected to COM 1 */
#define SPEED      4800		/* baud rate = 4800 */
#define CR         0x0d
#define COMMA	  0x2C
#include "stdio.h"
#include "stdbool.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//#include "conio.h"
#include "math.h"
//#include "ibmcom3.h"
void SystemInit(){}

 
int main(void){
UARTInit();	


 

  
 unsigned int   j, k;				/* dummy variable */
  unsigned int	 i;		     		/* Number of chars read per GPS message string */
unsigned int ReadString;
	unsigned char pChar;
		double  Stringlongitude;
		unsigned int	longitudeDegrees;
			unsigned int longitudeMinutes; 
	unsigned int  lastCommaPosition;
	 unsigned intlongitude_ ;
	 double longitude;
   //Rest of parsing function
// Geting longitude 
	      pChar = ReadString;
	      j = lastCommaPosition + 1;
	      k = 0;
	      while(*(pChar+j) != COMMA) {
		   Stringlongitude[k] = *(pChar+j);
		   j++;
		   k++;
	      }
	      lastCommaPosition = j;
	      Stringlongitude[k] = '\0';
				//longitude = atof(Stringlongitude);
		    sscanf(Stringlongitude, "%f", &longitude);
	      longitudeDegrees = (int)(longitude/100);
	      longitudeMinutes = (double)(longitude - longitudeDegrees*100);
				longitude_ = longitudeDegrees + (longitudeMinutes/60);
	      

	      printf("/n");
	  } // else not a GPGGA sentence 

return (longitude_);
      } 
		 