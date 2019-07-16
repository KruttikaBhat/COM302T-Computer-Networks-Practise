//4. Write a socket program for transferring files between client-server using TCP. Server side.
#include<stdio.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
int main()
{
  int serv_sock,accept_file;
  struct sockaddr_in server,client;
  //create socket
  serv_sock=socket(AF_INET,SOCK_STREAM,0);
  if(serv_sock<0)
  {
    perror("Socket not created");
    return 1;
  }
  puts("Socket created");
  server.sin_family=AF_INET;
  server.sin_port=htons(8000);
  server.sin_addr.s_addr=INADDR_ANY;
  //bind socket to port
  if(bind(serv_sock,(struct sockaddr*)&server,sizeof(server))<0)
  {
    perror("Not binded");
    return 1;
  }
  puts("Binded");
  //listen for connections
  listen(serv_sock,3);
  puts("Waiting for incoming connections...");
  socklen_t c=sizeof(client);
  //accept incoming connection
  accept_file=accept(serv_sock,(struct sockaddr*)&client,&c);
  if(accept_file<0)
  {
    perror("Accept failed");
    return 1;
  }
  puts("Accepted");
  char buffer[100];
  FILE *fp;
  //get data from client
  read(accept_file,buffer,100);
  fp=fopen("text1.txt","w");
  //write into new text file
  fprintf(fp, "%s",buffer );
  puts("File was recieved\nNew file created is text1.txt");
  return 0;
}
