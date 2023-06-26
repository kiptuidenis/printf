#include "main.h" 

/**
 * _printf - function that accepts a limited
 * number of format specifiers
 * @char_count - set counter
 * @arg_list - declare a variable to handle the variadic function
 * @format - format
 * Return - number of chars printed
 */

int _printf(const char *format, ...)
{
    int char_count = 0;  
    va_list arg_list;  // 
    va_start(arg_list, format); 
    for (int i = 0; format && format[i]; i++) 
    {
        if (format[i] != '%')
        {
            _putchar(format[i]);
            char_count++;
            continue;
        }

        i++;
        char_count += func_format(format[i], arg_list);
    }

    va_end(arg_list);
    return char_count;
}

