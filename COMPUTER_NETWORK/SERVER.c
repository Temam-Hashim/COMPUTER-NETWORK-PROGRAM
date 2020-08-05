/*NETWORK PROGRAMMING WITH SOCKETS FOR SERVER*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
int sock, length,i,list;
unsigned int acc;
char line1[100],line2[100];
struct sockaddr_in server,client;

/*calling socket function*/
sock=socket(AF_INET,SOCK_STREAM,0);
if(sock==-1){
           perror("unable to find the socket\n");
           exit(1);
}
 /*already defined member in sockaddr_in structure*/
 server.sin_family=AF_INET;
 server.sin_addr.s_addr=INADDR_ANY;
 server.sin_port=htons(6000);

 bzero(&server.sin_zero,8);

/*calling bind function*/
 i=bind(sock,(struct sockaddr *)&server,sizeof(server));
if(i==-1){
           perror("binding error\n");
           exit(1);
}

/*liten function calling ro listen to the client*/
 list=listen(sock,5);
 if(list==-1){
           perror("listeninig error\n");
           exit(1);
}
else{
    printf("Operation success waiting for client to connect on port 6000\n");
}

while(1){
 /*Accept function to grant acceptance*/
 length=sizeof(client);
 acc=accept(sock, (struct sockaddr *) &client,&length);
 if(acc==-1){
            perror("acceptance error\n");
           exit(1);
}
 /*Message to client*/
strcpy(line1,"Message from Server");
strcpy(line2,"Welcome to Socket Programming");
send(acc, line1, 100, 0);
send(acc, line2, 100, 0);

/*Message from client*/
recv(acc, line1, 100, 0);
printf("%s\n", line1);

close(acc);

return 0;

}
}
