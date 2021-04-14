#include "narita.h"

int main()
{
    char *input;
    size_t chars_read, size = 32, error = -1;
    unsigned int lines = 1;

    input = malloc(sizeof(char) * 32);
    while(1)
    {
        write(1, "#cisnotfun$ ", 12);
        chars_read = getline(&input, &size, stdin);
        
        if (chars_read == error)
        {
            perror("error: ");
            exit(-1);
        }
        if(execve() == -1)
        lines++;
    }
}