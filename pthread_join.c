#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<pthread.h>


static void* threadfun(void* arg)
{
	char *s = (char *) arg;
	printf("%s\n", s);
	sleep(5);
	return (void*) strlen(s);
}


int main(){

	pthread_t t1;
	
	void *res;
	int s;
	pthread_create(&t1, NULL, threadfun, "hello world");
	
	printf("message from main\n");
	
	pthread_join(t1, &res);
	
	printf("thread returned %ld\n",(long)res );		
		
	
return 0;
}
