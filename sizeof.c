#include <stdio.h>
/*
Code copied from a discussion at

http://forums.macosxhints.com/archive/index.php/t-62551.html
as made by tji and is used to examine the size of different
data types and see if the output is compatible with 
a 32 bit or 64 bit architecture.

32 bit will yield:
char = 1 bytes
integer = 4 bytes
Long integer = 4 bytes
Long long integer = Double = 8 bytes
pointer = 4 bytes

64 bit yields:
Char = 1 bytes
Integer = 4 bytes
Long integer = 8 bytes
Long Long Integer = 8 bytes
Double = 8 bytes
Pointer = 8 bytes

I can get a 64 bit mode by forcing it with compiler 
option -m64 on macbok argo. The OS X compiler defaults to 
32 bit.

Thus to get 32 bit output on argo
gcc -o sizeof sizeof.c

To get 64 bit mode on argo
gcc -m64 -o sizeof sizeof.c 
  
*/
main()
{
  int i=0;
  long int li=0;
  long long int lli=0;
  double d=0;
  char c;
  char * p;

  /* make a structure s with tag name s_type 
     and show size*/
  
  struct s_type {
    int i ;
    char ch ;
    double d;
    char str[80];
  } s;

  printf("\nSize of Data Types on this System:\n\n");
  /*---------------------------------------*/
  printf("Char = %d bytes\n",sizeof(c));
  printf("Integer = %d bytes\n",sizeof(i));
  printf("Long Integer = %d bytes\n",sizeof(li));
  printf("Long Long Integer = %d bytes\n",sizeof(lli));
  printf("Double = %d bytes\n",sizeof(d));
  printf("Pointer = %d bytes\n",sizeof(p));
  printf("Structure s = %d bytes\n",sizeof(s));
  printf("Size of a unsigned short = %d bytes\n",sizeof(unsigned short));
  printf("Size of a unsigned char = %d bytes\n",sizeof(unsigned char));
  printf("Size of a unsigned long = %d bytes\n",sizeof(unsigned long));
  printf("Size of a float = %d bytes\n",sizeof(float));
  printf("Size of a double = %d bytes\n",sizeof(double));

  printf("\nSize of Data Types for cobra.c:\n\n");
  printf("Size of a short = %d bytes\n",sizeof(short));
  printf("Size of an Integer = %d bytes\n",sizeof(i));
  printf("Size of a unsigned char = %d bytes\n",sizeof(unsigned char));
  printf("Size of a unsigned short = %d bytes\n",sizeof(unsigned short));
  printf("Size of a unsigned int = %d bytes\n",sizeof(unsigned int));

}
