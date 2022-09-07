#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int sec;
void my_custom_signal_handler(int signum);

/**
 * main - raises and catches an alarm signal
 *
 * Return: 0 on success
 */

int main()
{
	signal(SIGALRM, my_custom_signal_handler);
	printf("Raising an alarm signal\n");
	alarm(10);
	sec = 60;
	do {
		printf("\r%d ",sec);
		sec--;
		fflush(stdout);
		sleep(1);
	}while(sec>0);

	printf("\n Time Elapsed\n");
	return 0;
}

/**
 * my_custom_signal_handler - catches and handels signals
 * @signum: caught signal number
 *
 * Return: void
 */

void my_custom_signal_handler(int signum)
{
	printf("\a");
	printf("\ncaught signal number %d after %d seconds\n", signum, 60 - sec);
	raise(SIGINT);
}
