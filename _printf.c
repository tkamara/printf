#include "main.h"

void print_buffer(char buffer[], int *bytes);

/**
 * _printf - recreates the standard printf() function
 * @format: input string with possible format specifiers
 *
 * Return: number of characters printed to standard output
 */
int _printf(const char *format, ...)
{
	int format_counter;
	int char_counter = 0;
	int printed_bytes = 0;
	int printed = 0;
	char char_buffer[BUFFER_SIZE];
	va_list arg_list;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);

	for (format_counter = 0; format && (*(format + format_counter)) != '\0';
			format_counter++)
	{
		if (*(format + format_counter) != '%')
		{
			char_buffer[char_counter++] = *(format + format_counter);
			if (char_counter == BUFFER_SIZE)
				print_buffer(char_buffer, &char_counter);
			printed_bytes++;
		}
		else
		{
			print_buffer(char_buffer, &char_counter);
			++format_counter;
			printed = print_handler(format, &format_counter, arg_list, char_buffer);
			if (printed == -1)
				return (-1);
			printed_bytes += printed;
		}
	}
	print_buffer(char_buffer, &char_counter);
	return (printed_bytes);
}

/**
 * print_buffer - prints the contents of the input buffer to standard output
 * @buffer: input (character) buffer
 * @bytes: number of already printed characters
 *
 * Return: nothing
 */
void print_buffer(char buffer[], int *bytes)
{
	if (*bytes > 0)
		write(1, &buffer[0], *bytes);
	*bytes = 0; /* modifies <printed_bytes> without having to return it */
}

