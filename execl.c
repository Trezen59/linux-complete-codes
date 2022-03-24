#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("i am going to exeute an 'ls' program from child pid\n");
	
	int pid_1;
	
	printf("current processpid = %d\n", getpid());
	
	pid_1 = fork();
	
	if(pid_1 == 0)
	{
		printf("new child process pid = %d\n", getpid());
		printf("new child parent process pid = %d\n", getppid());
		
	}
	else
/*	{	sleep(3);*/
		printf("new parent process pid = %d\n", getpid());
		printf("new parents parent process pid = %d\n", getppid());
		execl("/bin/ls","ls", "-lh", 0);
	}
	

	printf("I executed ls program\n");
	printf("I executed ls program\n");
	printf("I executed ls program\n");
	
return 0;
}
