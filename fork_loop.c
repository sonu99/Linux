//program for understanding the fork execution..
//program for understandinng the fork concept
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
main()
	{
		int a,i ;
		for(i=0;i<2;i++)		//p1---->c1........i=0
		if(fork())			//p1----->c2........i=1
			{			//c1(p2)------>c3------->i=1
				printf("value of i=%d\n",i);
				printf("I am in parent process\n");
				printf("process id=%d\n",getpid());
				printf("parent process id=%d\n",getppid());
				//pause();
				//while(1);
				//sleep(10);
			}
		else
			{       
  				printf("value of i in child=%d\n",i);
				printf("I am in child \n");
				printf("Process id=%d\n",getpid());
				printf("parent process is =%d\n",getppid());


			}
	}

//Note:-

//x->x+1->x+2->x+3
/*for(i=1;i<3;i++)
{
	if(fork()==0)
	{
		exexlp(argv[i],argv[i],0);	
	}
*/
