#include "main.h"
#include <stdio.h>

int print_char(va_list list, char buffer[])
{
	char character = va_arg(list, int);
	int index = 0;

	buffer[index++] = character;
	buffer[index] = '\0';
	return (write(1, &buffer[0], 1));
}

int print_string(va_list list, char buffer[])
{
	char *string = va_arg(list, char *);
	int string_length = 0;
	UNUSED(buffer);
	
	while (*(string + string_length) != '\0')
		string_length++;

	return(write(1, string, string_length));
}

int print_percent(va_list list, char buffer[])
{
	UNUSED(list);
	UNUSED(buffer);
	
	return (write(1, "%%", 1));
}

int print_int(va_list list, char buffer[])
{
	int print_index = BUFFER_SIZE - 2;
	int is_negative = 0;
	int input_int = va_arg(list, int);
	unsigned int u_input_int;

	if (input_int == 0)
		buffer[print_index--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';
	u_input_int = (unsigned int)input_int;

	if (input_int < 0)
	{
		u_input_int = (unsigned int)((-1) * input_int);
		is_negative = 1;
	}

	while (u_input_int > 0)
	{
		buffer[print_index--] = ((u_input_int % 10) + '0');
		u_input_int /= 10;
	}

	print_index++;

	return (write_number(is_negative, print_index, buffer));
}

