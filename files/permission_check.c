#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main- checks for access permissions of a specified file
 *
 * access prototype: int access(const char *filepath, int amode);
 * amode possible arguments :
 *  • R_OK: This flag tests the read permissions of a file.
 *  • W_OK: This flag tests the write permissions of a file.
 *  • F_OK: This flag tests whether a file exists or not.
 *  • X_OK: This flag tests the execute permissions of a file.
 *
 * Return: 0 on success
 */

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <path to file>\n", argv[0]);
		exit(1);
	}
	if (access(argv[1], F_OK) != -1)
	{
		if (access(argv[1], R_OK) == -1)
			printf("File has no read permission\n");
		else
			printf("File reading permitted\n");
		if (access(argv[1], W_OK) == -1)
			printf("File has no write permission\n");
		else
			printf("File writing permitted\n");
		if (access(argv[1], X_OK) == -1)
			printf("File execution not permitted\n");
		else
			printf("File is executable\n");
	}
	else
		fprintf(stderr, "File does not exist!\n");
	return (0);
}
