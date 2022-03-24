#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>


int main(){
		
		int ret , i, cnt =0;
		errno = 0;
		ret = nice(1);
		
		if(ret == -1 && errno !=0 )
			perror("nice");
		else
			printf("nice value is now %d\n", ret);
			
		while(1)
		{
			printf("process with nice value %d count = %d\n", ret, cnt);
			for(i=0; i<1000000; i++)
			{
				cnt++;
			}
		}
	
	
return 0;
}
