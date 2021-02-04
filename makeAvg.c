#include "stdio.h"
/*
From chapter 7.1, Exercise 1 in "Teach Yourself C"
Program queries a user for 10 numbers and using a 
function it returns the average of these numbers.

It is not exactly what they wanted as my avg only computes 
an average. But, by use of global variables I don't 
have to pass any arguments to function avg()
*/

double avg();
int max = 10; /*Set number of times to ask for numbers*/
float asum;

main()
{
  int i;
  float anavg,count,fmax,getnum;

  asum = 0.0;  
 
  for(i=0; i<max; i++){
   printf("Enter a number: ");
   scanf("%f",&getnum);
   printf("%f\n",getnum);
   asum = asum + getnum;
  }
  printf("asum = %.3f for call to function doavg \n",asum);
  anavg = avg();
  printf("Average is %.3f \n",anavg); 
}

double avg()
{
  return asum/max;
}
