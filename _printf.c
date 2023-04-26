#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - prints formatted output to stdout
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
int output = 0;
va_list args;
va_start(args, format);

while (*format != '\0')
{
if (*format == '%')
{
format++;
if (*format == 's')
{
const char *str = va_arg(args, const char *);
output += printf("%s", str);
}
else if (*format == 'r')
{
const char *str = va_arg(args, const char *);
output += printf("%r", str);
}
else if (*format == 'c')
{
int c = va_arg(args, int);
output += printf("%c", c);
}
else if (*format == 'd' || *format == 'i')
{
int num = va_arg(args, int);
output += printf("%d", num);
}
else if (*format == 'u')
{
unsigned int num = va_arg(args, unsigned int);
output += printf("%u", num);
}
else if (*format == 'o')
{
unsigned int num = va_arg(args, unsigned int);
output += printf("%o", num);
}
else if (*format == 'p')
{
void *ptr = va_arg(args, void *);
output += printf("%p", ptr);
}
else if (*format == 'x')
{
unsigned int num = va_arg(args, unsigned int);
output += printf("%x", num);
}
else if (*format == 'X')
{
unsigned int num = va_arg(args, unsigned int);
output += printf("%X", num);
}
else if (*format == '%')
{
output += printf("%%");
}
}
else
{
putchar(*format);
output++;
}
format++;
}
va_end(args);
return (output);
}
