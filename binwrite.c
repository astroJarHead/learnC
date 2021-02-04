#include "stdio.h"
#include "stdlib.h" /* needed for exit(1) */
/*
Example 2 section 9.5 of "Teach yourself C"
for writing and reading a binary file.

This will, on medea, produce an 80 byte file
as doubles are 8 bytes, and there are 10 numbers 
in the array to go into the file.

This compares to 100 bytes for an ascii text file 
containing the 10 numbers, or 101 for 10 numbers 
and a carriage return.

Note that the array d and the binary file are both 
80 bytes, as expected.

It also demonstrates the use of ftell() and fseek()
for accessing binary files.
*/


double d[10] = {
  10.23, 19.87, 1002.23, 12.9, 0.897, 
  11.45, 75.34, 0.0, 1.01, 875.875
};
double anum;
int thestart;

int main(void)
{
  int i;
  FILE *fp;

  if((fp = fopen("myfile","wb"))==NULL) {
    printf("cannot open file");
    exit(1);
  }

  /* write the entire array in one step */
  if(fwrite(d, sizeof d, 1, fp)!=1) {
    printf("write error");
    exit(1); 
  }
  fclose(fp);

  if((fp = fopen("myfile", "rb"))==NULL) {
    printf("cannot open file");
    exit(1);
  }

  /* clear the array */
  for(i=0; i<10; i++) d[i] = -1.0;

  /* read the entire array in one step */
  if(fread(d, sizeof d, 1, fp)!=1) {
    printf("read error");
    exit(1);
  }

  if(fseek(fp, 24, SEEK_SET)) {
    printf("fseek problem \n"); 
    exit(1);
  }
  thestart=ftell(fp);
  printf("I am at byte %d in myfile \n",thestart);
  fread(&anum, sizeof(double), 1, fp);
  printf("And fread at the %d byte location returns %lf \n",thestart,anum);
  fclose(fp);
 
  /* display the array */
  printf("**********\n");
  printf("Byte locations at start:\n");
  printf("0         8         16          24        32       40        48        56       64       72\n");
  for(i=0; i<10; i++) printf("%lf ", d[i]);
  printf("\n");
  printf("array d has size of %d bytes\n",sizeof(d));
}
