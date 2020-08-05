#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>

int main(){
int a,b,c,sock,len;
char line[100],line1[100],ch;
struct sockaddr_in client;
sock=socket(AF_INET,SOCK_STREAM,0);
client.sin_family=AF_INET;
client.sin_port=htons(6000);
client.sin_addr.s_addr=inet_addr("127.0.0.1");
bzero(client.sin_zero,8);
len=sizeof(struct sockaddr_in);
while(1){
c=connect(sock,(struct sockaddr*)&client,len);
printf(" Send Message:-");
do{
scanf("%s ",line);
send(sock,line,100,0);

recv(sock,line,100,0);
printf("%s ",line);
}
while(strcpy(line,"quit"));
close(sock);
return 0;
}
}
