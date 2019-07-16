//2. Write a socket program for implementation of echo. Client side
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>    //write
#include<string.h>
int main()
{
  int c_socket;
  struct sockaddr_in server;
  char message[2000],server_reply[2000];
  //create socket
  c_socket=socket(AF_INET,SOCK_STREAM,0);
  if (c_socket==-1) {
    printf("Socket not created");
  }
  //assign values to sockaddr_in
  server.sin_addr.s_addr= INADDR_ANY;
  server.sin_port=htons( 8888 );
  server.sin_family=AF_INET;
  //connect to server
  if(connect(c_socket, (struct sockaddr *)&server, sizeof(server))<0)
  {
    puts("connection failed");
    return 1;
  }
  puts("connection done");
  printf("Enter a message\n");
  fgets(message,strlen(message),stdin);
  send(c_socket,message,strlen(message),0);
  recv(c_socket,server_reply,sizeof(message),0);
  printf("Server: %s",server_reply);
  close(c_socket);
  return 0;
}
