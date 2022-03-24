/*#include<stdio.h>*/
/*#include<fcntl.h>*/

/*int main(){*/
/*	int fd1;*/
/*	*/
/*	// file discripter */
/*	fd1 = open("main.c", O_CREAT | O_RDWR, 777);*/
/*	printf("the fd is %d\n", fd1);*/
/*	*/
/*	close(fd1);*/

/*	*/

/*return 0;*/
/*}*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, int * argv[]){
	int i;
	
	printf("File name : %s\n", argv[0]);
	printf("total number of arguments : %d\n", argc);
	for(i=1; i<argc; i++)
	{
		printf("%s ", argv[i]);
	}
	
	int fd1;
	
	// file discripter 
	fd1 = open("main.c", O_CREAT | O_RDWR, 777);
	printf("the fd is %d\n", fd1);
	
	close(fd1);
	
return 0;
}
