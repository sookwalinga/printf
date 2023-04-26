#include "main.h"
#include <stdarg.h>

/**
 * print_binary - Prints an unsigned integer in binary form
 *
 * @n: The unsigned integer to print
 */
void print_binary(unsigned int n)
{
int binary[32];
int i = 0, j;

/* Convert to binary representation */
while (n > 0)
{
binary[i] = n % 2;
n = n / 2;
i++;
}

/* Reverse binary representation */
for (j = 0; j < i / 2; j++)
{
int temp = binary[j];
binary[j] = binary[i - j - 1];
binary[i - j - 1] = temp;
}

/* Print binary representation */
for (j = 0; j < i; j++)
{
putchar(binary[j] + '0');
}
}

/**
 * _printS - Prints a formatted string to the console
 *
 * @format: The format string to print
 * @...: Additional arguments to print
 *
 * Return: The number of characters printed
 */
int _printS(const char *format, ...)
{
va_list args;
int count = 0;

va_start(args, format);

while (*format)
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'b':
print_binary(va_arg(args, unsigned int));
break;
default:
putchar('%');
putchar(*format);
count += 2;
break;
}
count++;
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
