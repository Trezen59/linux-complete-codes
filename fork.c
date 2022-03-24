#include<stdio.h>
#include<unistd.h>

int main()
{
/*	printf("current process\n");*/
/*	fork();*/
/*	fork();*/
/*	*/
/*	printf("linux process 22\n");*/
/*	printf("linux process 33\n");*/
/*	*/
/*	while(1);   // parent */
/*				// child*/


	int pid_1;
	
	printf("current processpid = %d\n", getpid());
	
	pid_1 = fork();
	
	if(pid_1 == 0)
	{
		printf("new child process pid = %d\n", getpid());
		printf("new child parent process pid = %d\n", getppid());
		
	}
	else
	{	sleep(3);
		printf("new parent process pid = %d\n", getpid());
		printf("new parents parent process pid = %d\n", getppid());
	}
	
	while(1);
	
return 0;
}
