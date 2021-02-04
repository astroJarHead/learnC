#include "stdio.h"

/* This shows how to use global variables to exchange data
   between functions, and how to use a non-implicit function 
   definition. It also illustrates the use of void
   to explicitly say a function has no parameters. */

float dollars, pounds, convert(void);

main(void)
{
  convert();
  printf("$%5.2f dollars = %5.2f pounds\n", dollars, pounds);
}

float convert(void)
{

  printf("Enter number of dollars to convert to pounds: ");
  scanf("%f", &dollars);
  printf("I will convert %f dollars to pounds.\n", dollars);
  /*printf("dollars/2.0 = %f \n", dollars/2.0);*/
  pounds = dollars/2.0;
  
}
