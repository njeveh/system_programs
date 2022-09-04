#include <stdio.h>
#include <stdlib.h>

/**
 * main - sets a new environment variable
 * library function used: setenv()
 * prototype:int setenv(const char *envname, const char *envval, int overwrite);
 *
 * Return: 0 on success
 */

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		fprintf(stderr, "Usage %s <variable_name> <value>\n", argv[0]);
		exit(0);
	}
	if (setenv(argv[1], argv[2], 0) == -1)
		printf("Sorry! variable not set, something went wrong.\n");
	else
	{
		printf("Environment variable set successfully\n");
		printf("%s=%s\n", argv[1], getenv(argv[1]));
	}
	return (0);
}
