#include <stdio.h>

int main(){
int eof = 0x30;
long nc;
int c;
while((c=getchar())!=eof)
{
	putchar(c);
	nc ++;

}

printf("%ld\n",nc);
}
