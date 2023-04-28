#include "main.h"

#define BUFFER_SIZE 1024

/**
 * _printf - prints formatted output to stdout
 * @format: format string
 * Return: input of characters printed
 */
int _printf(const char *format, ...)
{
int i, j;
int output = 0;
int width;
char padding;
char specifier = '\0';
int flag_plus = 0;

va_list args;
va_start(args, format);

while (*format != '\0')
{
if (*format == '%')
{
format++;

width = 0;
padding = ' ';

if (*format == '+' && specifier != 'c' && specifier != 's')
{
flag_plus = 1;
format++;
}

if (*format == ' ' && specifier != 'c' && specifier != 's')
{
if (!flag_plus)
{
output += putchar(' ');
}
format++;
}

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
else if (*format == 'S')
{
char *str = va_arg(args, char *);
while (*str != '\0')
{
if (*str == '\n')
{
output += printf("\\n");
}
else if (isprint(*str))
{
output += putchar(*str);
}
else
{
output += printf("\\x%02X", (unsigned char)*str);
}
str++;
}
format++;
}
else if (*format == 'c')
{
int c = va_arg(args, int);
output += printf("%c", c);
}
else if (*format == 'd' || *format == 'i')
{
int input = va_arg(args, int);
output += printf("%d", input);
}
else if (*format == 'u')
{
unsigned int input = va_arg(args, unsigned int);
output += printf("%u", input);
}
else if (*format == 'o')
{
unsigned int input = va_arg(args, unsigned int);
output += printf("%o", input);
}
else if (*format == 'x')
{
unsigned int input = va_arg(args, unsigned int);
output += printf("%x", input);
}
else if (*format == 'X')
{
unsigned int input = va_arg(args, unsigned int);
output += printf("%X", input);
}
else if (*format == 'p')
{
void *ptr = va_arg(args, void *);
output += printf("%p", ptr);
}
else if (*format == 'b')
{
unsigned int input = va_arg(args, unsigned int);
int binary[32], i = 0;

if (input == 0)
{
output += printf("%u", input);
}
while (input > 0)
{
binary[i] = input % 2;
input /= 2;
i++;
}
for (j = i - 1; j >= 0; j--)
{
output += printf("%d", binary[j]);
}
}
else if (*format == 'r')
{
output += printf("%%r");
}
else if (*format == '%')
{
output += printf("%%");
}
else
{
output += printf("%s", format);
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
