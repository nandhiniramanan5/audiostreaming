#include <stdio.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
int main()
{
//Variable declarations
int sd,i=0,port = 5488;
char content[30]="Welcome by client";
struct sockaddr_in ser;
//Socket creation & checking
if((sd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP))==-1)
{
printf(":: SOCKET Creation Problem -- Check the parameters .");
return 0;
}
//Initializes the structure to zero
bzero((char *)&ser,sizeof(ser));
printf("PORT ADDRESS is %d",port);
//Assign the values to the structure
ser.sin_family=AF_INET;
ser.sin_port=htons(port);
ser.sin_addr.s_addr=inet_addr("127.0.0.1");
//Connect with the server and checking
if(connect(sd,(struct sockaddr*)&ser,sizeof(ser))==-1)
{
printf(":: CONNECTING Problem. -- Check the SERVER Availability STATUS .");
return 0;
}
printf(" CLIENT MODULE");
printf("*******************");
send(sd,content,30,0);
close(sd);
/*void cleanExit()
{
  exit(0);
}*/
}

