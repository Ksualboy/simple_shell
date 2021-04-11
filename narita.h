#ifndef NARITA_H
#define NARITA_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

/* -------- Prototypes -------- */

/* str_handlers */
int _strlen(char *str);
char *_strdup(char *str);
char **_split(char *str, char *delim);

/* path_handler.c */
char *_getenv(const char *name, char **environ);
char **getpath(char **environ);


#endif /* ifndef NARITA_H */
