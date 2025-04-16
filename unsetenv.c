#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "main.h"

// function prototy for setenv
int _setenv(const char *name, const char *value, int overwrite);

/**
* _unsetenv - mimic unsetenv function to remove a variable from the environment
*/

extern char **environ;

int _unsetenv(const char *name)
{
    if (!name || name[0] == '\0')
        return (-1); //invalid input

    size_t name_len = strlen(name);

    for (int i = 0; environ[i]; i++)
    {
        // check if variable name is matched exactly
        if (strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
        {
            while (environ[i])
            {
                environ[i] = environ[i + 1]; //update the old variable with the next one
                i++;
            }

            return (0); // successfully removed
        }
    }

    return (-1); // if not found that name
}

/**
* main - to test the _unsetenv function above
*/
int main(void)
{
    char *var = "MY_TEST_VAR";

    // Step 1: Set it first
    _setenv(var, "hello", 1);
    printf("Set: %s=hello\n", var);

    // Step 2: Show it's present
    for (int i = 0; environ[i]; i++)
    {
        if (strncmp(environ[i], var, strlen(var)) == 0)
            printf("Found: %s\n", environ[i]);
    }

    // Step 3: Remove it
    if (_unsetenv(var) == 0)
        printf("Removed %s\n", var);
    else
        printf("Failed to remove %s\n", var);

    // Step 4: Confirm it's gone
    for (int i = 0; environ[i]; i++)
    {
        if (strncmp(environ[i], var, strlen(var)) == 0)
            printf("Still exists: %s\n", environ[i]);
    }

    return 0;
}

// passed test => all good

// when test result: gcc unsetenv.c setenv.c -o unsetenv
// but gott comment the main section in setenv file