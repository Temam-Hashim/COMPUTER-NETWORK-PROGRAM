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
  char line[100],num2[200],sum[200];
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
printf("enter the number to be reversed: ");
scanf("%s",line);
send(sockfd,line,strlen(line)+1,0); 

n=recv(sockfd,line,100,0);
        printf("Reverse number recieved from server=%s\n",line);
}

while(strcpy(line,"quite"));
	
close(sockfd);

 return 0;
}
