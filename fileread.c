/**************************************************************************
fileread.c 


An example C program to read in a file, whose name is hard coded into 
the program. Then print out the lines preceded by a line number. 
At the end tell the user how many lines were in the file. 


***********************************************************************/


#include <stdio.h>
/* printf, fopen, fscanf fclose FILE NULL*/ 
#include <stdlib.h>
/* exit */
#include <unistd.h>
/* sleep */

#define MAX 25 /* for the maximum size of the string to pull from 
                   the file to be read */

int main(void)

{
  FILE *fp;
  char hunc[MAX];  /* Recall Fr. Kalck */  
  int i;

  printf("\n");
  printf("starting fileread program \n");

  if((fp = fopen("lengths","r"))==NULL) {
    printf("cannot open file \n");
    exit(1);
  }

  else {
    printf("Success, file opened! \n");
  }


  printf("Got past file opening \n");
  printf("\n");

  i=0;

  printf("10 second sleep coming.\n");
  sleep(10);

  /* use a while to read the file contents  */
  while (fgets(hunc,MAX,fp) !=NULL) 
    {
      i++; /* Show first  line as 1, second as 2, ... */ 
      printf("%u %s",i, hunc);
    }

  fclose(fp);
 
  printf("\n");
  printf("The file contained %u lines.\n",i);
  printf("\n");


}
