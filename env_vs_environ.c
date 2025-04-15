/*
Both env and environ point to the same array of environment strings.
*/

#include "stdio.h"

extern char **environ;

int main(int ac, char **av, char **env)
{
    (void)ac; (void)av; //unused

    printf("env:  %p\n", (void *)env);
    printf("environ:  %p\n", (void *)environ);

    return(0);
}