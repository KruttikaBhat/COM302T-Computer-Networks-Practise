#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>

int main()
{
  int s_socket,key[10];
  struct sockaddr_in server,client;
  char message[]="Key recieved";
  //create socket
  s_socket=socket(AF_INET,SOCK_DGRAM,0);
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
  puts("Waiting for incoming connections");
  int read_message,len=sizeof(client),l=0,i;
  read_message=recvfrom(s_socket,key,10,0,(struct sockaddr *)&client,&len);
  printf("Key sent by client is\n");
  for(i=0;key[i]!=0 && key[i]!=1 ;i++)
  {
    printf("%d",key[i]);
  }
  l=i;
  sendto(s_socket,message,strlen(message),0,(struct sockaddr *)&client,len);
  printf("Echo sent");

  return 0;

}
