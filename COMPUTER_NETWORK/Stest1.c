#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<errno.h>
#include<arpa/inet.h>

int main(){
   int sock,a,b,acc1,acc2,len,list,i,j;
   int x,y,sum;
   char line1[100],line2[100],line3[100];
   struct sockaddr_in server,client;
   sock=socket(AF_INET,SOCK_STREAM,0);
   server.sin_family=AF_INET;
   server.sin_port=htons(6000);
   server.sin_addr.s_addr=INADDR_ANY;
   bzero(&server.sin_zero,8);
   len=sizeof(struct sockaddr_in);
   
   //bind
   b=bind(sock,(struct sockaddr*)&server,len);
   list=listen(sock,5);
   while(1){
   printf("Connection established waiting for the client\n");

   acc1=accept(sock,(struct sockaddr*)&client,&len);

    recv(acc1,line1,strlen(line1)+1,0);
     x=atoi(line1);
   recv(acc1,line1,strlen(line1)+1,0);
     y=atoi(line1);
    sum=x+y;

    sprintf(line1,"%d",sum);
    send(acc1,line1,strlen(line1)+1,0);
    printf("client1 has sent message  successfully\n");
   //while(strcpy(line3,"quit"));
close(acc1);
return 0;
}
}

