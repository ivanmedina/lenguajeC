#include <stdio.h>
/* count lines in input */
int main()
{  
    int ch;
    int nl=0;
    int nt=0;
    int nb=0;
    while ((ch = getchar())!= EOF)
{		
	getchar();
        if (ch == '\n'){
	    ++nl;
		       }
	else if (ch == '\t'){
	    ++nt;
		       }
	else if (ch == ' '){
	    ++nb;
		       }	

}        
printf("Numero de lineas: %d\n", nl);
printf("Numero de tabuladores: %d\n", nt);
printf("Numero de espacios: %d\n", nb);
return 0;
}
