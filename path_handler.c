#include "narita.h"

/**
 * _getenv - gets the enviroment variable needed
 * @name: name of the environment variable
 * @environ: enviroment variables
 *
 * Return: the line with the environment variable
*/

char *_getenv(const char *name, char **environ)
{
	int i, j, n;

	for (n = 0; name[n]; n++)
	{
	}

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

char **getpath(char **environ)
{
	char **path;

	path = _split(_getenv("PATH", environ), "=:");

	return (path);
}
