#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

ssize_t _putchar(char c);
int _printf(const char *format, ...);
int func_format(char c, va_list arg_list)
int handle_char(va_list arg_list);
int handle_string(va_list arg_list);
int handle_percent(va_list arg_list);

#endif

