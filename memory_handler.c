#include "narita.h"

void array_cleaner(char **fire)
{
    int i;

    for (i = 0; fire[i]; i++)
    {
        free(fire[i]);
    }

    free(fire);
}