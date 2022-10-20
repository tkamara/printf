#include "main.h"

/**
 * print_handler - prints an input argument depending on its data type
 * @fmt: input string containing format specifiers
 * @index: the index of the format specifier in the input fmt string
 * @list: char array of arbitrary number of unnamed arguments
 * @buffer: character buffer carrying characters to print to stdout
 *
 * Return: number of printed characters to standard output
 */
int print_handler(const char *fmt, int *index, va_list list, char buffer[])
{
	int counter, unknown_length = 0, printed_chars = -1;
	fmt_t print_functions[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'d', print_int}, {'i', print_int}, {'\0', NULL}
	};
	for (counter = 0; print_functions[counter].data_type != '\0'; counter++)
		if (fmt[*index] == print_functions[counter].data_type)
			return (print_functions[counter].print_func(list, buffer));

	if (print_functions[counter].data_type == '\0')
	{
		if (fmt[*index] == '\0')
			return (-1);
		unknown_length += write(1, "%%", 1);
		unknown_length += write(1, &fmt[*index], 1);
		return (unknown_length);
	}
	return (printed_chars);
}

