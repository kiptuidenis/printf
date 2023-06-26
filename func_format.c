#include "main.h" 

/* handle_char - Handles the character format and
 * returns the number of characters printed
 */
int handle_char(va_list arg_list)
{
    char carr = (char)va_arg(arg_list, int);
    _putchar(carr);
    return 1;
}

/**
 * handle_string - Handles the string format and returns
 * the number of characters printed
 */
int handle_string(va_list arg_list)
{
    int char_count = 0;
    char *str = va_arg(arg_list, char*);
    if (str)
    {
        for(int j = 0; str[j]; j++)
        {
            _putchar(str[j]);
            char_count++;
        }
    }
    return char_count;
}

/**
 * handle_percent - Handles the percent symbol and returns
 * the number of characters printed
 */
int handle_percent(va_list arg_list)
{
    (void)arg_list;
    _putchar('%');
    return 1;
}

/**
 * func_format - Selects the right handler
 * based on the format character
 */
int func_format(char c, va_list arg_list)
{
    switch (c) 
    {
        case 'c': return handle_char(arg_list); 
        case 's': return handle_string(arg_list);  
        case '%': return handle_percent(arg_list);  
        default: _putchar(c); return 1;  
    }
}

