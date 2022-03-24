#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void * process(void * args)
{
	pthread_detach(pthread_self());
	printf("sleeping 2 secs\n");
	sleep(2);
	printf("slept 2 secs\n");
}

int main(){
	
	pthread_t t_id;
	pthread_create(&t_id, NULL, process, NULL);
	
	pthread_exit(NULL);	 
	
return 0;
}
