#include "stdio.h"

main()
{
  char *cp, ch;
  int *ip, i;
  float *fp, f;
  double *dp, d;

  cp = &ch;
  ip = &i;
  fp = &f;
  dp = &d;

  /*print the current values*/

  printf("%p %p %p %p\n", cp, ip, fp, dp);
  printf("%d %d %d %d\n", cp, ip, fp, dp);

  /*now increment them by one*/
  cp++;
  ip++;
  fp++;
  dp++;

  /*print their new values*/
  printf("   +1          +4        +4        +8\n");
  printf("%d %d %d %d\n", cp, ip, fp, dp);
  printf("%p %p %p %p\n", cp, ip, fp, dp);

}
