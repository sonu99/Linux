//program for receive the msz from msz queue..
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
	v.mtype=atoi(argv[1]);			//mtype indicate that which type of msz you want to retrieve ex: 0 for 1st msz retrieve from 							//queue      	
	id=msgget(1,0600);
	printf("reading in process:%d\n",getpid());
	while(1)
	{
		bzero(v.mtext,20);
		printf("reading process\n");
		if(msgrcv(id,&v,20,v.mtype,0))
		{
			perror("msgrcv");
		}
		printf("msg:%s\n",v.mtext);
	}

}

