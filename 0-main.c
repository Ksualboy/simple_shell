#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct node
{
    char *str;
    struct node *next; 
} node_t;

char *_getenv(const char *name)
{
    extern char **environ;
    int i, j, n;

    for (n = 0; name[n]; n++)
    {
    }

    for (i = 0; environ[i]; i++)
    {
        for (j = 0; environ[i][j] == name[j]; j++)
        {   
        }
        if (j == n && environ[i][j] == '=')
            return (environ[i]);
    }
    return (NULL);
}

char *_strdup(char *str)
{
    char *dup;
    int i;

    /* printf("%s\n", str); */
    for (i = 0; str[i]; i++)
    {
    }

    /* printf("%d\n", i); */
    dup = malloc((sizeof(char) * i) + 1);
    if (!dup)
    {
        return(NULL);
    }

    for (i = 0; str[i]; i++)
    {
        dup[i] = str[i];
    }

    dup[i] = '\0';

    return (dup);
    
}

node_t *add_node_end(node_t **head, char *str)
{
	node_t *temp;
	node_t *search = *head;

	temp = malloc(sizeof(node_t));
	if (!temp)
		return (NULL);

	temp->str = _strdup(str);
    /* printf("%s\n", temp->str); */

	if (!temp->str)
	{
		free(temp);
		return (NULL);
	}

	temp->next = NULL;

	if (!search)
		*head = temp;
	else
	{
		while (search->next)
			search = search->next;

		search->next = temp;
	}

    /* printf("%s\n", temp->str); */
	return (temp);

}

size_t print_list(const node_t *h)
{
	int i;
	node_t *search = (node_t *)h;

	if (!h)
		return (0);

	for (i = 0; search; i++)
	{
		if (!search->str)
			printf("[0] (nil)\n");
		else
			printf("%s\n", search->str);
		search = search->next;
	}

	return (i);
}

int main(void)
{
    char *path, *token;

    node_t *head = NULL;

    path = _getenv("PATH");
    token = strtok(path, "=:");
    token = strtok(NULL, "=:");
    while (token)
    {

        if (!add_node_end(&head, token))
        {
            printf("se murió\n");
            return (-1);
        }
        token = strtok(NULL, "=:");
    }

    print_list(head);

    return (0);
}
