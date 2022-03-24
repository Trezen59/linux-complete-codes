#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>


void *proc(void* param)
{
	sleep(3);
	return 0;
}


int main(){

	pthread_attr_t attr;
	pthread_t id;
	int err, info;
	
	pthread_attr_init(&attr);
	
	pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);     // setting own value - PTHREAD_EXPLICIT_SCHED
	pthread_attr_getinheritsched(&attr, &info);                     // getting the value from info
	
	switch(info)
	{
		case PTHREAD_INHERIT_SCHED :
		printf("\n sched from parent\n");
		break;
		
		case PTHREAD_EXPLICIT_SCHED :
		printf("\n explicit defining its own sched pol n pri\n");
		break;
	}
	
	pthread_create(&id, &attr, proc, NULL);
	
	
return 0;
}
