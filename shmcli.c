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
#define msg_len 256
#define resp_msg_start 265


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
	
	
	shmid = shmget(my_key, shm_size, 0660 );
	
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
		printf("client : enter some req msg to send to server\n");
		fgets(pshm, msg_len, stdin);
		smop.sem_num = 0;
		smop.sem_op = 1;
		smop.sem_flg = 0;
		
		semop(semid, &smop, 1);
		
		
		smop.sem_num = 0;
		smop.sem_op = -1;
		smop.sem_flg = 0;
		
		semop(semid, &smop, 1);
		puts(pshm+resp_msg_start);
	}
	
return 0;
}
