#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int file_descriptor;
	char some_text[20];

	file_descriptor = open("njeveh2.txt", O_RDONLY);
	if (file_descriptor == -1)
		fprintf(stderr, "unable to open file\n");
	else
	{
		if (read(file_descriptor, some_text, 19) != -1)
		{
			some_text[19] = '\0';
			printf("%s\n", some_text);
		}
		else
		{
			perror("unable to read file.\n");
		}
		close(file_descriptor);
	}
	return (0);
}
