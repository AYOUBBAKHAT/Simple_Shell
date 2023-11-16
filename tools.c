#include "shell.h"
/**
 *freearray2D - Frees a 2D array of characters
 *@array: The 2D array to be freed
 *Return: Nothing
 */
void freearray2D(char **array)
{
	int i;
	if (!array)
		return;
	for (i = 0; array[i]; i++)
	{
		free(array[i]);
		array[i] = NULL;
	}

	free(array);
	array = NULL;
}
/**
 *print_error - Prints an error message to the standard error output
 *@name: The name to be printed in the error message
 *@cmd: The command to be printed in the error message
 *@idx: The index to be printed in the error message
 */
void print_error(char *name, char *cmd, int idx)
{
	char *index, mssg[] = ": not found\n";

	index = _itoa(idx);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, mssg, _strlen(mssg));

	free(index);
}

/**
*_itoa - Converts an integer to a string
*@n: The integer to be converted. This is the integer that will be converted to a string.
*This function first checks if the number is zero, if it is, it simply assigns '0'
*to the first position of the buffer. If the number is not zero, it converts the
*number to a string by repeatedly dividing the number by 10 and storing the
*remainder in the buffer. After the conversion, it reverses the string to get
*the correct order.
*Return: A string representation of the integer
*/
char *_itoa(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buffer[i] = '\0';
	reverse_string(buffer, i);

	return (_strdup(buffer));
}
/**
* reverse_string - Reverses a string
* @str: The string to be reversed. This is the string that will be reversed.
* @len: The length of the string. This is the length of the string to be reversed.
*/
void reverse_string(char *str, int len)
{
	char tmp;
	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}
