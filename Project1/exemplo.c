#include <stdio.h>
#include <string.h>
 
 
 char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

int main()
{
   char arr[100] = {"123    "};
 
   printf("Reverse of the string is \n%s\n",strrev(arr));
 
   return 0;
}