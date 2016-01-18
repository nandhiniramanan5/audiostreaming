#include <stdio.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
int main()
{
//Variable declarations
int sd, nsd, i=0, port = 5488;
char content[30]="0";
struct sockaddr_in ser,cli;
//Socket creation and checking
if((sd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP))==-1)
{
printf(":: SOCKET Creation Problem -- Check the parameters .");
return 0;
}
//initializes the structure to zero
bzero((char *)&ser,sizeof(ser));
printf("PORT ADDRESS is %d",port);
//Assign the values to the structure
ser.sin_family=AF_INET;
ser.sin_port=htons(port);
 ser.sin_addr.s_addr=inet_addr("127.0.0.1");
//Binding and checking
if(bind(sd,(struct sockaddr*)&ser,sizeof(ser))==-1)
{
printf(":: BINDING Problem , PORT BUSY -- Please CHANGE the PORT ADDRESS IN BOTH SERVER and CLIENT.");
return 0;
}
i=sizeof(cli);
//Listen whether any client wants to connect
listen(sd,1);
nsd=accept(sd,(struct sockaddr*)&cli,&i);

printf(" SERVER MODULE");
printf("*******************");
i = recv(nsd,content,30,0);
content[i]='\0';
printf("%s",content);
}


