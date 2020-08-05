/*COMPUTER NETWORK OF THE CLIENT PROCESS*/



#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<string.h>
int main()
{
  int i,sockfd,n;
  char buf[100];
  char line[100],line1[200],sum[200];
  struct sockaddr_in sa_addr;

  sockfd=socket(AF_INET,SOCK_STREAM,0);


  sa_addr.sin_family=AF_INET;
  sa_addr.sin_addr.s_addr=inet_addr("127.0.0.1"); //Loop back IP address
  sa_addr.sin_port=htons(6000);

  bzero(sa_addr.sin_zero,8);


  i=connect(sockfd,(struct sockaddr *)&sa_addr,sizeof(sa_addr));
printf("connection Established successfully continue your operation\n");

/* After connection, the client can send or receive messages.*/
do{
printf("please write your message to the server:\n ");
scanf("%s",line);


send(sockfd,line,100,0);

//strcpy(line1,line);
n=recv(sockfd,line,100,0);
        printf("echo back from server is:\n %s\n",line);
}
while(strcpy(line,"quit"));


	
close(sockfd);

 return 0;
}
