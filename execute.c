/*
execve() replaces the current running program with a completely new one.	It completely erases and starts the new one

Needs full path like /bin/ls	Not just ls

Arguments must be in an array	First one usually the program name

Last item in argv[] must be NULL	Always end with NULL

Only returns if something went wrong	Otherwise, it never comes back!
*/

#include <stdio.h>
#include <unistd.h>

/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(void)
{
    char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

    printf("Before execve\n");
    if (execve(argv[0], argv, NULL) == -1)
    {
        perror("Error:");
    }
    printf("After execve\n");
    return (0);
}