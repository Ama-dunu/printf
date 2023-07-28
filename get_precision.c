#include "main.h"

/**
<<<<<<< HEAD
 * get_precision - Calculate the precision for printing.
 * @format: The formatted string in which to find the precision.
 * @i: The index from which to start analyzing the format string.
 * @list: The va_list of arguments.
 * Return: The precision value.
=======
 * get_precision - Calculates the precision for printing task
 * @format: Formatted string to print the arguments on this task
 * @i for  List of arguments to be printed.
 * @: list of arguments.
 * done by partners
 * Return: Precision.
>>>>>>> dcddece9c8429154f88265f83c64a97e8df707dc
 */
int get_precision(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precision = -1;

	/* If the current character is not a '.', return default precision (-1) */
	if (format[curr_i] != '.')
		return (precision);

	precision = 0;

	/* Loop through the characters after the '.' to find the precision */
	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		/* If the character is a digit, update the precision accordingly */
		if (is_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		/* If the character is '*', get the precision from the va_list of arguments */
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(list, int);
			break;
		}
		/* If the character is not a digit or '*', stop analyzing the precision */
		else
		{
			break;
		}
	}

	/* Update the index 'i' to the last character that was analyzed */
	*i = curr_i - 1;

	return (precision);
}

