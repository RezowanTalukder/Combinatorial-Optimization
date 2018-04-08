#include <stdlib.h>
#include <stdio.h>


void print_ver(void);


void print_ver(void) 
{
    fprintf(stderr, "Lab Example: Command-line Arguments Handling\n"
		    "Institute of Information Technology\n"
		    "University of Dhaka, Dhaka, Bangladesh.\n"
		    "$ Version: 1.0; Date: 2018/04/04 $\n");
    return;
}



int main(int argc, char ** argv) 
{
  int index;

  print_ver();

  printf ("\n\targc = %d\n", argc);
  printf ("\n\targv\n");
  for (index = 0; index < argc; index++)
    printf ("\targ[%d] = %s\n", index, argv[index]);

  exit(0);
}

/*
########################################################## End
*/

