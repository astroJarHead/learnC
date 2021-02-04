#include "stdio.h"
#include "stdlib.h"
/*
Section 7.5, modification to Example 1 of "Teach yourself C"
Shows usage of arguments passed to main in an effort to 
understand what is happening with readnatcounts in cobra.c
of OYSTER. 
*/

int main(int argc, char *argv[])
{
  int i;
  double d;
  long l;

  if(argc<4) {
    printf("usage: I need three input numbers\n");
    printf("try again \n");
    exit(1); /*stop program execution*/
  } 

  if(argc>4) {
    printf("usage: I will only convert first three numbers\n");
  } 

  i = atoi(argv[1]); /*atoi, atol, atof come from stdlib*/
  l = atol(argv[2]);
  d = atof(argv[3]);
  
  printf("Including program executable you passed %d arguments.\n",argc);
  printf("Program executable name: %s \n",argv[0]);
  printf(" the integer: %d\n the long: %ld\n the double: %lf\n", i, l, d);
}
