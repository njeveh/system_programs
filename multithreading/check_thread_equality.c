#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *custom_thread_function();

/**
 * main - checks whether two threads are the same
 *
 * Return: 0 on success
 */

int main()
{
	pthread_t thread1, thread2;

	pthread_create(&thread1, NULL, custom_thread_function, NULL);
	pthread_create(&thread2, NULL, custom_thread_function, NULL);

	if (pthread_equal(thread1, thread2))
	{
		printf("The two threads are Equal...!\n");
	}
	else
	{
		printf("The two threads are not equal.\n");
	}
	return (0);
}

/**
 * custom_thread_function - the function to be run by the created thread
 *
 * Return: void
 */
void *custom_thread_function()
{
	printf("This is my custom thread.\n");
	return (NULL);
}
