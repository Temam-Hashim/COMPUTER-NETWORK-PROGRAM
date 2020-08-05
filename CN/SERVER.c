/*NETWORK PROGRAMMING WITH SOCKETS FOR SERVER*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<string.h>
int main()
{
int sockfd, length,i;
unsigned int fd1;
char buf[100]; /* We will use this buffer for communication */
struct sockaddr_in sa_addr,cl_addr;

sockfd=socket(AF_INET,SOCK_STREAM,0);

 sa_addr.sin_family=AF_INET;
 sa_addr.sin_addr.s_addr=INADDR_ANY;
 sa_addr.sin_port=htons(6000);

 memset(sa_addr.sin_zero, '\0', sizeof (sa_addr.sin_zero));
                                                            

 i=bind(sockfd,(struct sockaddr *)&sa_addr,sizeof(sa_addr));
 printf("test %d%d\n",sockfd,i);


 listen(sockfd,5);



 length=sizeof(cl_addr);
 fd1=accept(sockfd, (struct sockaddr *) &cl_addr,&length);

 for(i=0; i < 100; i++) buf[i] = '\0';
			strcpy(buf,"Message from server");
			send(fd1, buf, 100, 0);


for(i=0; i < 100; i++) buf[i] = '\0';
			recv(fd1, buf, 100, 0);
			printf("%s\n", buf);

close(fd1);

return 0;

 }
