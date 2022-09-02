#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

/**
 * system call used: mkdir()
 * prototype: int mkdir(const char *path, mode_t mode);
 */

/**
 * main - creates directories in the specified paths
 * @argc: number of arguments provided
 * @argv: pointer to an array of arguments
 *
 * Return: 0 on success
 */

int main(int argc, char **argv)
{
	int i;

	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s <space separated dir name(s) | paths>\n", argv[0]);
		exit(1);
	}
	for (i = 1; i < argc; ++i)
	{
		if(mkdir(argv[i], 0777) == -1)
		{
			fprintf(stderr, "unable to create dir %s\n", argv[i]);
		}
		else
			printf("dir %s created successfully\n", argv[i]);
	}
	return (0);
}
