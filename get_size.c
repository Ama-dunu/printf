#include "main.h"

/**
 * get_size - Calculate the size to cast the argument.
 * @format: The formatted string in which to find the size.
 * @i: The index from which to start analyzing the format string.
 * Return: The size to be used for casting the argument.
 */
int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	/* Check if the current character indicates a size specifier */
	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;

	/* If size is not found, update the index 'i' to the last character that was analyzed */
	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}

