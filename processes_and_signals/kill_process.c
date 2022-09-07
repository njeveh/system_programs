#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>


void my_custom_signal_handler(int signum);

/**
 * main - creates a child process and send a kill signal to it
 *
 * Return: 0 on success
 */

int main()
{
	pid_t pid;
	int i;

	pid = fork();

	if (pid == 0)
	{
		signal(SIGQUIT, my_custom_signal_handler);
		printf("hooray!! my paps ain't watching lemme just mess around :-)\n");
		sleep(1);
		printf("Imma litter all this place with rubbish text\n");
		for (i = 0; i < 100; ++i)
		{
			printf("Rubbish text and ain't nothing you gonna do..!!\n");
		}
	}
	else
	{
		sleep(1);
		printf("Sending a signal to stop that stubborn kid!\n");
		sleep(0.5);
		kill(pid, SIGQUIT);
	}
	return (0);
}

/**
 * my_custom_signal_handler - handles caught signals
 * @signum: caught signal number
 *
 * Return: void
 */
void my_custom_signal_handler(int signum)
{
	printf("oops! seems my dad was watching after all..gotta stop!\n");
	printf("Received signal number: %d\n", signum);
	raise(SIGKILL);
}
