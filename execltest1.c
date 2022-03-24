#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	
	execl("/home/trezen/Desktop/Linux/Linux Internals/fd","./a.out", "file", "discriptor", 0) ;
	printf("\n");
	
return 0;
}
