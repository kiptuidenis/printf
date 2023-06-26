#include <stdarg.h>
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *print_string - prints strings, and (null) if string = NULL
 *@args: string to be printed
 *
 *Return: number of characters printed in the string
 */

int print_string(va_list args)
{
	int num_char = 0;
	char *string;

	string = va_arg(args, char *);

	if (string == NULL)
		string = "(null)";
	while (*string != '\0')
	{
		_putchar(*string);
		num_char++;
		string++;
	}

	return (num_char);
}

/**
 *find_specifier - finds a match for the specifier following the % character.
 *@format: format string
 *@format_index: Current format index
 *@printer: array of specifiers (c, s, %)
 *@specifier_size: size of specifier array
 *
 *Return: Specifier index if specifier is found. -1 otherwise
 */

int find_specifier(const char *format, int format_index, specifier *printer
		   , int specifier_size)
{
	int specifier_index;

	for (specifier_index = 0; specifier_index < specifier_size;
	     specifier_index++)
	{
		if (format[format_index + 1] ==
		    printer[specifier_index].specifier[0])
		{
			return (specifier_index);
		}
	}
		
	return (-1);
}

/**
 *handle_specifier - calls find_specifier function to
 *determine index of specifier
 *@format: format string
 *@format_index: current format index
 *@printer: array of specifiers
 *@args: arguments passed
 *
 *Return: number of characters printed if valid specifier is found
 *by 'find_specifier function'. -1 if no valid specifier is found
*/

int handle_specifier(const char *format, int format_index,
		     specifier *printer, va_list args)
{
	int specifier_size = 5;
	int specifier_index = find_specifier(format, format_index,
					     printer, specifier_size);
	int charPrinted = 0;

	if (specifier_index != -1)
	{
		charPrinted = printer[specifier_index].funcs(args);
			if (charPrinted == -1)
				return (-1);
		return (charPrinted);
	}
	else
	{
		charPrinted = handle_normal_character(format, format_index);
		charPrinted += handle_normal_character(format, format_index + 1);

		return (charPrinted);
	}
}

/**
 *handle_normal_character - prints a normal character(not a specifier)
 *@format: format string
 *@format_index: current format index
 *
 *Return: Always 1
 */

int handle_normal_character(const char *format, int format_index)
{
	_putchar(format[format_index]);
	return (1);
}

/**
 *get_func - gets the required print function depending on specifier
 *@format: pointer to the format string. Specifies how the output
 *should be printed
 *@args: arguments to be printed
 *
 *Return: number of printed characters
 */

int get_func(const char *format, va_list args)
{
	specifier printer[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_integer},
		{"i", print_integer}
	};
	int printed_chars = 0;
	int format_index = 0;
	int buffer;

	while (format[format_index] != '\0')
	{
		if (format[format_index] == '%')
		{
			buffer = handle_specifier(format, format_index,
						  printer, args);
			if (buffer == -1)
				return (-1);
			printed_chars += buffer;
			format_index += 2;
		}
		else
		{
			buffer = handle_normal_character(format, format_index);
			printed_chars += buffer;
			format_index += buffer;
		}
	}

	return (printed_chars);
}
