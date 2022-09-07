#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

/**
 * main - creates a child process whose parent terminates before it terminates.
 * The child process entry remains in the process is left without it's
 * original parent. (adopted by init process)
 */

int main()
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		printf("in the child process. pid = %d, ppid = %d\n", getpid(), getppid());
		sleep(10);
		printf("in child process after sleep. pid = %d, ppid = %d\n", getpid(), getppid());
	}
	else
	{
		sleep(1);
		printf("executing and exiting parent process. pid = %d\n", getpid());
	}
	return (0);
}
