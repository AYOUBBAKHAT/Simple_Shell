#include "shell.h"

int is_builtin(char *command)
{
	char *builtins[] = {
	"exit", "env", "setenv",
	"cd", NULL
	};
	int i;

	for (i=0; builtins[i]; i++) 
	{
		if (_strcmp (command, builtins[i]) == 0)
			return (1);
	}
	return (0);
}

void handle_builtin(char **command, char **argv, int status, int idx)
{
	(void) argv;
	(void) idx;
	
	if (_strcmp(command[0], "exit") == 0)
	    exit_shell(command, status);
	
	else if (_strcmp(command[0], "env") == 0)
		print_env(command, status);
}

void exit_shell(char **command, int status)
{
	freearray2D(command);
	exit(status);
}

void print_env (char **command, int status)
{
	int i;
	(void) status;
	
	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	freearray2D(command);
}

