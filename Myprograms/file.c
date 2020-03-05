#include<stdio.h>
 
int main() {
 
   FILE *fp;
   char ch;
   int num;
   long length;
 
   printf("Enter the value of num : ");
   scanf("%d", &num);
 
   fp = fopen("/home/vishal/oiddata.txt", "r");
   if (fp == NULL) {
      puts("cannot open this file");
      exit(1);
   }
 
   fseek(fp, 0, SEEK_END);
   length = ftell(fp);
length-=2;
char *str;
   fseek(fp, (length - num), SEEK_SET);
fscanf(fp,"%s",str);
printf("%s",str);
  
   fclose(fp);
   return(0);
}
