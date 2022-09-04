#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the value of the environment variable specified in
 * the arguments
 * library function used: getenv()
 * prototype: char *getenv(const char *name);
 *
 * Return: 0 on success
 */

int main(int argc, char **argv)
{
	char *env_value;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <variable name>\n", argv[0]);
		exit(1);
	}

	env_value =getenv(argv[1]);
	if (env_value == NULL)
		printf("Variable not found\n");
	else
		printf("%s\n", getenv(argv[1]));
	return (0);
}
