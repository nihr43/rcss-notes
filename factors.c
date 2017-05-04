
// part of a project to find the highest prime factor of a very large number.
// its an exponentially complex problem, so the answer was to to work down from the top

// the solution for this example is 6857

// this program recklessly creates a new working thread at each turn of the factor trees, with no regard for system resources
// it needs some work to actually stop when it finds the solution

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void *new_thread(void *vargp)		//runs for each thread created
{
    pthread_t tid;
    long long i, myval = (long long)vargp;		//assigns argument to variable

	printf("factor: %lu\n", myval);
	

	for (i=2; i<myval/2; i++)
	{
		if (myval % i == 0)
		{
			pthread_create(&tid, NULL, new_thread, (void *)(i));
			pthread_create(&tid, NULL, new_thread, (void *)(myval/i));
		}
	}


}
 
int main()
{
    pthread_t tid;
	long long val = 600851475143;

	pthread_create(&tid, NULL, new_thread, (void *)(val));

    pthread_exit(NULL);
    return 0; 
}