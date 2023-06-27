#include <stdout.h>
#include "main.h"

/**
 * _printf - Custom printf function for standard output
 * @format: The format to print
 *
 * Return: The number of characters printed
 */

int _printf(const char *format, ...)
{
	int char_count = 0;
	va_list arg_list;

	va_start(arg_list, format);

	for (int i = 0; format && format[i]; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			char_count++;
			continue;
		}

		/* Move to next character for conversion specifier */
		i++;
		char_count += func_format(format[i], arg_list);
	}

	va_end(arg_list);
	return (char_count);
}

