#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef struct person{
	char *name;
	int age;
	char *blood_group;
} person;

void *printData(void *data);

/**
 * main - creates a thread that calls a function that takes mulitple
 * arguments
 *
 * Return: 0 on success
 */
int main()
{
	person *arguments;
	pthread_t thread;
	char name[50], blood_group[5];
	int age;

	arguments = malloc(sizeof(arguments));
	if (arguments == NULL)
	{
		printf("memory allocation error\n");
		return (1);
	}
	printf("Enter your name:\n");
	fgets(name, 50, stdin);
	printf("Enter your age:\n");
	scanf("%d", &age);
	printf("Enter your blood group:\n");
	scanf("%s", blood_group);
	arguments->name = name;
	arguments->age = age;
	arguments->blood_group = blood_group;

	pthread_create(&thread, NULL, printData, arguments);
	pthread_join(thread, NULL);
	free(arguments);
	return (0);
}

/**
 * printData - prints a person's information
 * @data: person's data to be printed
 *
 * Return: void
 */
void *printData(void *data)
{
	printf("Name: %s\n", ((person *)data)->name);
	printf("Age: %d\n", ((person *)data)->age);
	printf("Blood Group: %s\n", ((person *)data)->blood_group);
	return (NULL);
}
