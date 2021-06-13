#include "stdint.h"
#include "C:/keil/tm4c123gh6pm.h"

#include "stdio.h"
#include "stdbool.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
//#include "ibmcom3.h"
void SystemInit(){}

 #define COM_PORT   3		/* Serial device connected to COM 3*/
#define SPACE	  0x20
#define COMMA	  0x2C
#define MAXSIZE    100		/* GPS at most, sends 80 or so chars per message string.  So set maximum to 100 */

#define CR         0x0d
#define LF         0x0a
#define pi 3.14159265358979323846

	
unsigned char  charRead;	     		
unsigned char	 ReadString[MAXSIZE]; 		/* Buffer collects chars read from GPS */
unsigned char  Stringtemp[MAXSIZE];
  
unsigned char  Stringlatitude[11];
unsigned char  StringlatitudeCardinal[3];
unsigned char  Stringlongitude[12];
unsigned char  StringlongitudeCardinal[3];

unsigned char  *pChar;
unsigned char  dummyChar;
  

unsigned  char lastCommaPosition;
double latitude;
int	  latitudeDegrees;
double	latitudeMinutes;

double longitude;
int		longitudeDegrees;
double	longitudeMinutes;
unsigned int   j, k;				
unsigned int	 i;		     		//chars read per GPS message string 
unsigned int	 LinesReadNO;        		// Number of GPS stringlines read
double longitude_;
double latitude_;
int main(void){
UARTInit();	
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

return(longitude_);
      } 
		 