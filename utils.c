#include "main.h"

/**
 * is_printable - Evaluates if a char is printable return 0 if otherwise 
 * @c: Char to be evaluated to give result if tally to the requirement
 * done by partners for submission
 * Return: 1 if c is printable, (0) otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * hexa_code - Append ascci in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @i: Index at which to start appending.
 * @ascii_code means  ASSCI CODE.
 * Return: Always 3
 * done by Nuha
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to_it[] = "0123456789ABCDEF";

	/* The hexa format code is always 2 digits long to meet the requirement of ASSCI */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to_it[ascii_code / 16];
	buffer[i] = map_to_it[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Verifies if char is a digit or word
 * @c: Char to be evaluated to validate the code 
 * redo on purpose
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Casts numb to the specified size
 * @num: Num to be casted to a specific size
 * @size: Number indicating the type to be casted.
 * count of number to cast
 * Return: Casted value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - Casts a number to the specified size
 * @num: Number to be casted
 * @size: Number indicating the type to be casted
 * similer to above: read more
 * Return: Casted value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
