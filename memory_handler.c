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
