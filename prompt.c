#include "stdio.h"

void prompt(char *msg, int *num);

int main(void)
{
  int i;
  prompt("Enter a number: ", &i);
  printf("Your number is: %d\n", i);
}

void prompt(char *msg, int *num)
{
  printf(msg);
  scanf("%d",num);
}
