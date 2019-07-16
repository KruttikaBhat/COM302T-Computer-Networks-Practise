//echo
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
int main()
 {
  int server_socket=socket(AF_INET,SOCK_STREAM,0);
  struct sockaddr_in server_address;
  server_address.sin_family=AF_INET;
  server_address.sin_port=htons(3000);
  server_address.sin_addr.s_addr=INADDR_ANY;
  int r=bind(server_socket,(struct sockaddr *)&server_address,sizeof(struct sockaddr));
  if(r==0)
   printf("correct bind \n");
   else
  printf("no bind\n");
   listen(server_socket,3);
   int client_socket=accept(server_socket,NULL,NULL);
   char message[200];
   char request[200]; 
     strcpy(message,"");
   printf("enter then message to be sent to client");
   gets(message);
   printf("\n");
   send(client_socket,message,sizeof(message),0);
    //receiving
   recv(client_socket,request,sizeof(request),0);
  printf("message from client is:%s",request);
   return(0);
}
