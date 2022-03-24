// run as gcc mutex.c -pthread

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int sharedval = 5;

pthread_mutex_t my_mutex;

void *thread_inc(void *args)
{
	pthread_mutex_lock(&my_mutex);
	sharedval++;
	pthread_mutex_unlock(&my_mutex);
}

void *thread_dec(void *args)
{
	pthread_mutex_lock(&my_mutex);
	sharedval--;
	pthread_mutex_unlock(&my_mutex);
}

int main(){
	
	pthread_t thread1, thread2;
	pthread_mutex_init(&my_mutex, NULL);
	
/*	sem_init(&my_sem, 0, 1);*/
	
	pthread_create(&thread1, NULL, thread_inc, NULL);
	pthread_create(&thread2, NULL, thread_dec, NULL);
	
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	
	printf("sharedval = %d\n", sharedval);
	
return 0;
}
