#include "narita.h"

/**
 * main - Entry function
 * @ac: Ammount of arguments passed
 * @av: Arguments passed
 * @env: Enviroment variables
 *
 * Return: 0 if success
*/

int main(int ac, char **av, char **env)
{
	char *input, **splitted = NULL;
	int id, i;
	size_t size = 32, n, minus = -1;

	input = (malloc(sizeof(char) * size));
	if (!input)
	{
		perror("No se pudo reservar la memoria");
		exit(1);
	}

	while (1)
	{
		write(1, "$uwu ", 5);
		n = getline(&input, &size, stdin);
		if (n == minus)
		{
			write(1, "\n", 1);
			break;
		}
		if (input[0] == '\n')
			continue;

		input[n - 1] = ' ';
		splitted = _split(input, " ");
		id = fork();

		if (id != 0)
			wait(NULL);

		if (id == 0 && execve(splitted[0], splitted, NULL) == -1)
		{
			perror("Error: ");
			return (-1);
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
