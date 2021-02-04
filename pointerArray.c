#include "stdio.h"
/*
A short snippet of C code to illustrate the connection between
arrays and pointers. It prints array elements using 
pointer, array indices and finally prints the first element 
of an array by using a pointer without ().
*/
int a[3] = {1, 20, 30};

main()
{
  int *p;
 
  p = a;/*Recall that array without index is a pointer
          to the start of the array*/

  /*Print a's 3 elements using pointers*/
  printf("\n");
  printf("Values in a using a pointer %d %d %d\n", *p, *(p+1), *(p+2));
  printf("\n");
  

  /*Print a's 3 elements using a with indices*/
  printf("Values in a using a's indices %d %d %d\n", a[0], a[1], a[2]);
  printf("\n");
  
  /*Print a[0] using pointer without () */
  /*Note * has higher precedence than + operator*/
  printf("Watch the precedence %d %d %d\n", *p, *p+1, *p+2);
  printf("\n");

  /*Print addresses of a*/
  printf("Addresses %d %d %d %d\n", &a, &a[0], &a[1], &a[2]);
  printf("\n");

  /*Print addresses of a*/
  printf("Hexadecimal addresses %p %p %p %p\n", &a, &a[0], &a[1], &a[2]);
  printf("\n");

  /*Print address of a using p*/
  printf("address contained in p is %p \n", p);
  printf("\n");

  p++;

  /*Print p after a p+*/
  printf("p after a p++ is %d or in hex %p\n", p, p);
  printf("\n");


}
 
 
  
