#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void my_custom_signal_handler(int signum);

/**
 * main - raises and catches a signal using a custom signal handler
 *
 * Return: 0 on success
 */

int main()
{
	signal(SIGQUIT, my_custom_signal_handler);

	printf("Just before raising signal\n");
	if (raise(SIGQUIT) != 0) /* returns 0 on success */
	{
		printf("Something went wrong...signal not raised\n");
	}
	return (0);
}

/**
 * my_custom_signal_handler - catches and handles a raised signal
 * @signum: signal number
 *
 * Return: void
 */

void my_custom_signal_handler(int signum)
{
	printf("Whoa!! You can't just quit on me... :-(\n");
	printf("caught signal number %d\n", signum);
}
