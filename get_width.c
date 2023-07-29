#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @index: Pointer to the index of the current character in the format string.
 * @args: List of arguments to be printed.
 *
 * Return: Width.
 */
int get_width(const char *format, int *index, va_list args)
{
	int current_index = *index + 1;
	int width = 0;

	for (; format[current_index] != '\0'; current_index++)
	{
		if (is_digit(format[current_index]))
		{
			width *= 10;
			width += format[current_index] - '0';
		}
		else if (format[current_index] == '*')
		{
			current_index++;
			width = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*index = current_index - 1;

	return (width);
}

