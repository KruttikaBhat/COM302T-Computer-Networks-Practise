//echo
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
int main()
 {
  int client_socket=socket(AF_INET,SOCK_STREAM,0);
  struct sockaddr_in server_address;
  server_address.sin_family=AF_INET;
  server_address.sin_port=htons(3000);
  server_address.sin_addr.s_addr=INADDR_ANY;
  if(connect(client_socket,(struct sockaddr *)&server_address,sizeof(struct sockaddr))==0)
  
    printf("connected\n");
   else
    printf("no connected\n"); 
     char react[200],request[200];
   recv(client_socket,&react,sizeof(react),0); 
   printf("the message from server is:%s",react);
   send(client_socket,react,sizeof(react),0);
    close(client_socket); 
 return(0);
 }





