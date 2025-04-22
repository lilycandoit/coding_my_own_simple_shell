#include <stdio.h>      /* for printf, fprintf, perror */
#include <stdlib.h>     /* for getenv, malloc, free, exit */
#include <string.h>     /* for strdup, strtok, snprintf */
#include <sys/stat.h>   /* for stat struct and function  */

/**
 * main - find a file in the current PATH
 * @ac: argument count
 * @av: argument vector (list of filenames)
 * Return: 0 on success, 1 on error
 */

 int main(int ac, char **av)
 {
	char *path_env, *path_copy, *dir;
	char full_path[1024];
	struct stat st; /* from sys/stat.h library */
	int i;

	/* if no argument is given */
	if (ac < 2)
	{
		fprintf(stderr, "Usage: %s filename ...\n", av[0]);
		return (1);
	}

	path_env = getenv("PATH");
	if (!path_env) /* PATH is not set */
	{
		fprintf(stderr, "PATH not found in environment\n");
		return (1);
	}

	for (i = 1; i < ac; i++)
	{
		path_copy = strdup(path_env); /* cuz strtok modifies original array */
		if (!path_copy)
		{
			perror("strdup");
			continue; /* to move on and check the next command av[i] */
		}

		dir = strtok(path_copy, ":"); /* get the first dir */
		while (dir)
		{
			sprintf(full_path, "%s/%s", dir, av[i]); /* get the full path from dir and the input */

			if (stat(full_path, &st) == 0) /* if the path found */
			{
				printf("%s\n", full_path);
				break; /* break while loop to move to next file av[i] */
			}

			dir = strtok(NULL, ":"); /* move to the next directory in PATH */
		}

		/* when it comes to end of array, run through all tokens and did not find any matching file */
		if (dir == NULL)
			printf("%s not found in PATH\n", av[i]);

		free(path_copy);
	}
	return (0);
 }
