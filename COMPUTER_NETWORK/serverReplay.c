#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>


int main(){
int sock,len,k,lis,acc,sent,i;
char line[100],line1[100],line2[100];
int num1,digit=0,rev=0,n;
char buf[]="welcome to socket Programming";
unsigned int rec;
struct sockaddr_in server,client;


sock=socket(AF_INET,SOCK_STREAM,0);

if(sock==-1){
perror("Socket\n");
exit(1);
}
server.sin_family=AF_INET;
server.sin_port=htons(6000);
server.sin_addr.s_addr=INADDR_ANY;

bzero(&server.sin_zero,8);

len=sizeof(struct sockaddr_in);
k=bind(sock,(struct sockaddr *)&server,sizeof(server));
if(k==-1){
perror("bind\n");
exit(1);
}

lis=listen(sock,5);
if(lis==-1){
perror("listen\n");
exit(1);
}

while(1){

printf("waiting for client connection on port 6000\n");
acc=accept(sock,(struct sockaddr *)&client,&len);
if(acc==-1){
perror("accept\n");
exit(1);
}


printf("Passing Information to the client............................\n");
do{
memset(line,0x0,100);

n=recv(acc,line,100,0);

send(acc,line,100,0);

}
while(strcpy(line,"quit"));

close(acc);
return 0;

}
}
