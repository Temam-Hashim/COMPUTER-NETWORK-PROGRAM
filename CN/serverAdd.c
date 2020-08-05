#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>


int main(){
int sock,len,k,lis,acc,sent;
char line[100],line1[100],line2[100];
int num1,num2,sum,n;
char buf[]="welcome to socket Programming";
unsigned int rec;
struct sockaddr_in server,client;


sock=socket(AF_INET,SOCK_STREAM,0);

if(sock==-1){
perror("Socket error\n");
exit(1);
}
server.sin_family=AF_INET;
server.sin_port=htons(6000);
server.sin_addr.s_addr=INADDR_ANY;

bzero(&server.sin_zero,8);

len=sizeof(struct sockaddr_in);
k=bind(sock,(struct sockaddr *)&server,sizeof(server));
if(k==-1){
perror("binding error\n");
exit(1);
}

lis=listen(sock,5);
if(lis==-1){
perror("listening error\n");
exit(1);
}

while(1){

printf("waiting for client connection on port 6000\n");
acc=accept(sock,(struct sockaddr *)&client,&len);
if(acc==-1){
perror("acceptance error\n");
exit(1);
}

//do{
printf("Passing Information to the client............................\n");

memset(line,0x0,100);

n=recv(acc,line,100,0);
num1=atoi(line);

n=recv(acc,line,100,0);
num2=atoi(line);

sum=num1+num2;
sprintf(line1,"%d\n",sum);

send(acc,line1,strlen(line1),0);
//}

//while(abs(strcpy(line,"quit")));



close(acc);
return 0;

}
}
