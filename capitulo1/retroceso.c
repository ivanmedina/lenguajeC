#include <stdio.h>
#include <stdbool.h>
/* count lines in input */
int main()
{  
    	int ch;

	while ((ch = getchar())!= EOF)
	{	fflush(stdin);
		getchar();
		fflush(stdin);
		if(ch=='\t')
		{
			putchar('<');
			putchar('\r');
			putchar('-');
			putchar('\n');

		}
		else if(ch!='\n')
		{	putchar(ch);
			putchar('\n');

		}
		else
		{
			putchar('<');
			putchar('\r');
			putchar('+');
			putchar('\n');

		}
		
	}
	return 0;
}
