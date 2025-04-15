#include "stdio.h"
#include "string.h"
#include "stdlib.h"

/**
* print_path_dirs - print each dir in PATH on a new line
*/

void print_path_dirs(void)
{
    char *path = getenv("PATH");

    if (!path)
    {
        printf("PATH not found.\n");
        return;
    }

    // duplicate because strtok modifies the original one
    char *path_copy = strdup(path);

    if (!path_copy)
    {
        perror("strdup");
        return;
    }

    char *token = strtok(path_copy, ":");
    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, ":");
    }

    free(path_copy); // Free the memory we allocated with strdup
}

int main(void)
{
    print_path_dirs();
    return (0);
}