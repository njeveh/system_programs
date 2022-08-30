#include <stdio.h>
#include <unistd.h> /* unix standard library */
#include <pthread.h> /* POSIX thread creation library */

void *custom_thread_function();

/**
 * main - creates a thread
 *
 * Return: 0 on success
 */
int main()
{
	pthread_t thread; /* Thread descriptor */
	int status; /* status variable to store the status of thread */
	int i;

	status = pthread_create(&thread, NULL, custom_thread_function, NULL);
	/**
	 * status = 0 ==> if thread is created successfully,
	 * otherwise 1.
	 */

	if (!status)
	{
		printf("Custom Created Successfully.\n");
	}
	else
	{
		printf("Unable to create the Custom Thread.\n");
		return (0);
	}
	/* Main Function For loop */
	for (i = 0; i < 15; i++)
	{
		printf("I am the process thread created by compiler By default.\n");
		sleep(1);
	}
	return (0);
}

/**
 * custom_thread_function - show cases thread termination
 *
 * Return: void
 */
void *custom_thread_function()
{
	int i;

	for (i = 0; i < 15; i++)
	{
		printf("I am a custom thread function created by programmer.\n");
		sleep(1);
		if (i == 3)
		{
			printf("My JOB is Done. I am now being terminated by programmer.\n");
			pthread_exit(NULL);
		}
	}
	return (NULL);
}
