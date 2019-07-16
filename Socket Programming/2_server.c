//2. Write a socket program for implementation of echo. Server side
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>    //write
#include<string.h>
int main()
{
  int s_socket, client_accept;
  struct sockaddr_in server,client;
  char message[2000];
  //create socket
  s_socket=socket(AF_INET,SOCK_STREAM,0);
  if (s_socket==-1) {
    printf("Socket not created");
    return 1;
  }
  //assign values to sockaddr_in
  server.sin_addr.s_addr= INADDR_ANY;
  server.sin_port=htons( 8888 );
  server.sin_family=AF_INET;
  //bind(create an address between 2 nodes)
  if(bind(s_socket, (struct sockaddr *)&server, sizeof(server))<0)
  {
    puts("bind failed");
    return 1;
  }
  puts("bind done");
  //listen for any incoming connections (struct sockaddr *)&client,(socklen_t*)&c
  listen(s_socket,3);
  puts("Waiting for incoming connections");
  socklen_t c=sizeof(client);
  client_accept=accept(s_socket,(struct sockaddr *)&client,&c);
  if(client_accept<0)
  {
    puts("accept failed");
    return 1;
  }
  puts("Connection accepted");
  recv(client_accept,message,sizeof(message),0);
  send(client_accept, message,strlen(message),0);
  close(s_socket);
  return 0;

}
