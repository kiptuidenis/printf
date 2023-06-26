#include "main.h"

void print_buffer(char buffer[], int *buff_pos);

/**
 * _printf - emulates the functionality of the printf function.
 * It accepts an arbitrary number of arguments.
 * @format: format specifier argument.
 * Return:  total number of printed characters
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flaglist, findwidth, myprecision, thesize, buff_pos = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_pos++] = format[i];
			if (buff_pos == BUFF_SIZE)
				print_buffer(buffer, &buff_pos);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_pos);
			flaglist = get_flaglist(format, &i);
			findwidth = get_findwidth(format, &i, list);
			myprecision = get_myprecision(format, &i, list);
			thesize = get_thesize(format, &i);
			++i;
			printed = handles_print(format, &i, list, buffer,
				flaglist, findwidth, myprecision, thesize);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_pos);

	va_end(list);

	return (printed_chars);
}
/**
 * print_buffer - prototype, monitors buffer contents
 * and uses the write system to print them if buff_pos > 0
 * @buffer: character array
 * @buff_pos: position to add next char.
 */
void print_buffer(char buffer[], int *buff_pos)
{
	if (*buff_pos > 0)
		write(1, &buffer[0], *buff_pos);

	*buff_pos = 0;
}

