#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>

#define BUFFER_SIZE 1024
#define UNUSED(i) (void)(i)

typedef struct fmt
{
	char data_type;
	int (*print_func)(va_list, char[]);
} fmt_t;

int _printf(const char *format, ...);

int print_handler(const char *, int *, va_list, char[]);

int print_char(va_list, char[]);
int print_string(va_list, char[]);
int print_percent(va_list, char[]);
int print_int(va_list, char[]);

int write_number(int, int, char[]);
int write_num(int, char[], int, char);

#endif

