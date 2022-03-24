// run with -   gcc pthread.c -lpthread


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>

pthread_t tid1, tid2, tid3;

void * thread1(void * arg)
{
	printf("thread 1 executing\n");
	return NULL;
}

struct arg
{
	int x = 10;
	char y = 'a';
};

/*void * thread2(void * arg)*/
/*{*/
/*	printf("thread 2 executing\n");*/
/*	return NULL;*/
/*}*/

/*void * thread3(void * arg)*/
/*{*/
/*	printf("thread 3 executing\n");*/
/*	return NULL;*/
/*}*/

int main(){

	int ret1 = pthread_create(&tid1, NULL, thread1, NULL);
	int ret2 = pthread_create(&tid2, NULL, thread2, NULL);
	int ret3 = pthread_create(&tid3, NULL, thread3, NULL);
	
	if(ret1)
	{
		printf("thread 1 is not created\n");
	}
	else
	{
		printf("thread 1 is created\n");
	}
	
	if(ret2)
	{
		printf("thread 2 is not created\n");
	}
	else
	{
		printf("thread 2 is created\n");
	}
	
	if(ret3)
	{
		printf("thread 3 is not created\n");
	}
	else
	{
		printf("thread 3 is created\n");
	}
	
/*	sleep(2);*/

	pthread_join(tid1, NULL);	 // use this instead of sleep
	pthread_join(tid2, NULL);                             // joins given thread with main process execution 
	pthread_join(tid3, NULL);                            // forces the process to wait for completion of thread with threadid.
	
return 0;
}



