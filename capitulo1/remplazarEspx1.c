#include <stdio.h>
#include <stdbool.h>
/* count lines in input */
int main()
{  
    	int ch;
    	bool esp=false;
	while ((ch = getchar())!= EOF)
	{		
		getchar();
		if (esp==false)
		{
			if (ch!=' ')
			{
				putchar(ch);
				putchar('\n');
				esp=false;
			}
 	    		else
			{
			putchar(ch);

			esp=true;
			}
		}
		else{
			if (ch!=' ')
			{
				putchar(ch);
			 	putchar('\n');
				esp=false;
			}
 	    		else
			{

			esp=true;
			}		
		}
	}        

	return 0;
}
