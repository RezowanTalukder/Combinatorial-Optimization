#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


void print_ver(void);
void print_use(char * binary);


void print_ver(void) 
{
    fprintf(stderr, "Read pcap file\n"
    		    "Name:Rezowan Talukder,Roll:0933\n"
    		    "Lab Example: Command-line Arguments Handling\n"
		    "Institute of Information Technology\n"
		    "University of Dhaka, Dhaka, Bangladesh.\n"
		    "$ Version: 3.0; Date: 2018/04/04 $\n\n");
    return;
}


void print_use(char * binary) 
{
    fprintf(stderr, "usage:\n\t%s [-f] [-i val] [-c string] [-h] [-v] StrArg\n\n"
		    "  -a\t\tPrint ARP data\n"
		    "  -e\t\tPrint Ethernet Header Data\'val\'\n"
		    "  -g\t\tPrint PCAP Global Header Data\'string\'\n"
		    "  -h\t\tPrint this help message\n"
		    "  -p 0  \tPrint all packet data\n"
		    "  -p 1  \tPrint only APP packet Data\n"
		    "  -r\t\tPrint PCAP Record Header Data\n"
		    "  -v\t\tPrint Version\n"
		    "  pcap file\tFile Name of the PCAP file\n\n", binary );
    return;
}


int main(int argc, char ** argv) 
{
  int opt, index;
  int flagA=0, flagE=0, flagH=0, ivaV=0 ,flagG = 0 ;
  char *cval, *strarg;

  if (argc == 1) {
    print_use(argv[0]);
    exit(1);
  }

  while ((opt = getopt(argc, argv, "fi:c:hv")) != -1) {
    switch (opt) {
      case 'g':
      	flagG = 1 ;
      	break ;
      case 'a':
        flagA = 1;
        break;
     /* case 'e':
        flagE = 1;
        ival = atoi(optarg);
        break;
      case 'v':
        ivaV = 1;
        cval = optarg;
        break;*/
      case 'h':
        print_use(argv[0]);
        exit(0);
      case 'v':
        print_ver();
        exit(0);
      case ':':
        printf("option needs a value\n");
        print_use(argv[0]);
        exit(1);
      case '?':
      default :
        printf("unknown option: %c\n",optopt);
        print_use(argv[0]);
        exit(1);
    }
    
    if(flagG==1)
  	printf("\t Print PCAP file Global header\n") ;
  }

  if ( argc <= optind ) {
     print_use(argv[0]);
     exit(0);
  }
  strarg=argv[optind++];

  if(flagG==1)
  	printf("\t Print PCAP file Global header\n") ;
  
  if (flagA == 1)
    printf("\tf option is \'SET\'\n");
  else
    printf("\tf option is \'NOT SET\'\n");
/*
  if (ivaV == 1)
    printf("\ti option is \'SET\' and value=%d\n",ival);
  else
    printf("\ti option is \'NOT SET\'\n");
*/
  if (flagH == 1)
    printf("\tc option is \'SET\' and value=%s\n",cval);
  else
    printf("\tc option is \'NOT SET\'\n");
  

  printf ("\tFile Name of the PCAP file Name %s\n\n", strarg);


 for (index = optind; index < argc; index++)
    printf ("extra Non-option argument %s\n", argv[index]);

  exit(0);
}


/*
########################################################## End
*/

