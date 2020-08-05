/*COMPUTER NETWORK OF THE CLIENT PROCESS*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<string.h>
int main()
{
  int i,sock,n;
  char line[100],num2[200],sum[200];
  struct sockaddr_in client;

  sock=socket(AF_INET,SOCK_STREAM,0);
  if(sock==-1){
    perror("socket connection failed\n");
  exit(1);
 } 


  client.sin_family=AF_INET;
  client.sin_addr.s_addr=inet_addr("127.0.0.1"); //Loop back IP address
  client.sin_port=htons(6000);

  bzero(&client.sin_zero,8);


  i=connect(sock,(struct sockaddr *)&client,sizeof(client));
  if(i==-1){
    perror("unable to find the server\n");
   }
  else{
     printf("connection Established successfully continue your operation\n");
  }
/* After connection, the client can send or receive messages.*/
//do{

printf("enter 1st num: ");
scanf("%s",line);
send(sock,line,strlen(line)+1,0); 

printf("enter 2nd num: ");
scanf("%s",line);
send(sock,line,strlen(line)+1,0);

n=recv(sock,line,100,0);
        printf("sum recieved from server=%s\n",line);
//exit(1);
//}
//while(strcpy(line,"quit"));


	
close(sockfd);

 return 0;
}
