#include "stdio.h"
#include "stdlib.h"
/*
Here I took Example 1 starting on page 292 of 
"Teach Yourself C" and used the efficiency modifications
of page 297 It demonstartes, in the file read back, 
a very efficient way to combine variable assisgnment 
and a comparison within a loop.
*/
char str[80] = "This is a file system test";

int main(void)
{
 FILE *fp;
 char ch, *p;
 int j = 0;
 
 /* open myfile for output */
 if((fp = fopen("myfile","w")) ==NULL) {
   printf("Cannot open file\n");
     exit(1);
 }

 /* write string to disk */
 /* fputc writes byte by byte */
 /* the printf on screen gets progressively shorter */
 p = str;
 while(*p) {
   if(fputc(*p++, fp)==EOF) {
     printf("Error writing file\n");
     exit(1);
   }
   printf("for j = %2d p is %s\n",j,p);
   j++;
 }
 fclose(fp);

 /* open myfile for input */
 if((fp = fopen("myfile","r"))==NULL) {
   printf("Cannot open file\n");
   exit(1);
 }

 /* read back the file */
 /* 
    notice how the return value of fgetc() 
    is equal to (ch = fgetc(fp))
    and makes for an efficient loop 
 */
 while((ch = fgetc(fp)) != EOF) putchar(ch);
 printf("\n");
 fclose(fp); 

}
