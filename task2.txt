#include <stdarg.h>
#include "main.h"

/**
 * _putchar - writes a character to stdout
 * @c: the character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}

/**
 * _printf - print formatted output to stdout
 * @format: the format string
 *
 * Return: the number of characters printed
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

if (*format == 'b')
{
unsigned int n = va_arg(args, unsigned int);
int i;

for (i = 31; i >= 0; i--)
{
if ((n >> i) & 1)
_putchar('1');
else
_putchar('0');
}

count += 32;
}
else
{
_putchar('%');
count++;
}
}
else
{
_putchar(*format);
count++;
}

format++;
}

va_end(args);

return (count);
}
