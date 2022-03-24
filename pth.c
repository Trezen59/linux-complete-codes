#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<pthread.h>

struct thread
{
	int thread_id;
	char msg[100];
};

void* print(void* obj)
{
	pthread_t thread_ID;
	struct thread *t1;
	t1 = (struct thread*) obj;
	thread_ID = pthread_self();
	printf("\n thread ID : %u\n", thread_ID);
	printf("\n %d thread message : %s ",t1->thread_id, t1->msg);
}


int main(){
		
	pthread_t thread2, thread3, thread4, thread_ID;
	int rc;
	
	struct thread t2,t3,t4;
	
	t4.thread_id = 4;
	strcpy(t4.msg, "i am 4th thread\n");
	
	t2.thread_id = 2;
	strcpy(t2.msg, "i am 2nd thread\n");
	
	t3.thread_id = 3;
	strcpy(t3.msg, "i am 3rd thread\n");
	
	thread_ID = pthread_self();
	
	printf("\n main thread ID : %u", thread_ID);
	
	pthread_create(&thread4, NULL, print, (void *)&t4);
	pthread_create(&thread2, NULL, print, (void *)&t2);
	pthread_create(&thread3, NULL, print, (void *)&t3);
	
	print("\n exit from main thread\n");
	pthread_exit(NULL);
	
return 0;
}
