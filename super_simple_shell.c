#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

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
      printf("#cisfun$ ");
      n = getline(&input, &size, stdin);
      if (n == minus)
      {
         printf("Lo mataste capo X-X\n");
         break;
      }
        if (input[0] == '\n')
          continue;


      input[n-1] = ' ';

      
      splitted = _split(input, " ");
      id = fork();

      if (id != 0)
         wait(NULL);

      if (id == 0)
      {
         if (execve(splitted[0], splitted, NULL) == -1)
         {
            perror("ERROR ERROR ERROR: ");
            return (-1);
         }
      }
   }

   if (splitted)
   {
    for (i = 0; splitted[i]; i++)
    {
        free(splitted[i]);
    }
    free(splitted);
   }

   free(input);

    return(0);
}