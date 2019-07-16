//4. Write a socket program for transferring files between client-server using TCP. Client side.
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
int main()
{
  int cli_sock;
  struct sockaddr_in server;
  //create socket
  cli_sock=socket(AF_INET,SOCK_STREAM,0);
  if(cli_sock<0)
  {
    perror("Socket not created");
    return 1;
  }
  puts("Socket created");
  server.sin_family=AF_INET;
  server.sin_port=htons(8000);
  server.sin_addr.s_addr=INADDR_ANY;
  //connect to server
  if(connect(cli_sock,(struct sockaddr*)&server,sizeof(server))<0)
  {
    perror("Connection failed");
    return 1;
  }
  puts("Connection done");
  char buffer[100];
  FILE *fp;
  fp=fopen("text.txt","r");
  //read the file and copy text into buffer
  while(fread(buffer,sizeof(buffer),1,fp)==1)
  {
      write(cli_sock,buffer,100);
  }
  //end of file is written
  write(cli_sock,&buffer,100);
  puts("File text.txt was sent successfully");
  return 0;
}
