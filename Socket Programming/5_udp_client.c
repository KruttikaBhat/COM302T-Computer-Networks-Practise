#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

int main()
{
 
 int sockfd;
 struct sockaddr_in server_addr;
char buffer[1024];
socklen_t addr_size;

sockfd=socket(AF_INET,SOCK_DGRAM,0);

server_addr.sin_family=AF_INET;
server_addr.sin_port=htons(8080);
server_addr.sin_addr.s_addr=inet_addr("127.0.0.1");

strcpy(buffer,"Hello \n");
sendto(sockfd,buffer,1024,0,(struct sockaddr *)&server_addr,sizeof(server_addr));
printf("sent to server: %s",buffer);

addr_size=sizeof(server_addr);
recvfrom(sockfd,buffer,1024,0,(struct sockaddr *)&server_addr,&addr_size);
printf("received from server: %s",buffer);

close(sockfd);  
return(0);
}