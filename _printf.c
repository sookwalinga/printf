#include "main.h"

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
count += putchar(va_arg(args, int));
}
else if (*format == 's')
{
count += printf("%s", va_arg(args, char *));
}
else if (*format == '%')
{
count += putchar('%');
}
else
{
printf("Error: Invalid conversion specifier");
return (-1);
}
}
else
count += putchar(*format);
format++;
}
va_end(args);
return (count);
}
