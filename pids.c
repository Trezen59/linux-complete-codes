#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	printf("my process pid = %d\n", getpid());
	printf("my parent pid = %d\n", getpid());
	
	printf("linux kernel\n");
	while(1);
	
return 0;
}
