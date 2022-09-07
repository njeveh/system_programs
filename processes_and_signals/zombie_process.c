#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

/**
 * main - creates a child process that terminates while the parent is
 * in the sleep state.
 * The child process entry remains in the process table even after its
 * termination.
 */

int main()
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		printf("in the child process. pid = %d, ppid = %d\n", getpid(), getppid());
		exit(0);
	}
	else
	{
		sleep(10);
		printf("executing parent process now. pid = %d\n", getpid());
	}
	return (0);
}
