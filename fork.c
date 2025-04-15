/*
fork()	Creates a new process - creates a copy of your current process (like CLONING)
So you end up with two processes running the same code:
the parent and the child.

Returns 0	Inside the child
Returns child PID	Inside the parent
Returns -1	If something went wrong
Used for	Making sure your shell keeps running while a command is executed
*/

#include <stdio.h>
#include <unistd.h>

/**
 * main - fork example
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t my_pid;
    pid_t child_pid;

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("Error:");
        return (1);
    }
    my_pid = getpid();
    printf("My pid is %u\n", my_pid);
    if (child_pid == 0)
    {
        printf("(%u) I'm child!\n", my_pid);
    }
    else
    {
        printf("(%u) %u, I am your father\n", my_pid, child_pid);
    }
    return (0);
}