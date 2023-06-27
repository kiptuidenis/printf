#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 *_printf - prints the string that is formatted
 *@format: format specifier
 *
 *Return: Number of characters that have been printed
 */

int _printf(const char *format, ...)
{
	int printed_chars;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	printed_chars = get_func(format, args);
	va_end(args);

	return (printed_chars);
}
