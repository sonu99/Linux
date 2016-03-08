//Program for understanding the concept of parent wait for child exit
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<wait.h>
void main()
	{
		printf("process id=%d\n",getpid());
		if(fork())
			{  
				int status;
				printf("I am in parent process\n");
				printf("process id=%d\n",getpid());
				printf("parent process id=%d\n",getppid());
				//sleep(2);
				printf("chiled %d exited",wait(&status);//wait(&status)->waitpid(0,&status,WNOHANG)-->it won't wait for child
				printf("status=%d ",status);	 //to exit...it will terminate the child when parent compelets it's execution
			}
		else
			{
				printf("I am in child \n");
				printf("Process id=%d\n",getpid());
				printf("parent process is =%d\n",getppid());
				sleep(7);


			}
	}
