#include "main.h"

/**
 * handle_char - Handles format of char `c`
 * @arg_list: arg list where the character is taken
 *
 * Return: 1
 */
int handle_char(va_list arg_list)
{
	char carr = (char)va_arg(arg_list, int);

	_putchar(carr);
	return (1);
}

/**
 * handle_string - Handles format of string `s`
 * @arg_list: arg list where the string is taken
 *
 * Return: Number of characters in the string
 */
int handle_string(va_list arg_list)
{
	int char_count = 0;
	char *str = va_arg(arg_list, char*);

	if (str)
	{
		for (int j = 0; str[j]; j++)
		{
			_putchar(str[j]);
			char_count++;
		}
	}
	return (char_count);
}

/**
 * handle_percent - Handles format of special character `%%`
 * @arg_list: arg list
 *
 * Return: 1
 */
int handle_percent(va_list arg_list)
{
	(void)arg_list;

	_putchar('%');
	return (1);
}

/**
 * func_format - Function that selects right function for format
 * @c: Character representing format type
 * @arg_list: Argument list holding the argument to format and print
 *
 * Return: Number of characters printed
 */
int func_format(char c, va_list arg_list)
{
	switch (c)
	{
	case 'c':
		return (handle_char(arg_list));
	case 's':
		return (handle_string(arg_list));
	case '%':
		return (handle_percent(arg_list));
	default:
		_putchar(c);
		return (1);
	}
}

