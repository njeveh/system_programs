#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * main - changes current working directory to the one in the specified path
 * @argc: number of command line arguments supplied
 * @argv: pointer to arguments array
 * system call used : chdir()
 * prototype: int chdir(const char *path);
 *
 * Return: 0 on success
 */

int main (int argc, char **argv)
{
	char *dir;
	int size;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <path>\n", argv[0]);
		exit(1);
	}
	if (access(argv[1], F_OK) == -1)
		fprintf(stderr, "Directory in the specified path does not \
exist\n");
	else
	{
		if(chdir(argv[1]) == -1)
			fprintf(stderr, "Can't access %s\n", argv[1]);
		else
		{
			printf("directory changed successfully\n");
			size = strlen(argv[1]) + 1;
			dir = malloc(sizeof(dir) * size);
			if (dir != NULL)
			{
				printf("Working Directory After Operation: %s\n", getcwd(dir, size));
				free(dir);
			}
		}
	}
	return (0);
}
