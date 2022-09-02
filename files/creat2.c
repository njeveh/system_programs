#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include<unistd.h>

/**
 * method prototype: int creat(char *filename, mode_t mode)
 */

/**
 * main - creates a new file
 */

int main(int argc, char **argv)
{
	int file_descriptor;
	if (argc != 2)
	{
		fprintf(stderr, "Usage: creat2 <file name>\n");
		exit(1);
	}
	file_descriptor = creat(argv[1], O_RDWR | O_CREAT);
	if (file_descriptor == -1)
	{
		perror("File creation unsuccessful\n");
	}
	else
	{
		printf("file created successfully\n");
		close(file_descriptor);
	}
	return (0);
}
