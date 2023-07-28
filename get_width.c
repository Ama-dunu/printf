#include "main.h"

/**
 * get_width - Calculate the width for printing.
 * @format: The formatted string in which to find the width.
 * @i: The index from which to start analyzing the format string.
 * @list: The va_list of arguments.
 * Return: The width value.
 */
int get_width(const char *format, int *i, va_list list)
{
	int curr_i;
	int width = 0;

	/* Loop through the characters to find the width */
	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		/* If the character is a digit, update the width accordingly */
		if (is_digit(format[curr_i]))
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
		/* If the character is '*', get the width from the va_list of arguments */
		else if (format[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(list, int);
			break;
		}
		/* If the character is not a digit or '*', stop analyzing the width */
		else
		{
			break;
		}
	}

	/* Update the index 'i' to the last character that was analyzed */
	*i = curr_i - 1;

	return (width);
}

