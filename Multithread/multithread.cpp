#include <pthread.h>
#include <stdio.h>
#include <pthread.h>
#include <cstdlib>
#include <iostream>
using namespace std;

#define NUM_THREADS 5

struct thread_data {
	int thread_id;
	char * message;
};

void *PrintHello(void * threadarg)
{
	struct thread_data *my_data;
	my_data = (struct thread_data *) threadarg;
	long tid = (long) my_data -> thread_id;
	cout << "Thread ID, " << tid << ", thread_data: " << my_data->message << endl;
	pthread_exit(NULL);
}

int main()
{
	pthread_t threads[NUM_THREADS];
	struct thread_data data[NUM_THREADS];
	int rc;
	int i;
	void * status;

	for (i = 0; i < NUM_THREADS; i++)
	{
		cout << "main(): creating thread, " << i << endl;
		//struct thread_data data;
		data[i].thread_id = i;
		data[i].message = (char *) "abcdfe";
		rc = pthread_create(&threads[i], NULL, PrintHello, (void *) &data[i]);
		if (rc)
		{
			cout << "Error: Unable to create thread, " << rc << endl;
			exit(-1);
		}
		rc = pthread_join(threads[i], &status);
		if (rc)
		{
			cout << "Error: Unable to join, " << rc << endl;
			exit(-1);
		}
		cout << "Status: " << status << endl;
	}
	cout << "Nae1" << endl;
	pthread_exit(NULL);
	cout << "Nae2" << endl;
	return 0;
}