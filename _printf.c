#include "main.h"
#include <stdarg.h>
<<<<<<< HEAD
#include <string.h>
=======
>>>>>>> 18f8f6b48f7b03424ea6e9ff59dd54bbb700282d

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
<<<<<<< HEAD
switch (*format) {
case 'c':
putchar(va_arg(args, int));
=======
if (*format == 'c')
{
char c = (char) va_arg(args, int);
putchar(c);
>>>>>>> 18f8f6b48f7b03424ea6e9ff59dd54bbb700282d
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
<<<<<<< HEAD
} else {
=======
else
{
putchar('%');
putchar(*format);
count += 2;
}
}
else
{
>>>>>>> 18f8f6b48f7b03424ea6e9ff59dd54bbb700282d
putchar(*format);
count++;
}
format++;
}

va_end(args);

return (count);
}
