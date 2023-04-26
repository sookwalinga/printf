#include "main.h"
#include <stdarg.h>
#include <string.h>

/**
 * _printf - prints formatted output to stdout
 * @format: format string
 * Return: num of x-ters printed (without null byte)
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;

va_start(args, format);

while (*format != '\0')
{
if (*format == '%')
{
format++;
switch (*format) {
case 'c':
putchar(va_arg(args, int));
count++;
}
else if (*format == 's')
{
char *str = va_arg(args, char *);
fputs(str, stdout);
}
else if (*format == '%')
{
putchar('%');
count++;
}
} else {
putchar(*format);
count++;
}
format++;
}

va_end(args);

return (count);
}
