#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include<unistd.h>

/**
 * method prototype: int open(const char *filepath, int flags, ...)
 */

/**
 * main - opens a file or creates it if it doesn't exist
 */

int main(int argc, char **argv)
{
	int file_descriptor;
	if (argc != 2)
	{
		fprintf(stderr, "Usage: open2 <file name>\n");
		exit(1);
	}
	file_descriptor = open(argv[1], O_RDWR | O_CREAT);
	if (file_descriptor == -1)
	{
		perror("File opening unsuccessful\n");
	}
	else
	{
		printf("file opened successfully\n");
		close(file_descriptor);
	}
	return (0);
}
