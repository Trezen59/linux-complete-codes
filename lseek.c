#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int fd, len;
	char write_buf[50] = "Hii. How are you?";
	char read_buf[50];
	
	fd = open("lk.txt", O_CREAT | O_RDWR, 777);
	
	len = write(fd, write_buf,50);
	printf("return value from write optn = %d\n", len);
	
	lseek(fd, 4, SEEK_SET);
	
	lseek(fd, 2, SEEK_CUR);
	
	lseek(fd, 2, SEEK_END);
		
	read(fd, read_buf, len);
	
	printf("read buffer data is : \n%s\n", read_buf);

	close(fd);
	
return 0;
}
