/*
The getenv() function searches the environment list to find the environment variable name, and returns a pointer to the corresponding value string.

char *getenv(const char *name);
*/


#include "stdio.h"
#include "string.h"

extern char **environ;

/**
* _getenv - built getenv manually
* @name: name of the enviroment variable
* Return: the pointer to the value, or NULL if not found
*/

char *_getenv(const char *name)
{
    int i = 0;
    size_t name_len = strlen(name);

    while (environ[i])
    {
        // compare the start string of environ with given name
        if (strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
        {
            // return pointer to value (after '=')
            return (&environ[i][name_len + 1]);
        }
        i++;
    }
    return (NULL); // if not found
}

int main(void)
{
    char *val = _getenv("PATH");

    if (val)
        printf("PATH = %s\n", val);
    else
        printf("PATH not found\n");

    return (0);
}
