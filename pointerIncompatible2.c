#include "stdio.h"

main()
{
  int *p;
  float q, temp;

  temp = 1234.34F;

  p = &temp; /* try to put address od a float into integer pointer */
  q = *p;    /* now try to assign a value to a float variable */
  
  printf("This probably will not print 1234.34\n");
  printf("%f\n", q); /* This probably won't print 1234.34 */
}
  
  
