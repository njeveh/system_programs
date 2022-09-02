#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

/**
 * main - changes the access permission of a specified file.
 *
 * chmod prototype: int chmod(char *filepath, int mode)
 *
 * Return : 0 on success
 */
int main(int argc, char **vargs)
{
	if (argc != 3)
	{
		fprintf(stderr, "usage: chmod2 <path to file> <permission>\n");
		exit(1);
	}

	if(chmod(vargs[1], atoi(vargs[2])) == -1)
	{
		fprintf(stderr, "permission change unsuccessful\n");
	}
	else
	{
		printf("permission changed successfully\n");
	}
	return (0);
}
