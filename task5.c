#include "main.h"
#include <stdarg.h>
#include <stdio.h>

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
while (*str != '\0') 
{
if (*str < ' ' || *str >= 127) 
{
printf("\\x");
print_hex(*str);
count += 4;
} else 
{
putchar(*str);
count++;
}
str++;
}
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
