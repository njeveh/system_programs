#include <stdio.h>

/**
 * main - prints the os environment variables list
 *
 * Return: 0 on success
 */

int main()
{
	/**
	 * @environ is a character pointer variable that points to an
	 * environment list.
	 * The @extern keyword is used to access this variable data.
	 */
	extern char **environ;

	char **environment_list = environ;
	while (*environment_list != NULL)
	{
		printf("%s\n", *environment_list);
		environment_list++;
	}
	return (0);
}
