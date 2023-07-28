#include "main.h"

/**
 * get_size - Calculates all the size that would cast the argument task
 * @format: Format string in which is to print the arguments
 * @i: List of arguments to be printed
 * Return: Precision
 */
int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}
