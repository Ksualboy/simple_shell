#include "narita.h"

/**
 * execute - Runs a given program
 * @command: command to run
 * @arguments: arguments to pass to execve
 * @av: name of the program
 *
 * Return: -1 if it breaks, 0 if it doesn't
*/

int execute(char *command, char **arguments, char *av)
{
	int id;

	id = fork();

	if (id != 0)
		wait(NULL);

	if (id == 0 && execve(command, arguments, NULL) == -1)
	{
		write(2, av, _strlen(av));
		perror(": ");
		return (-1);
	}

	return (0);
}

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
	char *input, **splitted;
	size_t size = 32, n, error = -1;

	input = (malloc(sizeof(char) * size));
	if (!input)
	{
		write(2, "Unable to allocate memory", 25);
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
		switch (core(input, splitted, env, av))
		{
			case 0:
				exit(0);

			case 1:
				continue;

			case -1:
				return (-1);
		}
	}

	free(input);
	return (0);
}


/**
 * core - the heart of our shell
 * @input: the imput of the user
 * @splitted: proccessed input
 * @env: enviroment variable
 * @av: arguments
 *
 * Return: 10 if success, 0 if exit, 1 if continue, -1 if return-1
*/

int core(char *input, char **splitted, char **env, char **av)
{
	char *command;
	int i;
	struct stat st;

	if (_strcmp(splitted[0], "exit"))
	{
		array_cleaner(splitted);
		free(input);
		return (0);
	}
	if (_strcmp(splitted[0], "env"))
	{
		for (i = 0; env[i]; i++)
		{
			write(1, env[i], _strlen(env[i]));
			write(1, "\n", 1);
		}
		array_cleaner(splitted);
		return (1);
	}
	if (stat(splitted[0], &st) == 0)
	{
		execute(splitted[0], splitted, av[0]);
		array_cleaner(splitted);
		return (1);
	}
	command = getpath(env, splitted[0]);
	if (!command)
	{
		write(2, av[0], _strlen(av[0]));
		write(2, ": No such file or directory\n", 28);
	}
	else if (execute(command, splitted, av[0]) == -1)
	{
		perror(": ");
		return (-1);
	}
	array_cleaner(splitted);
	free(command);
	return (10);
}
