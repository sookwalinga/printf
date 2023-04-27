#include "main.h"
#include <stdarg.h>

/**
 * print_hex - prints a hexadecimal number with at least 2 digits
 * @num: the number to print
 */
void print_hex(unsigned char num)
{
if (num < 16)
putchar('0');
printf("%X", num);
}
/**
 * print_string - prints a string
 * @str: the string to print
 */
void print_string(char *str)
{
while (*str != '\0')
{
putchar(*str++);
}
}

/**
 * print_int - prints an integer
 * @num: the integer to print
 */
void print_int(int num)
{
printf("%d", num);
}

/**
 * handle_conversion - handles a conversion character
 * @p: a pointer to the conversion character
 * @args: a va_list containing the arguments
 *
 * Return: the number of characters printed
 */
int handle_conversion(const char **p, va_list args)
{
int count = 0;
/* handle %S */
if (**p == 'S')
{
char *str = va_arg(args, char *);
print_string(str);
count += strlen(str);
(*p)++;
}
/* handle %d */
else if (**p == 'd')
{
int num = va_arg(args, int);
print_int(num);
count += 1;  /* count the number of digits printed */
(*p)++;
}
/* handle other conversions */
else
{
/* ... */
}
return (count);
}
/**
 * _printHex - custom implementation of printf
 * @format: the format string
 * @...: the arguments to print
 *
 * Return: the number of characters printed
 */
int _printHex(const char *format, ...)
{
va_list args;
int count = 0;
const char *p = format;
va_start(args, format);
while (*p != '\0')
{
if (*p != '%')
{
putchar(*p++);
count++;
continue;
}
count += handle_conversion(&p, args);
}
va_end(args);
return (count);
}
