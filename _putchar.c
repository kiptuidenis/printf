#include <unistd.h>
#include "main.h"

/**
 *_putchar - prints the character c to stdout
 *@c: The character to be printed
 *
 *Return: 1 on success, else return -1
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

