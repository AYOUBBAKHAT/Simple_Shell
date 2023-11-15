#include "shell.h"

int _execute(char **command, char **argv)
{
	char *fullcmd;
    pid_t child;
    int status;
    
	full_cmd = _getpath(command[0]);
	if (!full_cmd)
	{
		printerror(argv[0], command[0], idx);
		freearray2D(command);
		return (127);
	}
	child = fork();
    	if (child == 0)
    	{
        	if (execve(command[0], command, environ) == -1)
        	{
        		free(full_cmd), full_cmd = Null;
        		freearray2D(command);
        	}
    	}
    	else
    	{
        	waitpid(child, &status, 0);
        	freearray2D(command);
        	free(full_cmd), full_cmd = Null;
    	}
    	return (WEXITSTATUS(status));
}
