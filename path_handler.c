#include "narita.h"

/**
 * _getenv - gets the enviroment variable needed
 * @name: name of the environment variable
 * @environ: enviroment variables
 *
 * Return: the line with the environment variable
*/

char *_getenv(char *name, char **environ)
{
	int i, j, n;

	n = _strlen(name);
	for (i = 0; environ[i]; i++)
	{
		for (j = 0; environ[i][j] == name[j]; j++)
		{
		}
		if (j == n && environ[i][j] == '=')
			return (environ[i]);

	}
	return (NULL);
}

/**
 * getpath - Gets the PATH variable
 * @environ: enviroment variable
 *
 * Return: the splitted PATH variable
*/

char *getpath(char **environ, char *input)
{
	char **path = NULL, *command;
	unsigned int input_len, path_len, i, j, k;
	struct stat st;

	
	path = _split(_getenv("PATH", environ), "=:");
	input_len = _strlen(input);

	for (i = 1; path[i]; i++)
	{
		path_len = _strlen(path[i]);
		command = malloc(sizeof(char) * (path_len + input_len + 2));
		if (!command)
		{
			write(2, "Unable to allocate memory", 25);
			exit(1);
		}
		
		for (j = 0; path[i][j]; j++)
			command[j] = path[i][j];

		command[j++] = '/';

		for (k = 0; input[k]; k++)
			command[j + k] = input[k];

		command[j + k] = '\0';

		if (stat(command, &st) == 0)
		{
			array_cleaner(path);
			return (command);
		}
		free(command);
	}
	array_cleaner(path);

	return (NULL);
}
