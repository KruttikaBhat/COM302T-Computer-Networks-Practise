#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main()
{
  int c_socket,n,l,data[20],key[10];
  struct sockaddr_in server;
  char message[2000];
  //create socket
  c_socket=socket(AF_INET,SOCK_DGRAM,0);
  if (c_socket==-1) {
    printf("Socket not created");
    return 1;
  }
  //assign values to sockaddr_in
  server.sin_addr.s_addr= INADDR_ANY;
  server.sin_port=htons( 8888 );
  server.sin_family=AF_INET;
  int read_message,len=sizeof(server),i;
  printf("Enter the length of the data and the key: ");
  scanf("%d %d",&n,&l);
  printf("Enter the data\n");
  for(i=0;i<n;i++)
    scanf("%d",&data[i]);
  printf("Enter the key\n");
  for(i=0;i<l;i++)
    scanf("%d",&key[i]);
  key[l]=l;
  sendto(c_socket,key,10,0,(struct sockaddr *)&server,len);
  read_message=recvfrom(c_socket,message,2000,0,(struct sockaddr *)&server,&len);
  printf("Server: %s\n",message);
  close(c_socket);
  return 0;

}
