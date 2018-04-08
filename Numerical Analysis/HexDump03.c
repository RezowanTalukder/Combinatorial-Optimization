#include <stdio.h>
#include "HexDump02.h"




int main() {
  int data, i, PktLength;
  unsigned char *pkt, PacketData[2048];

  // Get PCAP Global Header
  for (i=0; i<24; i++) {
    data = getchar();
    if (data == EOF ) {
      putchar('\n');
      return 0;
    }
    PacketData[i]=data & 0xFF;
  }
 
 // printf("\nPCAP Global Header:\n");
  
  pkt = PacketData;
  for (i=0; i<24; i++) {
    //PrintHex(*pkt++,i);
    
  }
  //putchar('\n');

  // Get PCAP Record Header
  
  int arpPacket = 0 ;
  int totalPacket = 0 ;
  int packetNo = 0;
  
  while(1){
  

	  for (i=0; i<16; i++) {
	    data = getchar();
	    if (data == EOF ) {
	        printf("\n") ;
		printf("ARP Pkt count: %d\n",arpPacket) ;
		printf("Tot Pkt count: %d\n",totalPacket) ;
	
		printf("\n\n") ;
	      return 0;
	      
	     
	    }
	    PacketData[i]=data & 0xFF;
	  }
	 
	
	  
	  pkt = PacketData;
	 

	  PktLength = *((unsigned int *)(pkt+8) ); 



	  // Get Packet 
	  
	  for (i=0; i<PktLength; i++) {
	    data = getchar();
	    if (data == EOF ) {
	      //putchar('\n');
	      return 0;
	      
	      
	    }
	    PacketData[i]=data & 0xFF;
	  }
	  
	 
	
	 
	 
	 totalPacket++ ;
	 
	 if(pkt[12]==8 && pkt[13]==6){
	    		arpPacket++ ;
	    		printf("[%04d] ",totalPacket) ;
	    		printf("Pkt Data:\n");
	  
	 		pkt = PacketData;
	 		
	  		for (i=0; i<PktLength; i++) {
	  			PrintHex(*pkt++,i);
	    		
	   		 }
	   		 
	   		 printf("\n") ;
	   		 
	   		 
	   		 printf(" Ether Header\n") ;
	  
			  printf("   Dst MAC") ;
			  for(int i=0 ;i<6 ;i++){
			  	printf(":") ;
			 	printf("%02X",PacketData[i]) ;
			 	
			 }
			 
			 putchar('\n') ;
			 
			 
			 
			 printf("   Src MAC") ;
			  for(int i=6 ;i<12 ;i++){
			  	printf(":") ;
			 	printf("%02X",PacketData[i]) ;
			 	
			 }
			 
			 putchar('\n') ;
			 
			 printf(" ARP:\n") ;
			 printf("   Type: ") ;
			 
			 
			 
			  int type = 0 ;
			  
			  if(PacketData[20]==0 && PacketData[21]==1){
			  	type = 1 ;
			  }
			  
			  if(type==1){
			  	printf("ArpReq\n") ;
			  }
			  else printf("ArpRep\n") ;
			  
			  putchar('\n') ;
			 
	  }
	  
	  
	 /* 
	  if(totalPacket==998){
	   
	  	printf("\n") ;
		printf("ARP Pkt count: %d\n",arpPacket) ;
		printf("Tot Pkt count: %d\n",totalPacket) ;
		
		printf("\n\n") ;
	
	  }	
	  
	 */  
	  
	}
	
    	
	
	
    return 0;
}


