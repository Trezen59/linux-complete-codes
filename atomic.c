#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "atomic.h"


int main(){
		
	atomic_t v;						//define v
	atomic_t u = ATOMIC_INIT(0);  // macro like func 
	
	atomic_set(&v, 4);									// v = 4
	printf("%d\n", atomic_read(&v));
	
	atomic_add(2, &v);
	printf("%d\n", atomic_read(&v));
	
	atomic_inc(&v);
	printf("%d\n", atomic_read(&v));
	
	atomic_sub(1, &v);
	printf("%d\n", atomic_read(&v));
	
	atomic_dec(&v);
	printf("%d\n", atomic_read(&v));
	
return 0;
}
