#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int _strlen(char *str)
{
    int i;

    for (i = 0; str[i]; i++)
    {
    }
    
    return (i);
}

char **_split(char *str, char *delim)
{
    int i, j, chars, lines = 1;
    char **splitted, *token;

    for (i = 0; str[i]; i++)
        if (str[i] == delim[0])
            lines++;
    
    splitted = malloc((lines + 1) * sizeof(char *));
    if (!splitted)
    {
        printf("No se pudo alocar");
        exit(1);
    }
    token = strtok(str, delim);
    j = 0;

    while (token)
    {
        chars = _strlen(token);
        splitted[j] = malloc((chars + 1) * sizeof(char));
        if (!splitted)
        {
            printf("No se pudo alocar");
            for (; j != 0 ; j--)
                free(splitted[j - 1]);
            free(splitted);
            exit(1);
        }

        for (i = 0; i < chars; i++)
        {
            splitted[j][i] = token[i];
        }
        splitted[j][i] = '\0';
        j++;
        token = strtok(0, delim);
    }
    splitted[j] = 0;
    return (splitted);
}

int main(void)
{
    int i;
    char texto[] = "Cuatro o 5 palabras";
    char delim[] = " ";
    char **storage;

    storage = _split(texto, delim);

    printf("2da palabra = %s\n", storage[3]);

    for (i = 0; storage[i]; i++)
    {
        free(storage[i]);
    }
    free(storage);

    return (0);
}