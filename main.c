 #include "shell.h"
/**
* main - Simple Shell main function 
* @ac: Count of argumnents
* @av: Arguments
*Return: 0 Always (success).
*/

int main(int ac, char **argv)
{
	char *line = NULL; **command = NULL;
	int i, status = 0; 
	(void) ac;
	(void) argv;
	
 
	while (1)
	{
   		line = read_line();	
   		if (line == NULL) /* reache EOF ctr + D */
   		{
   			if(isatty(STDIN_FILENO))
   			   write(STDOUT_FILENO,"\n", 1);
		   	return (status);
	    }
   			

     	command = tokenizer(line);
     	if (!command)
     	   continue;
     	   
     	for (i=0; command[i]; i++)
     	    printf("%s\n", command[i]);
        
	   /* status = _execute(command; argv); */
	}

}
