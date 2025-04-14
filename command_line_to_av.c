/*
strtok() work:
-it splits a string into tokens based on delimiters (e.g., space " ").

- On the first call: pass your full string (e.g., strtok(line, " "))

- On later calls: pass NULL (e.g., strtok(NULL, " ")) to keep splitting the same string.

=> It returns:

    A pointer to the next token

    NULL when no more tokens are found
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    printf("Type anything here: ");
    fflush(stdout);

    nread = getline(&line, &len, stdin);
    if (nread == -1)
    {
        free(line);
        return 0;
    }

    // Remove the trailing newline
    if (line[nread - 1] == '\n')
        line[nread - 1] = '\0';

    // Use strtok to split the line
    char *token = strtok(line, " ");
    while (token != NULL)
    {
        printf("[%s]\n", token);  // simulate av[i]
        token = strtok(NULL, " ");
        // to continue split the same string until it reaches the Null terminator
    }

    free(line);
    return 0;
}
