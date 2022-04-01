#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define my_key 199
#define shm_size 0x1000

void toggle(char *buf, int cnt);

union senum
{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
	struct seminfo * __buf;
	
};

union senum sem_union;


int main(){
		
	int semid, shmid;
	char * pshm;
	struct sembuf smop;
	
	semid = semget(my_key, 1, 0660 | IPC_CREAT);
	
	if (semid < 0)
	{
		printf("could not create semaphor\n");
		return 1;
	}		
	else
	{
		printf("opened a semaphor id is %d\n", semid);
	}
	
	semctl(semid, 0, SETVAL, 0);
	
	shmid = shmget(my_key, shm_size, 0660 | IPC_CREAT);
	
	if(shmid<0)
	{
		printf("could not create segment\n");
		return 2;
	}
	
	pshm = shmat(shmid, NULL, 0);
	if (!pshm)
	{
		printf("could not attach shared mem segment\n");
		return 3;
	}
	
	while (1)
	{
		smop.sem_num = 0;
		smop.sem_op = -1;
		smop.sem_flg = 0;
		
		semop(semid, &smop, 1);
		
		printf("got the semaphor\n");
		
		strcpy(pshm+256, pshm);
		toggle(pshm+256, strlen(pshm+256));
		
		printf("proceed the request and placed response\n");
		
		
		smop.sem_num = 0;
		smop.sem_op = 1;
		smop.sem_flg = 0;
		
		semop(semid, &smop, 1);
	}
	
return 0;
}


void toggle(char *buf, int cnt)
{
	int ii;
	for(ii=0; ii<cnt; ii++)
	{
		if(buf[ii] >= 'A' && buf[ii] <= 'Z')
		{
			buf[ii] += 0x20;
		}
		else if (buf[ii] >= 'A' && buf[ii] <= 'Z')
		{
			buf[ii] -= 0x20;
		}
	}
}


