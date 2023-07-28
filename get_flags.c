#include "main.h"

/**
 * get_flags - Calculate active flags from the format string.
 * @format: The formatted string in which to find the flags.
 * @i: The index from which to start analyzing the format string.
 * Return: The combined flags as an integer.
 */
int get_flags(const char *format, int *i)
{
	/* Flags characters: - + 0 # ' ' */
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	/* Corresponding flags values: F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0 */
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	int j, curr_i;
	int flags = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		/* Check if the current character is one of the flags characters */
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
		{
			if (format[curr_i] == FLAGS_CH[j])
			{
				/* If found, combine the corresponding flag to the 'flags' integer */
				flags |= FLAGS_ARR[j];
				break;
			}
		}

		/* If the current character is not one of the flags characters, exit the loop */
		if (FLAGS_CH[j] == '\0')
			break;
	}

	/* Update the index 'i' to the last character that was analyzed */
	*i = curr_i - 1;

	return (flags);
}

