#include "shell.h"
char *_getpath(char *command)
{
	char *path_env, *full_cmd, *dir;
	struct stat st;
	
	path_env = _getenv("PATH");
	
	dir = strtok(path_env, ":");
	while (dir)
	{
		/* size = len(directory) + len(commad) + 2 ('/' and '\0') */
		full_cmd = malloc(_strlen(dir) + _strlen(command) + 2);
		if (full_cmd)
		{
			_strcpy(full_cmd, dir);
			_strcat(full_cmd, "/");
			_strcat(full_cmd, command);
			if (stat(full_cmd, &st) == 0)
			{
				free(path_env);
				return (full_cmd);
			}
			free(full_cmd), full_cmd = NULL;
			
			dir = strtok(NULL, ":");
		}
	}
	free(path_env);
	return (NULL);
}
int main(int ac, char **av)
{
	char *full_cmd;
	
	full_cmd = _getpath(av[1]);
	if (full_cmd)
		printf("%s\n", full_cmd);
	else
		printf("does not exist");
}
