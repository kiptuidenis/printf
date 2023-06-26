#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 *print_number - converts integer to string
 *@args: string to be printed
 *
 *Return: number of characters printed
 */

int print_number(va_list args)
{
	int n;
	int check;
	int len;
	unsigned int num;

	n = va_arg(args, int);
	check = 1;
	len = 0;

	if (n < 0)
	{
		len += _putchar('-');
		num = n * -1;
	}
	else
		num = n;

	for (; num / check > 9; )
		check *= 10;

	for (; check != 0; )
	{
		len += _putchar('0' + num / check);
		num %= check;
		check /= 10;
	}

	return (len);
}

/**
 *print_unsigned_number - prints unsigned integer
 *@n: integer to be printed
 *
 *Return: number of characters printed
 */

int print_unsigned_number(unsigned int n)
{
	int check;
	int len;
	unsigned int num;

	check = 1;
	len = 0;
	num = n;

	for (; num / check > 9; )
		check *= 10;

	for (; check != 0; )
	{
		len += _putchar('0' + num / check);
		num %= check;
		check /= 10;
	}

	return (len);
}

/**
 *print_integer - prints integers
 *@args: integer to be printed
 *
 *Return: number of characters printed
 */

int print_integer(va_list args)
{
	int n;

	n = print_number(args);
	return (n);
}



/**
 *print_char - prints characters
 *@args: character to be printed
 *
 *Return: 1
 */

int print_char(va_list args)
{
	char character;

	character = va_arg(args, int);
	_putchar(character);

	return (1);
}

/**
 *print_percent - handles the % specifier
 *@args: % specifier
 *
 *Return: 1
 */

int print_percent(va_list args)
{
	(void)args;
	_putchar('%');

	return (1);
}
