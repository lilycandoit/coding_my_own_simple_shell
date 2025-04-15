/*
environ is a global variable provided by the system:

    It’s an array of strings

    Each string looks like: "KEY=value"

    It ends with a NULL pointer

    It is automatically available in your program — no need to pass it explicitly
*/

#include "stdio.h"

extern char **environ; // declare external  variable

int main(void)
{
    int i = 0;
    while (environ[i])
    {
        printf("%s\n", environ[i]);
        i++;
    }

    return (0);
}