#include <strings.h>          
#include <stdlib.h>          
#include <stdio.h>  
#include <unistd.h>        
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 3550 
#define BACKLOG 2 /* El número de conexiones permitidas */

#define MAXDATASIZE 100   
/* El número máximo de datos en bytes */

int main()
{

   int fd, fd2; 

   struct sockaddr_in server; 
   /* para la información de la dirección del servidor */

   struct sockaddr_in client; 
   /* para la información de la dirección del cliente */

   unsigned int sin_size;

   /* A continuación la llamada a socket() */
   if ((fd=socket(AF_INET, SOCK_STREAM, 0)) == -1 ) {  
      printf("error en socket()\n");
      exit(-1);
   }

   server.sin_family = AF_INET;         

   server.sin_port = htons(PORT); 

   server.sin_addr.s_addr = INADDR_ANY; 
   /* INADDR_ANY coloca nuestra dirección IP automáticamente */

   bzero(&(server.sin_zero),8); 
   /* escribimos ceros en el reto de la estructura */

   /* A continuación la llamada a bind() */
   if(bind(fd,(struct sockaddr*)&server,
           sizeof(struct sockaddr))==-1) {
      printf("error en bind() \n");
      exit(-1);
   }     

   if(listen(fd,BACKLOG) == -1) {  /* llamada a listen() */
      printf("error en listen()\n");
      exit(-1);
   }

   while(1) {
      sin_size=sizeof(struct sockaddr_in);
      /* A continuación la llamada a accept() */
      if ((fd2 = accept(fd,(struct sockaddr *)&client,
                        &sin_size))==-1) 
      {
         printf("error en accept()\n");
         exit(-1);
      }

      printf("Se obtuvo una conexión desde %s\n", (char *)inet_ntoa(client.sin_addr) ); 
      /* que mostrará la IP del cliente */

      send(fd2,"Bienvenido a mi servidor.\n",22,0); 
      /* que enviará el mensaje de bienvenida al cliente */

    int numbytes;
    char buf[MAXDATASIZE];  
    if ((numbytes=recv(fd2,buf,MAXDATASIZE,0)) == -1){  
    
	/* llamada a recv() */

      printf("Error en recv() \n");
      exit(-1);
   }	
   buf[numbytes]='\0';

   printf("Mensaje del Cliente:\n %s\nGuardando\n",buf);

    FILE* fp;
    fp = fopen("recibido.txt", "wt"); 
    fputs(buf,fp);
    fclose(fp);
    printf("Proceso completado");	
   close(fd2); /* cierra fd2 */

   }
}
