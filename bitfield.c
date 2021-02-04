#include "stdio.h"

struct s_type{
  signed a: 3;
  signed b: 3;
  signed c: 2;
} s, *p;

int main(void)
{

  p = &s;  /* skip this get segmentation fault below at p->b*/

  s.a = 3; /* try to make this 10, won't compile! */
  s.b = -3;
  s.c =0;

  printf("s.a = %d \n",s.a);
  printf("s.b = %d \n",p->b);
  printf("s.c = %d \n",s.c);

}
  
