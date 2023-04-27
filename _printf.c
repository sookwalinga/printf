#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_char - Print a single character to stdout
 * @c: The character to print
 * Return: 1 (always)
 */
int print_char(char c)
{
putchar(c);
return (1);
}

/**
 * print_str - Print a string to stdout
 * @str: The string to print
 * Return: The number of characters printed
 */
int print_str(char *str)
{
int count = 0;

while (*str != '\0')
{
putchar(*str);
count++;
str++;
}

return (count);
}

/**
 * print_percent - Print a percent sign to stdout
 * Return: 1 (always)
 */
int print_percent(void)
{
putchar('%');
return (1);
}

/**
 * _printf - Print formatted output to stdout
 * @format: The format string
 * Return: The number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
int count = 0;
va_list args;
va_start(args, format);

while (*format != '\0')
{
if (*format == '%')
{
format++;
if (*format == 'c')
{
count += print_char((char) va_arg(args, int));
}
else if (*format == 's')
{
count += print_str(va_arg(args, char *));
}
else if (*format == '%')
{
count += print_percent();
}
else
{
printf("Error: Invalid conversion specifier");
return (-1);
}
}
else
count += print_char(*format);
format++;
}
va_end(args);
return (count);
}
