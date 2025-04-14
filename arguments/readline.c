/*
getline function:

- It reads a whole line (until Enter is pressed) from a file or standard input.

- Automatically resizes the buffer to fit the input ( it auto allocates memory, therefore we need to free it at the end)

- Returns:
    The number of characters read (including newline \n)
    -1 when the user hits Ctrl+D (EOF = End Of File)
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *line = NULL; // hold th input line
	size_t len = 0; // size of the buffer
	ssize_t nread; // store number of characters read

	while (1) {
		printf("Please type something, anything: ");

		nread = getline(&line, &len, stdin); // read user input

		if (nread  == -1) // EOF or error
			break;

		printf("%s", line); // print back what user typed
	}

	free(line);
	return (0);
}
