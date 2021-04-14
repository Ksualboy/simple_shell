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
	unsigned int lines = 1;

	input = (malloc(sizeof(char) * size));
	if (!input)
	{
		write(2, "Unable to allocate memory", 25);
		exit(1);
	}
	while (1)
	{
		if (isatty(0) == 1)
			write(1, "#cisfun$ ", 9);
		n = getline(&input, &size, stdin);
		if (n == error)
			break;
		if (n == 1)
			continue;

		input[n - 1] = ' ';
		splitted = _split(input, " ");
		if (!*splitted)
		{
			free(splitted);
			continue;
		}
		switch (core(input, splitted, lines, env, av))
		{
			case 0:
				exit(0);
			case 1:
				continue;
			case -1:
				return (-1);
		}
		lines++;
	}
	free(input);
	return (0);
}


/**
 * core - the heart of our shell
 * @input: the imput of the user
 * @split: proccessed input
 * @lines: ammount of lines
 * @env: enviroment variable
 * @av: arguments
 *
 * Return: 10 if success, 0 if exit, 1 if continue, -1 if return-1
*/

int core(char *input, char **split, unsigned int lines, char **env, char **av)
{
	char *command;
	int i;
	struct stat st;

	if (_strcmp(split[0], "exit"))
	{
		array_cleaner(split);
		free(input);
		return (0);
	}
	if (_strcmp(split[0], "env"))
	{
		for (i = 0; env[i]; i++)
		{
			write(1, env[i], _strlen(env[i]));
			write(1, "\n", 1);
		}
		array_cleaner(split);
		return (1);
	}
	if (stat(split[0], &st) == 0)
	{
		execute(split[0], split, av[0]);
		array_cleaner(split);
		return (1);
	}
	command = getpath(env, split[0]);
	if (!command)
		error_message(lines, split[0], av);

	else if (execute(command, split, av[0]) == -1)
	{
		perror(": ");
		return (-1);
	}
	array_cleaner(split);
	free(command);
	return (10);
}

/**
 * error_message - Prints the error message
 * @lines: Ammount of lines so far
 * @split: proccessed input
 * @av: ammount of lines
*/

void error_message(int lines, char *split, char **av)
{
	char *strlines = numtostr(lines);

	write(2, av[0], _strlen(av[0]));
	write(2, ": ", 2);
	write(2, strlines, _strlen(strlines));
	write(2, ": ", 2);
	write(2, split, _strlen(split));
	write(2, ": not found\n", 12);
	free(strlines);
}
