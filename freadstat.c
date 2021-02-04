/**************************************************************************
freadstat.c

A program to test reading and using function stat on a file.
Written to help understand the problem with pktlist 
having problems using fstat on a binary NPOI rawdata 
file.



modification history:
---------------------
28-Dec-2020 BZ copied fileread.c -> freadstat.c as a start

***********************************************************************/

/* includes */

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>   /* strerror needs this .h */
#include <errno.h>    /* errno needs this .h    */

#define MAX 25

int main(void)

  {

  struct stat file_stat; /* Declare file_stat  of type stat */

  FILE *fp;    /* a file pointer fp to perform operations on file*/
char pktlength[MAX];
  int i,listLines=24336;

  /* open file, return error if there's a problem */

  if((fp = fopen("lengths","r"))==NULL) {
      printf("cannot open file");
      exit(1);
    }

  
  if( stat("lengths", &file_stat) ==-1)
    fprintf(stderr, "%s\n", strerror(errno));
  else
    {
      fprintf(stdout, "Links\tUid\tGid\tSize\tName\n");
      fprintf(stdout, "%u\t%u\t%u\t%u\t lengths \n", file_stat.st_nlink,
	  file_stat.st_uid,file_stat.st_gid,file_stat.st_size);
    }
  


  for(i=0;i<listLines;i++){
      fscanf(fp, "%s ",pktlength);
      printf("%s \n", pktlength);
    }
  
  fclose(fp);

}
