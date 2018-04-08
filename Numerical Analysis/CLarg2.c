#include <stdlib.h>
#include <stdio.h>


void print_ver(void);
void print_use(char * binary);


void print_ver(void) 
{
    fprintf(stderr, "Lab Example: Command-line Arguments Handling\n"
		    "Institute of Information Technology\n"
		    "University of Dhaka, Dhaka, Bangladesh.\n"
		    "$ Version: 2.0; Date: 2018/04/04 $\n\n");
    return;
}


void print_use(char * binary) 
{
    fprintf(stderr, "usage:\n\t%s [-f] [-i val] [-c string] [-h] [-v]\n\n"
		    "  -f\t\tto set f option\n"
		    "  -i\t\tto set i option with the integer value \'val\'\n"
		    "  -c\t\tto set c option with the character value \'string\'\n"
		    "  -h\t\tPrint this help message\n"
		    "  -v\t\tPrint version\n\n", binary );
    return;
}


int main(int argc, char ** argv) 
{
  int i;
  int flagF=0, flagI=0, flagC=0, ival=0;
  char *cval;

  if (argc == 1) {
    print_use(argv[0]);
    exit(1);
  }

  for (i = 1; i < argc && argv[i][0] == '-' ; i++) {
    switch (argv[i][1]) {
      case 'f':
        flagF = 1;
        break;
      case 'i':
        flagI = 1;
        if (argv[++i] == NULL ) {
          printf("option needs a value\n");
	  print_use(argv[0]);
	  exit(1);
        }
        ival = atoi(argv[i]);
        break;
      case 'c':
        flagC = 1;
        if (argv[++i] == NULL ) {
          printf("option needs a value\n");
	  print_use(argv[0]);
	  exit(1);
        }
        cval = argv[i];
        break;
      case 'v':
        print_ver();
        exit(0);
      case '?':
      case 'h':
      	print_use(argv[0]);
      	exit(0);
      	break;
      default :
      	printf("Unknown option '%s'\n", argv[i]);
      	exit(1);
      	break;
    }
  }

  if (flagF == 1)
    printf("\tf option is \'SET\'\n");
  else
    printf("\tf option is \'NOT SET\'\n");

  if (flagI == 1)
    printf("\ti option is \'SET\' and value=%d\n",ival);
  else
    printf("\ti option is \'NOT SET\'\n");

  if (flagC == 1)
    printf("\tc option is \'SET\' and value=%s\n",cval);
  else
    printf("\tc option is \'NOT SET\'\n");


  exit(0);
}


/*
########################################################## End
*/

