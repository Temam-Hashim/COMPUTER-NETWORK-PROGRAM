/*COMPUTER NETWORK OF THE CLIENT PROCESS*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<string.h>

struct student{
char name[100];
int roll;
int mark;
}; 

int main()
{
  struct student s[5];

  int i,sockfd,n,a,b,c,num;
  char line[100],line1[100],line2[100];
  struct sockaddr_in sa_addr;
 

  sockfd=socket(AF_INET,SOCK_STREAM,0);

  sa_addr.sin_family=AF_INET;
  sa_addr.sin_addr.s_addr=inet_addr("127.0.0.1"); //Loop back IP address
  sa_addr.sin_port=htons(6000);

 memset(sa_addr.sin_zero,'\0',sizeof(sa_addr.sin_zero));


  b=connect(sockfd,(struct sockaddr *)&sa_addr,sizeof(sa_addr));
/* After connection, the client can send or receive messages.*/
//do{


printf("please enter the roll number?\n");
scanf("%d",&num);

send(sockfd,&num,4,0);

recv(sockfd,s,sizeof(s),0);

printf("rollno=%d\n  name=%s\n mark=%d\n ",s->roll,s->name,s->mark);

//}
//while(strcpy(line1,"quit"));
close(sockfd);

 return 0;
}
