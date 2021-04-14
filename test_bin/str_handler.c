#include "narita.h"

/**
 * _strlen - Counts the length of a string
 * @str: string to count
 *
 * Return: the ammount of chars of the string
*/

int _strlen(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
	}

	return (i);
}

/**
 * _strdup - duplicates a given string
 * @str: string to duplicae
 *
 * Return: A pointer to a duplicate of the string given
*/

char *_strdup(char *str)
{
	char *dup;
	int i;

	for (i = 0; str[i]; i++)
	{
	}

	dup = malloc((sizeof(char) * i) + 1);
	if (!dup)
	{
		write(2, "Unable to allocate memory", 25);
		exit(1);
	}

	for (i = 0; str[i]; i++)
	{
		dup[i] = str[i];
	}
	dup[i] = '\0';

	return (dup);
}