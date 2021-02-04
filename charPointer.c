#include "stdio.h"

char str[] = "Pointers are fun";

main()
{
  char *p,*q;
  int i;

  p = str;/*Note that p = &str gives warning at compile*/
  q = &str[1];/*this works*/
  printf("%s\n",p);/*prints the string*/
  printf("%p\n",p);/*prints memory address in hex*/
  printf("%p\n",q);/*prints memory address one char over in hex*/
  /*loop until null is found*/
  for(i=0;p[i]; i++)
    printf("%c",p[i]);/*prints the string*/
  printf("\n");
}
