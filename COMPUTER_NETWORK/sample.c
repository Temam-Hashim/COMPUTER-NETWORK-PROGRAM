#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>


int main(){
int a,b,c,arr[100],acc1,acc2,sock,list,value,len,num1,num2;
char line[100],line1[100];
struct sockaddr_in server,client;

sock=socket(AF_INET,SOCK_STREAM,0);
if(sock==-1){
perror("unable to find the socket\n");
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
perror("listening error");
exit(1);
}

while(1){
printf("connection established waiting for the client\n");

//accept1
len=sizeof(struct sockaddr_in);
acc1=accept(sock,(struct sockaddr *)&client,&len);

//accept2
acc2=accept(sock,(struct sockaddr *)&client,&len);


printf("passing information between client.............\n");
do{
//accept from client1 and send to client2

recv(acc1,line,strlen(line)+1,0);
strcpy(line1,line);
send(acc2,line1,strlen(line1)+1,0);

//accept from client2 and send to clientt1

recv(acc2,line,strlen(line)+1,0);
strcpy(line1,line);
send(acc1,line1,strlen(line1)+1,0);
}

while(strcpy(line,"quit"));

close(acc1);
close(acc2);
return 0;

}
}
















