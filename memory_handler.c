#include "narita.h"

/**
 * array_cleaner - Cleans a double pointer
 * @fire: Double pointer to clean (Best name)
 */

void array_cleaner(char **fire)
{
	int i;

	for (i = 0; fire[i]; i++)
	{
		free(fire[i]);
	}

	free(fire);
}

/**
 * pointer_maker - Creates a pointer
 * @fire: Double pointer to clean (Best name)
 */

char *pointer_maker(size_t size)
{
	char *pointer;

	pointer = (malloc(sizeof(char) * size));
	if (!pointer)
		write(2, "Unable to allocate memory", 25);

	return (pointer);
}