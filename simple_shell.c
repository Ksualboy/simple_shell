#include "narita.h"

/**
 * main - Entry function
 * @ac: Ammount of arguments passed
 * @av: Arguments passed
 * @env: Enviroment variables
 *
 * Return: 0 if success
*/

int main(int ac __attribute__((unused)), char **av, char **env)
{
	char *input, **splitted = NULL, *command;
	int id, i;
	size_t size = 32, n, error = -1;

	input = (malloc(sizeof(char) * size));
	if (!input)
	{
		write(1, "Unable to allocate memory", 25);
		exit(1);
	}

	while (1)
	{
		write(1, "$uwu ", 5);
		n = getline(&input, &size, stdin);
		if (n == error)
		{
			write(1, "\n", 1);
			break;
		}
		if (input[0] == '\n')
			continue;

		input[n - 1] = ' ';
		splitted = _split(input, " ");
		command = getpath(env, splitted[0]);

		if (!command)
		{
			write(2, av[0], _strlen(av[0]));
			write(2, ": No such file or directory\n", 28);
		}
		else
		{
			id = fork();

			if (id != 0)
				wait(NULL);

			if (id == 0 && execve(splitted[0], splitted, NULL) == -1)
			{
				write(2, av[0], _strlen(av[0]));
				perror(": ");
				return (-1);
			}

			free(command);
		}
	}

	if (splitted)
	{
		for (i = 0; splitted[i]; i++)
			free(splitted[i]);

		free(splitted);
	}

	free(input);

	return (0);
}
