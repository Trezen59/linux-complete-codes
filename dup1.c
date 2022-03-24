#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd1, fd2, fd3, fd4;
	
	fd1 = open("linux.txt", O_WRONLY | O_CREAT | O_TRUNC, 777); 
	fd2 = open("linuxnew.txt", O_WRONLY | O_CREAT | O_TRUNC, 777); 
	
/*	fd2 = dup2(fd1, 444);*/
	printf("fd1 = %d\n", fd1);
	printf("fd2 = %d\n", fd2);
	
/*	fd3 = dup(fd1);   */
/*	fd4 = dup(fd2);*/

	fd3 = fcntl(fd1, F_DUPFD, 565);
	
	printf("fd3 = %d\n", fd3);
/*	printf("fd4 = %d\n", fd4);*/
	
	close(fd1);
	close(fd2);
	close(fd3);
	
return 0;
}
