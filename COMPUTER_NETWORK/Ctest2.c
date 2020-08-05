#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<errno.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(){
   int sock,conn,b,i,j,len;
   char line1[100],line2[100];
   struct sockaddr_in a;
   sock=socket(AF_INET,SOCK_STREAM,0);
   a.sin_family=AF_INET;
   a.sin_port=htons(6000);
   a.sin_addr.s_addr=inet_addr("127.0.0.1");
   bzero(&a.sin_zero,8);
   len=sizeof(struct sockaddr_in);
   
   //connect to the server
   conn=connect(sock,(struct sockaddr*)&a,len);
    printf("Connected to the server successfully\n");
    printf("........start sending message to your friend......\n");
   do{ 
    //sending data 
      scanf("%s",line1);
      strcpy(line1,line1);
      send(sock,line1,strlen(line1),0);
   //receiving data
   recv(sock,line2,strlen(line1),0);
   printf("%s",line2);

   }
   while(strcpy(line1,"quit"));
return 0;
}

