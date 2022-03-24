#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){
		
	char buff[5];
	
	int x;
	strcpy(buff, "ls -l");
	
	printf("\nsystem() library func uses fork() to create a child process\n\n");
	
	printf("child process executes execl() which loads and run new program provided by system() args\n\n");
	
/*	x = system(NULL);   // ret 1*/

	x = system(buff);
		
	printf("\n\tsys ret val : %d\n\n", x);	
	
return 0;
}
