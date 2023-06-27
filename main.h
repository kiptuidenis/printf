#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * struct Specifier - specifier structure
 * @specifier: specifies
 * @funcs: function printer
 */
typedef struct Specifier
{
	char *specifier;
	int (*funcs)(va_list args);
} specifier;

int find_specifier(const char *format, int format_index,
				   specifier *printer, int specifier_size);
int _printf(const char *format, ...);
int handle_normal_character(const char *format, int format_index);
int get_func(const char *format, va_list args);
int print_string(va_list args);
int handle_specifier(const char *format, int format_index,
					 specifier *printer, va_list args);
int print_char(va_list args);
int print_number(va_list args);
int print_unsigned_number(unsigned int n);
int print_percent(va_list args);
int _putchar(char c);
int print_integer(va_list args);

#endif

