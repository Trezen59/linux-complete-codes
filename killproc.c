#include<stdio.h>
#include<signal.h>
#include<sys/types.h>

int main()
{
	pid_t pid;
	int sig_no;
	
	printf("enter the pid of the process for which the signal need to be sent\n");
	scanf("%d", &pid);
	printf("enter the signal that need to be sent \n");
	scanf("%d", &sig_no);
	
	kill(pid, sig_no);
	perror("sig_res : ");
	return 0;
}
