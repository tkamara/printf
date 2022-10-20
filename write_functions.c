#include "main.h"

int write_number(int is_negative, int print_index, char buffer[])
{
	int num_length = BUFFER_SIZE - print_index - 1;
	char extra_char = 0;

	if (is_negative)
		extra_char = '-';

	return (write_num(print_index, buffer, num_length, extra_char));
}

int write_num(int print_index, char buffer[], int num_length, char extra_char)
{
	if (extra_char != 0)
		num_length++;
	if (extra_char)
		buffer[--print_index] = extra_char;
	return (write(1, &buffer[print_index], num_length));
}

