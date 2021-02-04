#include "stdio.h"
 
main()
{
  float sqr;

  sqr = get_sqr();
  printf("square: %f\n", sqr);
}

get_sqr()
{
  float num;

  printf("enter a number: ");
  scanf("%f", &num);
  printf("%f\n", num);
  printf("%f\n", num*num);
  return num*num; /* square the number */
}
