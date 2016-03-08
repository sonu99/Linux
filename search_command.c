//program to search file in directory
#include<stdio.h>
#include<sys/types.h>
#include<string.h>
#include<dirent.h>
static int flag=0;
void check(char *,char *);
void main(int c,char **v)
{
	if(c==2)                                //if directory is not give then it will start from present directory
	{
		check(".",v[1]);
	}
	else
	{
		if(c==3)			//if directory name is given then open it and search file in that directory
		{
			check(v[1],v[2]);
		}
	}
	printf("No of time file present in dir=%d",flag);
}
//----------------------------------------------------------------------------------------------------------------------------------------------
//this function uses recursion concept....1st it will open given directory and check..is it  directory or file if it is file then compare with file name ...if directory then open it and do same
//----------------------------------------------------------------------------------------------------------------------------------------------
void check(char *str1,char *str2)
{
	DIR *dp;
	struct dirent *ptr;
	dp = opendir(str1);			//system call for opening file. note:- it will only open any directory with complete path 							//like ./sonu
	char s[1000];
	while(ptr = readdir(dp))		//read directory pointer 
	{
		if(*(ptr->d_name)!='.')
		{
			strcpy(s,str1);
			strcat(s,"/");
			strcat(s,ptr->d_name);
			if(ptr->d_type == 4)
			{
				check(s,str2);
			}
			else
			{
				if(strcmp(str2,ptr->d_name)==0)
				{
					printf("%s\n",s);
					flag++;
				}
			}
		}
	}
}
