#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

/**
 * system call used: rmdir()
 * prototype: int rmdir(const char *pathname);
 */

/**
 * main - deletes the directory in the specified path
 * argc - number of arguments supplied
 * argv - pointer to array of arguments
 *
 * Return: 0 on success
 */

int main (int argc, char **argv)
{
	int i;

	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s <space separated path(s) to dir(s)\n", argv[0]);
		exit(1);
	}
	for (i =1; i < argc; ++i)
	{
		if (access(argv[i], F_OK) == -1)
			fprintf(stderr, "The directory %s does not exist\n", argv[i]);
		else
		{
			if (rmdir(argv[i]) == -1)
				fprintf(stderr, "Unable to delete %s\n", argv[i]);
			else
				printf("%s deleted successfully\n", argv[i]);
		}
	}
	return (0);
}
