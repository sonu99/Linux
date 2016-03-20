/*****************************************************************
* 			SONU SINGH                               *
*  Client application program for half duplex communication      *
* 								 *
******************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<errno.h>
#include<signal.h>
main(int argc,char *argv[])
{
	if(argc!=3)
	{
		puts("Input order:./tcp_ci <server port no.> <ip address>");
		return;
	}
	int fd;
	//puts("creating serer socket....!");
	fd=socket(AF_INET,SOCK_STREAM,0);
	if(fd==-1)
	{
		perror("socket");
		return;
	}
	//puts("server socket created successfully");
	struct sockaddr_in addr;
	addr.sin_family=AF_INET;
	addr.sin_port=htons(atoi(argv[1]));
	addr.sin_addr.s_addr=inet_addr(argv[2]);
	//puts("bind & connect.....!");
	if(connect(fd,(const struct sockaddr *)&addr,sizeof(addr))==-1)
	{
		perror("connect");
		return;
	}
	//puts("connect success...!");
	char buff[100];
	while(1)
	{
		puts("enter msg for server..!");
		scanf(" %[^\n]s",buff);
		if(send(fd,buff,100,0)==-1)
		{
			perror("send");
			break;
		}
		if(strcmp(buff,"quit")==0)
		{
			puts("server formally terminating");
			break;
		}
		//printf("sent:%s\n",buff);
		bzero(buff,100);
		puts("waiting for reply from server...!");
		int ret;
		ret=recv(fd,buff,100,0);
		if(ret==-1)
		{
			perror("recv");
			break;
		}
		if(ret==0)
		{
			puts("server abnormally terminated");	
			break;
		}
		printf("msg recv :%s\n",buff);
		
	}
	close(fd);
	exit(0);
}
