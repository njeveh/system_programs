#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	char some_text[20];

	printf("Enter some text; (limit: 19 chars) \n");

	if (read(0, some_text, 19) != -1)
	{
		some_text[19] = '\0';
		printf("%s\n", some_text);
	}
	else
	{
		perror("unable to read from stdin.\n");
	}
	return (0);
}
