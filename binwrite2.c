#include "stdio.h"
#include "stdlib.h"

/*use define preprocessor directive to 
  set max array size*/

#define MAX 10

/*
Based on Example 2 section 9.5 of "Teach yourself C"
for writing and reading a binary file, and used to understand 
readnantcounts funciton in cobra.c


*/
/* these pointers are for memory to be assigned 
   via malloc */
char *pRec,*pBody;

/* initialize the integer array */
int d[MAX] = {
  10, 19, 1002, 12, 1, 
  11, 75, 0, 1, 875
};

int anum;

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
  for(i=0; i<MAX; i++) d[i] = -1;

  /*try to read file into a malloc space*/
 
  pBody = malloc(sizeof(d));

  /* read the entire array in one step   
     into the memory space pBody */
  if(fread(pBody, sizeof d, 1, fp)!=1) {
    printf("read error");
    exit(1);
  }

  printf("I created memory space pBody with size %d bytes \n",sizeof(d));
  printf("\n");

  fclose(fp); 
  pRec = pBody;

  /* Now, knowing an integer is 4 bytes, use a cast
     to loop through pRec and print out the integer
     values
  */
  for (i=0;i<4*MAX;i+=4){
    anum = *((short*)pRec);
    printf("At starting byte = %2d the value returned is %4d \n",i,anum);
    pRec+=4;
      }

  free(pBody);

}



