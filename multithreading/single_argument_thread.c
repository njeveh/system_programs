#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *sayGreetings(void *name);

/**
 * main - creates a thread that takes in a single argument
 *
 * Return: 0 on success
 */
int main()
{
	pthread_t thread;
	char name[50];

	printf("Enter you name:\n");
	fgets(name, 50, stdin);

	pthread_create(&thread, NULL, sayGreetings, name);
	pthread_join(thread, NULL);
	return (0);
}

/**
 * sayGreetings - prints a greeting to the specified person
 *
 * Return: void
 */
void *sayGreetings(void *name)
{
	printf("Hello %s\n", (char *)name);
	pthread_exit(NULL);
}
