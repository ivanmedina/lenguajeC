#include <strings.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>  
#include <arpa/inet.h>      

#define PORT 3550         

#define MAXDATASIZE 100   
/* El número máximo de datos en bytes */

int main(int argc, char *argv[])
{
   

   char buf[MAXDATASIZE];  
   /* en donde es almacenará el texto recibido */

   struct hostent *he;         
   /* estructura que recibirá información sobre el nodo remoto */

   struct sockaddr_in server;  
   /* información sobre la dirección del servidor */



   if (argc !=3) 
   { 
      /* esto es porque nuestro programa sólo necesitará un
      argumento, (la IP) ****** esti cambiara*/
      printf("Uso: %s <Dirección IP> <noombre archivo>\n",argv[0]);
      exit(-1);
   }


   /* Valida que exista el archivo*/

  FILE *fp;
  fp=fopen(argv[2],"r");
  int cantidadDeBytes;

  if(fp==NULL)
   { printf(" File does not exist or can not be opened\n");
    exit(-1);
   }

	    fseek( fp, 0, SEEK_END);
	    cantidadDeBytes = ftell(fp);
	    fclose(fp);
            fp=fopen(argv[2],"r");	
	    char mensaje[cantidadDeBytes];	      

	    if (cantidadDeBytes<100)
		{
			char ch;
		        printf("Tamaño de archivo: %d\n",cantidadDeBytes);

                        char *pm; /*pm es un puntero a mensaje para copiar el mensaje ahi*/
			pm= mensaje;
   			/* Valida que el tamaño mensaje del archivo sea mayor a 0 y menor de 100 bytes*/
			ch=fgetc(fp);
			*pm =ch;
			*pm++;
			while(ch  != EOF)
	    		{  /* Leer archivo y copiar mensaje */
				printf("%c",ch);
				ch=fgetc(fp);
				if(ch != EOF){
				*pm =ch;
				*pm++;}
	    		}
			printf("%s",mensaje);
			fclose(fp);
        	}
		
		
	    else
		{
		printf("Tamaño de archvio debe ser menor a 100 Bytes\n Tamaño de archivo: %d\n",cantidadDeBytes);
		}
    //else de : if(fp==NULL)
   int fd, numbytes;    
   if ((he=gethostbyname(argv[1]))==NULL)
   {       
      /* llamada a gethostbyname() */
      printf("gethostbyname() error\n");
      exit(-1);
   }

   if ((fd=socket(AF_INET, SOCK_STREAM, 0))==-1)
   {  
      /* llamada a socket() */
      printf("socket() error\n");
      exit(-1);
   }

   server.sin_family = AF_INET;
   server.sin_port = htons(PORT); 
   /* htons() es necesaria nuevamente ;-o */
   server.sin_addr = *((struct in_addr *)he->h_addr);  
   /*he->h_addr pasa la información de ``*he'' a "h_addr" */
   bzero(&(server.sin_zero),8);

   if(connect(fd, (struct sockaddr *)&server,
      sizeof(struct sockaddr))==-1){ 
      /* llamada a connect() */
      printf("connect() error\n");
      exit(-1);
   }

   if ((numbytes=recv(fd,buf,MAXDATASIZE,0)) == -1){  
    
	/* llamada a recv() */

      printf("Error en recv() \n");
      exit(-1);
   }

   
   buf[numbytes]='\0';

   printf("Mensaje del Servidor: %s\n",buf); 
   /* muestra el mensaje de bienvenida del servidor =) */

   send(fd,mensaje,cantidadDeBytes,0); 

   close(fd);   /* cerramos fd =) */

}


