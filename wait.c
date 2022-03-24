#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	
/*	pid_t pid1;*/
/*	pid1  = fork();*/
/*	*/
/*	if(pid1 == 0){*/
/*		sleep(3);*/
/*		printf("i am child with delay of 3 sec aand my pri pid = %d\n", getpid());*/
/*		execl("/bin/ls", "ls", 0);*/
/*	}*/
/*	else{*/
/*		int pid2;*/
/*		printf("i am parent pro pid = %d\n", getppid());*/
/*		pid2 = wait(0);*/
/*		*/
/*		printf("parent saying child %d exited/terminated normally\n", pid2);*/
/*		printf("I am parent process pro pid = %d\n", getpid());*/
/*		*/
/*	}*/

/*		int pid2;*/
/*		printf("i am parent pro pid = %d\n", getppid());*/
/*		pid2 = wait(0);         // returns -1*/
/*		*/
/*		printf("parent saying child %d exited/terminated normally\n", pid2);*/
/*		printf("I am parent process pro pid = %d\n", getpid());*/

/*	pid_t pid;*/
/*	int option, stat;*/
/*	*/
/*	while(1)*/
/*	{*/
/*		printf("enter 1 to execute 0 to exit : \n");*/
/*		scanf("%d", &option);*/
/*		*/
/*		if(!option){*/
/*			exit(1);*/
/*		}*/
/*		printf("\n");*/
/*		if(fork() == 0)*/
/*		{*/
/*			execl("/bin/ls", "ls", 0);*/
/*			exit(0);*/
/*		}*/
/*	}*/

	pid_t childone, childtwo;
	
	printf(" current parent pid = %d\n", getpid());
	childone = fork();
	
	if(childone == 0)
	{
		printf(" child one pid = %d\n", getpid());
	}
	
	else
	{
		childtwo = fork();	
		if(childtwo == 0) 
		{
		printf(" child two pid = %d\n", getpid());
		}
		else
		{
			wait(0);
			printf("parent of one and two  pid = %d\n", getpid());
		}
	}
	
	
	
return 0;
}
