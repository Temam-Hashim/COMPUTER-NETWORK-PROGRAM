#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>


int main(){
int a,b,c,arr[100],numbyte1,numbyte2,sock,len;
char line[100],line1[100];
struct sockaddr_in server;

sock=socket(AF_INET,SOCK_DGRAM,0);
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

while(1){
printf("connection established waiting for the client\n");


len=sizeof(struct sockaddr_in);
printf("passing and Recieving information to/from client.............\n");

//accept from client1 and display the message
numbyte2=recvfrom(sock,line,sizeof(line1),0,(struct sockaddr*)&server,&len);
printf("%s\n",line);

printf("client ip_address=\n %s\n", inet_ntoa(server.sin_addr));

printf("number of byte from client=\n %d\n",numbyte2);

//send message to the client

strcpy(line,"Message from server-> Welcome To The server site\n");
numbyte1=sendto(sock,line,strlen(line),0,(struct sockaddr*)&server,len);


close(sock);


return 0;

}
}
