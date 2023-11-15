#include "shell.h"

/*
 * read_line - Read a line from standard input.
 *
 * This function reads a line from the standard input and returns it as a
 * dynamically allocated string.
 *
 * Return: A pointer to the allocated string containing the read line.
 * If an error occurs or the end of the file is reached, NULL is returned.
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t n;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	n = getline(&line, &len, stdin);
	if (n == -1)
	{
		free(line);
		return NULL;
	}

	return (line);
}
