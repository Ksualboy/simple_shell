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
	size_t size = 1024;
	unsigned int lines = 1;

/*	signal(SIGINT, signhandler); */
	input = (malloc(sizeof(char) * size));

	while (1)
	{
		write(1, "#cisfun$ ", 9);
		getline(&input, &size, stdin);


		splitted = _split(input, " \n\t\r");
			if (splitted[0] == NULL)
			continue;

		switch (core(input, splitted, lines, env, av))
		{
			case 0:
				return (-1);

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
 * @env: enviroment variable
 * @av: arguments
 * @split: splitted string
 * @lines: number of lines
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

/*
*void signhandler(int signum __attribute__((unused)))
*{
*	write(1, "\n", 1);
*	write(1, "#cisfun$ ", 9);
*}
*/

/**
 * error_message - function for error message
 * @split: splitted string
 * @lines: number of lines
 * @av: argument
 *
 * Return: 10 if success, 0 if exit, 1 if continue, -1 if return-1
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
}
