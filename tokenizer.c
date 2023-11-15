#include "shell.h"

/**
 * tokenizer - Tokenizes a string into an array of strings.
 * @line: The string to tokenize.
 *
 * Return: An array of strings.
 */
char **tokenizer(char *line)
{
	int i = 0, j = 0;
	char *token, *tmp, **array = NULL;

	if (line == NULL)
		return (NULL);

	tmp = _strdup(line);
	token = strtok(tmp, DELIM);
	if (!token)
	{
		free(line), line = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}

	while (token)
	{
		j++;
		token = strtok(NULL, DELIM);
	}
	free(tmp), tmp = NULL;

	array = malloc(sizeof(char *) * (j + 1));
	if (!array)
	{
		free(line), line = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}

	token = strtok(line, DELIM);
	while (token)
	{
		array[i++] = _strdup(token);
		token = strtok(NULL, DELIM);
	}
	array[i] = NULL;
	free(line), line = NULL;

	return (array);
}

