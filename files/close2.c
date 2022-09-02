#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
/**
 * function prototype: int close(int file_descriptor);
 */

int main()
{
	int file_descriptor;
	char filename[255];
	printf("Enter the filename: ");
	scanf("%s", filename);
/* Setting Permission to Read Write for the file. */
	file_descriptor = open(filename, O_RDWR, 0);
	if(file_descriptor != -1)
	{
		printf("File Opened Successfully!\n");
	}
	else
	{
		printf("Unable to Open the File.\n");
	}

	int close_status = close(file_descriptor);
/**
 * Checks the condition and prints the appropriate statement.
 * Success: 0
 * Error: -1
*/
	if(close_status == 0)
	{
		printf("File Descriptor is closed Successfully\n");
	}
	else
	{
		printf("File Descriptor is not closed\n");
	}
	return 0;
}
