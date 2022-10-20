#include "main.h"

/**
 * write_number - writes a number to standard output
 * @is_negative: flag indicating whether number is negative or not
 * @print_index: index of first digit of number to be printed
 * @buffer: output buffer
 *
 * Return: number of characters (digits) written to stdout
 */
int write_number(int is_negative, int print_index, char buffer[])
{
	int num_length = BUFFER_SIZE - print_index - 1;
	char extra_char = 0;

	if (is_negative)
		extra_char = '-';

	return (write_num(print_index, buffer, num_length, extra_char));
}

/**
 * write_num - helper function for write_num
 * @print_index: index of first digit of number to be printed
 * @buffer: output buffer
 * @num_length: length of number to print in digits
 * @extra_char: extra characters to precede number e.g. negative sign (-)
 *
 * Return: number of characters (digits) written to stdout
 */
int write_num(int print_index, char buffer[], int num_length, char extra_char)
{
	if (extra_char != 0)
		num_length++;
	if (extra_char)
		buffer[--print_index] = extra_char;
	return (write(1, &buffer[print_index], num_length));
}

