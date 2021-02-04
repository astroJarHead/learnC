#include "stdio.h"  /* i/o stuff */
#include "stdlib.h" /* needed for exit */
#include "string.h" /* strcmp used */

/*
Solution to Exercise 3, Section 9.2 of "Teach yourself C"
I did not originally use strcmp but incorporated it after 
viewing the solution. I do add an error check on writing the 
output file which the author did not do.

Note that if in strcmp() two strings match, strcmp returns 0.
That's why the !strcmp and not strcmp is used in the if loop 
as we write to the output file.
*/

int main(int argc, char *argv[]) 
{

  FILE *fin,*fout;
  char ch;

   /* first make checks for correct number of 
     arguments */
   if(argc<3) {
    printf("usage: readwritewatch infile outfile [watch]\n");
    printf("not enough arguments\n");
    exit(1); /*stop program execution*/
   } 
   else if(argc>4) {
    printf("usage: readwritewatch infile outfile [watch]\n");
    printf("too many arguments\n");
    exit(1); /*stop program execution*/
   }
   
   /* open required files */
   if((fin = fopen(argv[1],"r")) ==NULL) {
     printf("Cannot open file %s for reading\n",argv[1]);
    exit(1);
   }

   if((fout = fopen(argv[2],"w")) ==NULL) {
     printf("Cannot open file %s for writing\n",argv[2]);
    exit(1);
   }

   /* now read in the characters and write them to the 
      output file eith an error test for writing included 
      for a graceful exit */

   while((ch = fgetc(fin)) != EOF) {
     if(fputc(ch, fout)==EOF) {
       printf("Error writing file\n");
       exit(1);
     }
     if(!strcmp(argv[3], "watch") && ch!='\n') {
       printf("I just wrote %c to %s\n",ch,argv[2]);
     }
   }

   fclose(fin);
   fclose(fout);
}
