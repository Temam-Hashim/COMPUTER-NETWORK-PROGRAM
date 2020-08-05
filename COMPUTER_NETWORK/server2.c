#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>


int main(){
int a,b,c,arr[100],acc1,acc2,acc3,sock,list,value,len,num1,num2,sum;
char line[100],line1[100];
struct sockaddr_in server,client;

sock=socket(AF_INET,SOCK_STREAM,0);
if(sock==-1){
perror("socket not found\n");
exit(1);
}

server.sin_family=AF_INET;
server.sin_port=htons(6000);
server.sin_addr.s_addr=INADDR_ANY;
bzero(&server.sin_zero,8);

b=bind(sock,(struct sockaddr *)&server,sizeof(server));
if(b==-1){
perror("unable to bind\n");
exit(1);
}

list=listen(sock,5);
if(list==-1){
perror("unable to listen to the client\n");
exit(1);
}
while(1){
printf("connection established waiting for the client\n");

//accept1
len=sizeof(struct sockaddr_in);
acc1=accept(sock,(struct sockaddr *)&client,&len);
if(acc1==-1){
perror("acceptance error\n");
exit(1);
}
//accept2
acc2=accept(sock,(struct sockaddr *)&client,&len);
if(acc2==-1){
perror("acceptance error\n");
exit(1);
}
//accept3
acc3=accept(sock,(struct sockaddr *)&client,&len);
if(acc3==-1){
perror("acceptance error\n");
exit(1);
}

printf("passing information between client.............\n");
do{
//accept from client1 
a=recv(acc1,line,strlen(line)+1,0);
num1=atoi(line);
//accept from client2 
a=recv(acc2,line,strlen(line)+1,0);
num2=atoi(line);
//send the sum to 3rd client
sum=num1+num2;
sprintf(line1,"%d\n",sum);
c=send(acc3,line1,strlen(line1),0);
}

while(strcpy(line,"quit"));

close(acc1);
close(acc2);
return 0;
}
}
















