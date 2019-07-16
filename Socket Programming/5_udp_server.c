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
struct sockaddr_in serv_addr,cli_addr;
char buffer[1024];
socklen_t addr_size;

sockfd=socket(AF_INET,SOCK_DGRAM,0);

serv_addr.sin_family=AF_INET;
serv_addr.sin_port=htons(8080);
serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");

bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
addr_size=sizeof(cli_addr);  //removed & before cli_addr

recvfrom(sockfd,buffer,1024,0,(struct sockaddr *)&cli_addr,&addr_size);
printf("received from client: %s",buffer);

sendto(sockfd,buffer,1024,0,(struct sockaddr *)&cli_addr,addr_size);
printf("sent to server: %s",buffer); 

close(sockfd);
return(0);
}