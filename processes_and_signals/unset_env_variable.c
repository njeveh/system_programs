#include <stdio.h>
#include <stdlib.h>

/**
 * main - unsets an environment variable
 * library function used: unsetenv()
 * prototype: int unsetenv(const char *name);
 *
 * Return: 0 on success
 */

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <variable name>\n", argv[0]);
		exit(1);
	}

	if (unsetenv(argv[1]) == -1)
		printf("deleting %s unsuccessful.\n", argv[1]);
	else
		printf("%s deleted successfully\n", argv[1]);
	return (0);
}
