/*
wait() makes the parent pause until the child process is done.

It blocks (stops) the parent until the child finishes.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork & wait example
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t child_pid;
    /* status is a variable where the child’s exit status will be stored. */
    int status;

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("Error:");
        return (1);
    }
    if (child_pid == 0)
    {
        printf("Wait for me, wait for me\n");
        sleep(3);
    }
    else
    {
        wait(&status); /* in simple cases, can do: wait(NULL) */
        printf("Oh, it's all better now\n");
    }
    return (0);
}
