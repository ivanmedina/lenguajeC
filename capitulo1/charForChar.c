#include <stdio.h>

//copiar entrada a salida
int main()
{	
	int eof = 0x30;	
	int c;
	while((c=getchar())!=eof)
	putchar(c);
		
}
