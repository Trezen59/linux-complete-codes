#include<stdio.h>
#include<signal.h>

void sighand(int signum)
{
	printf("interrupt signal recorded but no termination on ctrl+c\n");
	signal(SIGINT, SIG_DFL);
}

int main()
{
	int i;
	signal(SIGINT, sighand);
/*	signal(SIGINT, SIG_DFL);*/
	
	for (i = 0; ; i += 1)
	{
		printf("%d\n",i);
		sleep(1);
	}
	return 0;
	
}
