#ifndef NARITA_H
#define NARITA_H

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

/* -------- Prototypes -------- */

/* simple_shell.c */
int execute(char *command, char **arguments, char *av);
int core(char *input, char **split, unsigned int lines, char **env, char **av);
/*void signhandler(int signum);*/
void error_message(int lines, char *split, char **av);

/* str_handlers */
int _strlen(char *str);
char *_strdup(char *str);
char **_split(char *str, char *delim);
int _strcmp(char *origin, char *comp);
int digit_calc(int n);

/* path_handler.c */
char *_getenv(char *name, char **environ);
char *getpath(char **environ, char *input);

/* memory_handler.c */
void array_cleaner(char **fire);


#endif /* ifndef NARITA_H */
