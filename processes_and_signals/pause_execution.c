#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void my_custom_signal_handler(int signum);

/**
 * main - raises a pause signal that pauses it's execution and an
 * alarm signal that triggers resumption of it's execution
 *
 * Return: 0 on success
 */

int main()
{
	signal(SIGALRM, my_custom_signal_handler);
	alarm(10);
	printf("pausing my execution...\n");
	pause();
	printf("Resuming my execution after some seconds\n");
	return (0);
}

/**
 * my_custom_signal_handler - catches and handles raised signal
 * @signum: raised signal number
 *
 * Return: void
 */

void my_custom_signal_handler(int signum)
{
	if (signum == 14)
	{
		printf("caught a signal number %d\n", signum);
		raise(SIGCONT);
	}
	else
		raise(SIGQUIT);
}
