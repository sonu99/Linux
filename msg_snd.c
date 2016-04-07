#include<stdio.h>
#include<sys/msg.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<string.h>
#include<stdlib.h>
struct msgbuf
{
	long int mtype;
	char mtext[20];
}
main(int argc,char **argv)
{
	int id;
	struct msgbuf v;
	printf(":%d\n",argc);
	
	v.mtype=3;
	printf("mtype=%ld",v.mtype);
	id=msgget(1,IPC_CREAT|0600);
	printf("reading in process:%d\n",getpid());
	while(1)
	{
		printf("enter msg:\n");
		gets(v.mtext);
		printf("sending  process\n");
		if(msgsnd(id,&v,20,0))
		{
			perror("msgsnd");
		}
		printf("msg:%s\n",v.mtext);
	}

}

