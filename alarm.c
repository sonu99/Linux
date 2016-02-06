//Kill the process after 6 second
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<fcntl.h>
#include<sys/types.h>
#include<wait.h>
void sig_hand(int sig_no)
	{
		printf("alaram is raised and signal no=%d\n",sig_no);
		kill(getpid(),SIGINT);
		printf("process is killed after 6 sec\n");	
	}

void main()
	{
		printf("process id=%d\n",getpid());
		signal(SIGALRM,sig_hand);
		alarm(6);
		while(1);
	}
