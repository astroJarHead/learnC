#include "stdio.h"
#include "string.h"

struct s_type {
  int i;
  char str[80];
} s, *p;

int main(void)
{
  p = &s;

  s.i = 10;
  p->i = 10;

  strcpy(p->str, "I like structures");

  printf("%d %d %s\n", s.i, p->i, s.str);
  printf("\n");

  strcpy(s.str,"I love structures");
  printf("%s \n",p->str);

  printf("Length of s.str is %d characters\n",strlen(p->str));
}
