#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - Print formatted output to stdout
 * @format: The format string
 * Return: numb of chars printed (excluding null byte)
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
char c = (char) va_arg(args, int);
putchar(c);
count++;
}
else if (*format == 's')
{
char *s = va_arg(args, char *);
while (*s != '\0')
{
putchar(*s);
count++;
s++;
}
}
else if (*format == '%')
{
putchar('%');
count++;
}
else
{
printf("Error: Invalid conversion specifier");
return -1;
}
}
else
{
putchar(*format);
count++;
}
format++;
}
va_end(args);
return (count);
}
