#include <stdio.h> // Print and error output (printf, perror)
#include <stdlib.h> // General utilities like exit()
#include <unistd.h> // System calls: fork(), execve(), getpid(), sleep()
#include <sys/types.h> // Data types for system calls (like pid_t)
#include <sys/wait.h> // Process control: wait(), exit status macros

/**
 * main - fork example
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t child_pid;
    int i, status;

    char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

    for (i = 0; i < 5; i++)
    {
        child_pid = fork();
        if (child_pid == -1)
        {
            perror("Error:");
            return (1);
        }

        if (child_pid == 0)
        {
            printf("Child %d running: ls -l /tmp\n", getpid());
            execve(argv[0], argv, NULL);
            perror("execve failed"); // only runs if execve fails
            exit(1); // exit child on failure
        }
        else
        {
            wait(&status);
            printf("Parent %d waited for child %d\n", getpid(), child_pid);
        }
    }
    return (0);
}