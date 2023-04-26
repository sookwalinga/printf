#include <stdarg.h>
#include <string.h>
<<<<<<< HEAD
#include <stdio.h>
=======
>>>>>>> 5db05da590c792f26d989ab9c2e0a3195f86b340

/**
 * _printf - prints formatted output to stdout
 * @format: format string
 * Return: num of x-ters printed (without null byte)
 */
int _printf(const char *format, ...)
{
int num_printed = 0;
va_list args;
va_start(args, format);

while (*format != '\0')
{
if (*format == '%')
{
format++;
<<<<<<< HEAD
if (*format == 's')
{
const char *str = va_arg(args, const char *);
num_printed += printf("%s", str);
=======
switch (*format) {
case 'c':
putchar(va_arg(args, int));
count++;
>>>>>>> 5db05da590c792f26d989ab9c2e0a3195f86b340
}
else if (*format == 'c')
{
int c = va_arg(args, int);
num_printed += printf("%c", c);
}
else if (*format == 'd' || *format == 'i')
{
int num = va_arg(args, int);
num_printed += printf("%d", num);
}
<<<<<<< HEAD
else if (*format == 'u')
{
unsigned int num = va_arg(args, unsigned int);
num_printed += printf("%u", num);
}
else if (*format == 'o')
{
unsigned int num = va_arg(args, unsigned int);
num_printed += printf("%o", num);
}
else if (*format == 'x')
{
unsigned int num = va_arg(args, unsigned int);
num_printed += printf("%x", num);
}
else if (*format == 'X')
{
unsigned int num = va_arg(args, unsigned int);
num_printed += printf("%X", num);
}
else if (*format == '%')
{
num_printed += printf("%%");
}
}
else 
{
=======
} else {
>>>>>>> 5db05da590c792f26d989ab9c2e0a3195f86b340
putchar(*format);
num_printed++;
}
format++;
}
va_end(args);
return (num_printed);
}
