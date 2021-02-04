#include "stdio.h"

main()
{
  char str[] = "This is a test";
  *(str+3) =  'c';
  *(str+2) =  'b';
  *(str+1) =  'a';
  
  printf("%c\n",*(str+3));
  printf("%c %c %c %c\n",str[0],str[1],str[2],str[3]);
  printf("%s\n",str);
  printf("\n");

  char *p;

  p = "one two three";

  printf("%s\n",p);
  printf("%p\n",&p);
  printf("%d\n",&p);  

}
