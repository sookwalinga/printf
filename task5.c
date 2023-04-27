#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_hex - prints a hexadecimal number with at least 2 digits
 * @num: the number to print
 */
static void print_hex(unsigned char num)
{
if (num < 16)
putchar('0');
printf("%X", num);
}

/**
 * print_string - prints a string with special formatting
 * @str: the string to print
 *
 * This function prints a string, but replaces non-printable characters
 * with the "\xXX" notation.
 */
static void print_string(char *str)
{
while (*str != '\0')
{
if (*str < ' ' || *str >= 127)
{
printf("\\x");
print_hex(*str);
}
else
{
putchar(*str);
}
str++;
}
}

/**
 * print_int - prints an integer
 * @num: the integer to print
 */
static void print_int(int num)
{
printf("%d", num);
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

/* handle %S */
if (*(p + 1) == 'S')
{
char *str = va_arg(args, char *);
print_string(str);
count += strlen(str);
p += 2;
continue;
}

/* handle %d */
if (*(p + 1) == 'd')
{
int num = va_arg(args, int);
print_int(num);
count += 1;  /* count the number of digits printed */
p += 2;
continue;
}

/* handle other conversions */
/* ... */

/* if we get here, we don't recognize the conversion */
putchar(*p++);
count++;
}

va_end(args);

return (count);
}
