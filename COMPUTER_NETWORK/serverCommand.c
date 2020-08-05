/*
 * This program displays the names of all files in the current directory.
 */

#include <dirent.h> 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(void)
{
  DIR           *d;
  struct dirent *dir;
  d = opendir(".");
  if (d)
  {
int a,b,c,arr[100],acc1,acc2,sock,list,value,len,num1,num2;
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

printf("passing information between client.............\n");

    while ((dir = readdir(d)) != NULL)
    {
     
    send(acc1,dir->d_name,strlen(dir->d_name),0);
   
    }
printf("all existing file in the current directory has sent to the client\n");
    exit(1);
    closedir(d);
  }

  return(0);
}
}

