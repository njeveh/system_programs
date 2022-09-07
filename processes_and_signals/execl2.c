#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * main - creates a child process that executes another program
 * system call used: execl()
 * prototype: int execl(const char *path, const char *arg, ..., NULL)
 */

int main()
{
	char *binary_path = "/bin/ls";
	pid_t pid;

	pid = fork();
	if (pid > 0)
	{
		wait(NULL);
		printf("exiting parent process\n");
	}
	else if (pid == 0)
	{
		printf("executing another program\n");
		if (execl(binary_path, binary_path, "-la", ".",  NULL) == -1)
		{
			fprintf(stderr, "execution failed!!\n");
		}
	}
	return (0);
}
