/*************************************************************************************
*Author:          SONU SINGH 							     *
*Application:	  Server application program..it will send total no of alphabet      *
* 		  and numeric present in msz which is send by client.we can connect  *
*		  multiple client to server.					     *
**************************************************************************************
*/
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
void f1(int );
char *ptr=NULL;
main(int argc,char *argv[])
{
	if(argc!=2)
	{
		puts("Input order:./tcp_se <port no.>");
		return;
	}
	int sfd;
	//puts("creating serer socket....!");
	sfd=socket(AF_INET,SOCK_STREAM,0);
	if(sfd==-1)
	{
		perror("socket");
		return;
	}
	//puts("server socket created successfully");
	struct sockaddr_in saddr;
	saddr.sin_family=AF_INET;
	saddr.sin_port=htons(atoi(argv[1]));
	saddr.sin_addr.s_addr=inet_addr("0.0.0.0");
	//puts("bind....!");
	if(bind(sfd,(const struct sockaddr *)&saddr,sizeof(saddr))==-1)
	{
		perror("bind");
		return;
	}
	//puts("bind success....!");
	//puts("creating connection queue....!");
	if(listen(sfd,2)==-1)
	{
		perror("listen");
		return;
	}
	//puts("listen success..!");
	int i=-1;
	while(1)
	{
		puts("Waiting to accpt connection from any client.....!");
		int cfd,clen;
		struct sockaddr_in caddr;
		clen=sizeof(caddr);
		cfd=accept(sfd,(struct sockaddr *)&caddr,&clen);
		if(cfd==-1)
		{
			perror("accept");
			return;
		}
		puts("accept connection from client...1");
		unsigned short portno;
		char *ip;
		portno=ntohs(caddr.sin_port);
		ip=inet_ntoa(caddr.sin_addr);
		puts("whose");
		printf("Ephermeral port is:%d\n",portno);
		printf("Ip address is     :%s\n",ip);
		printf("using file descri.:%d\n",cfd);
		char buff[100];
		++i;
		ptr=realloc(ptr,sizeof(char));
		if(fork()==0)
		{
			while(1)
			{
				bzero(buff,100);
				puts("waiting to recv msg from client..!");
				int ret;
				ret=recv(cfd,buff,100,0);
				if(ret==-1)
				{
					perror("recv");
					break;
				}
				else if(recv==0)
				{
					puts("client abnormally terminated");	
					break;
				}
				printf("msg recv :%s\n",buff);
				if(strcmp(buff,"quit")==0)
				{
					puts("client formally terminating");
					break;
				}
				//printf("echoing back:%s\n",buff);
				int re,i,cnt_c=0,cnt_i=0,td,cnt=0,rem;
				char temp[10]="Alphabet=",temp1[10]=" Numeric=",str[100];
				strcpy(str,buff);
				for(i=0;str[i];i++)
				{
					if((str[i]>='A')&&(str[i]<='Z')||(str[i]>='a')&&(str[i]<='z'))
						cnt_c++;
					else if((str[i]>='0')&&(str[i]<='9'))
						cnt_i++;
					else
						;
				}
				bzero(str,100);
				strcat(str,temp);
				td=cnt_c;
				while(td>0)
				{
					cnt++;
					td/=10;
				}
				td=cnt;
				while(cnt_c>0)
				{
					rem=cnt_c%10;
					temp[cnt-1]=rem+48;
					cnt_c/=10;
					cnt--;
				}
				if(td==0)
				{
					temp[0]=0+48;
					td=1;
				}
				temp[td]='\0';
				strcat(str,temp);
			      	strcat(str,temp1);
				cnt=0;
				td=cnt_i;
				while(td>0)
				{
					cnt++;
					td/=10;
				}
				td=cnt;
				while(cnt_i>0)
				{
					rem=cnt_i%10;
					temp1[cnt-1]=rem+48;
					cnt_i/=10;
					cnt--;
				}
				if(td==0)
				{
					temp1[0]=0+48;
					td=1;
				}
				temp1[td]='\0';
				strcat(str,temp1);
				strcpy(buff,str);		
				if(send(cfd,buff,100,0)==-1)
				{
					perror("send");
					break;
				}
			}
			close(cfd);
			exit(0);
		}
	}
	close(sfd);
}
