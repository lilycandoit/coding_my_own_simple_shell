#include "stdio.h"
#include "stdlib.h"
#include "string.h"

extern char **environ;

/**
* _env_count - count how many variable in environ
*/

int _env_count(void)
{
    int count = 0;
    while (environ[count])
        count++;
    return count;
}
/**
* _setenv - mimic setenv function - to change or add new variable
*/

int _setenv(const char *name, const char *value, int overwrite)
{
    size_t name_len = strlen(name);
    size_t value_len = strlen(value);
    int i = 0;
    char *new_var = NULL;

    // change the existing variable
    while (environ[i])
    {
        // check for match like "NAME=" first
        if (strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
        {
            if (!overwrite) // same as overwrite == 0
                return (0); // meaning success

            // if overwrite, allocate memory for new string "name=value"
            new_var = malloc(name_len + value_len + 2); // +1 for '=' and +1 for '\0'
            if (!new_var)
                return (-1); // failed

            // format new_var as 'name=value'
            sprintf(new_var, "%s=%s", name, value);
            environ[i] = new_var;
            // update old env variable with the new one

            return (0); // successfully overwrite
        }
        i++;
    }

    // add new variable
    int count = _env_count();
    char **new_environ = malloc((count + 2) * sizeof(char *)); // allocate memory
    if (!new_environ)
        return (-1);

    for (i = 0; i < count; i++)
        new_environ[i] = environ[i]; // Copy all current environment variables into the new array
    new_var = malloc(name_len + value_len + 2);
    if (!new_var)
        return (-1);

        // format as "name=value" and write it into the allocated new_var
        sprintf(new_var, "%s=%s", name, value);
        new_environ[count] = new_var; // add the new varible to the end of the new environ array
        new_environ[count + 1] = NULL; // null-terminate the array

        environ = new_environ; // update the old environ array with new_environ
        return (0);
}


int main(void)
{
    char *var_name = "MY_VAR";

    // Test 1: Add new environment variable
    if (_setenv(var_name, "hello", 0) == 0)
        printf("Added: %s=hello\n", var_name);
    else
        printf("Failed to add %s\n", var_name);

    // Check it appears in environ
    for (int i = 0; environ[i]; i++)
    {
        if (strncmp(environ[i], var_name, 6) == 0)
            printf("Found: %s\n", environ[i]);
    }

    // Test 2: Try to overwrite (should not happen if overwrite=0)
    if (_setenv(var_name, "world", 0) == 0)
        printf("Tried to overwrite with overwrite=0\n");

    // Test 3: Overwrite with overwrite=1
    if (_setenv(var_name, "new_world_2025", 1) == 0)
        printf("Overwritten: %s=new_world_2025\n", var_name);

    // Final check
    for (int i = 0; environ[i]; i++)
    {
        if (strncmp(environ[i], var_name, 6) == 0)
            printf("Final: %s\n", environ[i]);
    }

    return 0;
}
