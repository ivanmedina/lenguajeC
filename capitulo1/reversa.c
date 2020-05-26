#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(int argc, char** argv)
{

  char s[100], r[100];
  int begin, end, count =0;
  printf("Input get a string\n");
  gets(s);

  while(s[count] != '\0')
    count++;

  end= count-1;
  for(begin = 0; begin < count; begin++)
  {
    r[begin]=s[end];
    end--;
  }

  r[begin]='\0';
  printf("%s\n",r);
  return 0;
  
}
