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
	
return 0;
}
