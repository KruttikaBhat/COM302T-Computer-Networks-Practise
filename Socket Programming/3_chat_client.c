#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>    //write
#include<string.h>
int main()
{
  int c_socket,a;
  char client_message[2000];
  struct sockaddr_in server;
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
  printf("Start a conversation\n");
  //send and recieve data
  while(1)
  {
    char server_message[2000]={0};
    printf("\nYou: ");
    fgets(client_message,sizeof(client_message),stdin);
    send(c_socket,client_message,strlen(client_message),0);
    recv(c_socket,server_message,sizeof(server_message),0);
    printf("Server: %s",server_message);
  }
  close(c_socket);
  return 0;
}
