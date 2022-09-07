#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * main - creates a child process that executes another program
 * system call used: execv()
 * prototype: int execv(const char *path, char *const argv[]);
 */

int main()
{
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
		char *args[]={"/bin/ls", "./", NULL};
		execv(args[0],args);
	}
	return (0);
}
