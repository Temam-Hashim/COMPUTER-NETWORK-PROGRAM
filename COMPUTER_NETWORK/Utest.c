#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<errno.h>
#include<ctype.h>

int main(){
int a=0,b,c,sock,len,i,j,low,high;
char line[100],line1[100],line2[100];

struct sockaddr_in server;
sock=socket(AF_INET,SOCK_DGRAM,0);
server.sin_family=AF_INET;
server.sin_port=htons(7000);
server.sin_addr.s_addr=INADDR_ANY;
bzero(&server.sin_zero,8);
len=sizeof(struct sockaddr_in);

bind(sock,(struct sockaddr*)&server,len);
while(1){
recvfrom(sock,line,100,0,(struct sockaddr*)&server,&len);
j=strlen(line)-1;
for(i=0;i<=j;i++){
if(line[i]!=line[j-i]){
a=1;
break;
}
}
if(a==1){
strcpy(line2,"not palindrom");
sendto(sock,line2,100,0,(struct sockaddr*)&server,len);
}
else{
strcpy(line1,"is palindrom");
sendto(sock,line1,100,0,(struct sockaddr*)&server,len);
}
close(sock);
return 0;
}
}
