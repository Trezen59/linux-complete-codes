#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int fd1;
	char buffer[100];
	fd1 = open("main.c", O_CREAT | O_RDWR, 777);
	
	read(fd1, buffer, 100);
	
	printf("buffer data is : \n%s\n", buffer);
	

return 0;
}


