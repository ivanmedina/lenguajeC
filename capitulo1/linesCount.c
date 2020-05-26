#include <stdio.h>
/* count lines in input */
int main()
{  
    int ch;
    int nl=0;
    while ((ch = getchar())!= EOF)
{		
	getchar();
        if (ch == '\n'){
	    ++nl;
		       }
}        
printf("%d\n", nl);
return 0;
}
