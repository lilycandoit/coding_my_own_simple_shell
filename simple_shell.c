#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

// read a line from user
// split it into tokens (words)
// use first word as the command path
// pass the rest of the words as arguments

/*
[Parent]
    ↓ fork()
[Child] → execve() → becomes /bin/ls
[Parent] → wait()   → waits until /bin/ls is done
*/

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    char *argv[64]; //max 64 args

    while (1)
    {
        printf("cisfun$ ");

        nread = getline(&line, &len, stdin);

        if (nread == -1)
            break; // EOF

        // tokenize input
        int i = 0;
        char *token = strtok(line, " \n");

        while (token)
        {
            argv[i++] = token; /* meaning the 1st argument */
            token = strtok(NULL, " \n"); /* go to the next token */
        }
        argv[i] = NULL; // execve needs argv to end with NULL

        // if input empty
        if (argv[0] == NULL)
            continue;

        // fork and execve
        pid_t pid = fork(); // create a new process
        if (pid == 0)
        {
            execve(argv[0], argv, NULL); // replace child with the new program
            perror("execve failed");
            exit(1);
        }
        else
        {
            wait(NULL);
            // pauses the parent until the child process ends.
        }
    }

    free(line);
    return (0);
}
