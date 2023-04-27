#include "main.h"

#define BUFFER_SIZE 1024

/**
 * _printf - prints formatted output to stdout
 * @format: format string
 * Return: num of characters printed
 */
int _printf(const char *format, ...)
{
int i, j;
int output = 0;
int width;
char padding;

va_list args;
va_start(args, format);

while (*format != '\0')
{
if (*format == '%')
{
format++;

width = 0;
padding = ' ';

if (padding == '-' && width > 0)
{
putchar(*format);
output++;
for (i = 1; i < width; i++)
{
putchar(' ');
output++;
}
}

if (padding == '0' && width > 0)
{
putchar(*format);
output++;
for (i = 1; i < width; i++)
{
putchar(' ');
output++;
}
}

if (padding == '.' && width > 0)
{
putchar(*format);
output++;
for (i = 1; i < width; i++)
{
putchar(' ');
output++;
}
}

if (*format == 's')
{
const char *str = va_arg(args, const char *);
output += printf("%s", str);
}
else if (*format == 'c')
{
int c = va_arg(args, int);
output += printf("%c", c);
}
else if (*format == 'd' || *format == 'i')
{
int num = va_arg(args, int);
output += printf("%d", num);
}
else if (*format == 'u')
{
unsigned int num = va_arg(args, unsigned int);
output += printf("%u", num);
}
else if (*format == 'o')
{
unsigned int num = va_arg(args, unsigned int);
output += printf("%o", num);
}
else if (*format == 'x')
{
unsigned int num = va_arg(args, unsigned int);
output += printf("%x", num);
}
else if (*format == 'X')
{
unsigned int num = va_arg(args, unsigned int);
output += printf("%X", num);
}
else if (*format == 'p')
{
void *ptr = va_arg(args, void *);
output += printf("%p", ptr);
}
else if (*format == 'b')
{
unsigned int num = va_arg(args, unsigned int);
int binary[32], i = 0;
while (num > 0)
{
binary[i] = num % 2;
num /= 2;
i++;
}
for (j = i - 1; j >= 0; j--)
{
output += printf("%d", binary[j]);
}
}
else if (*format == 'r')
{
const char *str = va_arg(args, const char *);
int len = strlen(str);
for (i = len - 1; i >= 0; i--)
{
output += printf("%c", str[i]);
}
}
else if (*format == '%')
{
output += printf("%%");
}
}
else
{
putchar(*format);
output++;
}
format++;
}
va_end(args);
return (output);
}

