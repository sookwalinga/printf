#include "main.h"
#include <stdarg.h>
#include <string.h>

/**
 * print_char - prints a single character to stdout
 * @args: va_list containing the character to print
 * @count: pointer to the character count
 */
void print_char(va_list args, int *count)
{
char c = (char) va_arg(args, int);
putchar(c);
(*count)++;
}

/**
 * print_string - prints a string to stdout
 * @args: va_list containing the string to print
 * @count: pointer to the character count
 */
void print_string(va_list args, int *count)
{
char *str = va_arg(args, char *);
fputs(str, stdout);
(*count) += strlen(str);
}

/**
 * print_percent - prints a percent sign to stdout
 * @count: pointer to the character count
 */
void print_percent(int *count)
{
putchar('%');
(*count)++;
}

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
if (*format == 'c')
print_char(args, &count);
else if (*format == 's')
print_string(args, &count);
else if (*format == '%')
print_percent(&count);
else
{
print_percent(&count);
putchar(*format);
count++;
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
