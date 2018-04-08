#include <stdio.h>
#include "HexDump02.h"



int PrintHex(unsigned char c, int i) {
  if (i == 0 ) {
    //printf("%06X  ", i);
  } 
  
  else {
    if (i%16 == 0)
      //printf("\n%06X  ", i);
      printf("\n") ;
    else if (i%16 == 8)
      printf(" -- ");
    else
      printf(" ");
  }    

  printf("%02X", c);
  return 0;
}






	 //start
	 
	 /*
	 
	 printf("packet No : %d\n",++packetNo) ;
	 
	 for(int i=0 ;i<12 ;i++){
	 	data = getchar();
	 	if (data == EOF ) {
	     		putchar('\n');
	      		return 0;
	   	 }
	        PacketData[i]=data & 0xFF;
	   	PrintHex(*pkt++,i);
	 }
	 
	 printf("\nARP BYTE :: ") ;
	 
	 for(int i=0 ;i<2 ;i++){
	 	data = getchar();
	 	PacketData[i]=data & 0xFF;
	 	PrintHex(*pkt++,i);
	 	arpPacket++ ;
	 	
	 }
	 
	 printf("\n") ;
	 
	 
	 totalPacket++ ;
	 
	 
	 
	 */
	 //end
	 
	 /*
	 
	 /////////////////////
	 
	 
	 for(int i=0 ;i<12 ;i++){
	 	data = getchar();
	 	if (data == EOF ) {
	     		putchar('\n');
	      		return 0;
	   	 }
	        PacketData[i]=data & 0xFF;
	   	PrintHex(*pkt++,i);
	 }
	 
	 printf("\nARP BYTE :: ") ;
	 
	 for(int i=0 ;i<2 ;i++){
	 	data = getchar();
	 	PacketData[i]=data & 0xFF;
	 	PrintHex(*pkt++,i);
	 	arpPacket++ ;
	 	
	 }
	 
	 printf("\n") ;
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 */
	 
	 
	 
