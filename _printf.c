#include "main.h"
#include <stdarg.h>

/**
 * _printf - prints formatted output to stdout
 * @format: format string
 * Return: number of characters printed (excluding null byte)
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
if (*format == 'c')
{
char c = (char) va_arg(args, int);
putchar(c);
count++;
}
else if (*format == 's')
{
char *str = va_arg(args, char *);
fputs(str, stdout);
// count += strlen(str);
}
else if (*format == '%')
{
putchar('%');
count++;
}
else
{
putchar('%');
putchar(*format);
count += 2;
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
