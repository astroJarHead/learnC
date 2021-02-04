#include "stdio.h"
/*
Snippet of C code to illustrate the problem 
that can occur when pointers are not of campatible types. 
gcc lets this compile but not the result printed 
for the memory addresses are different.
*/
main()
{
  int q;
  int *p;
  float *fp;
  
  p  = &q;
  fp = &q;

  printf("Address of q in fp is %f\n",fp);
  printf("Address of q in p  is %d\n",p);
    }
