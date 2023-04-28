#include "main.h"
#include <stdio.h>

/**
 * print_short - prints a short number with the given format specifier
 * @format: the format specifier (d, i, u, o, x, or X)
 * @number: the number to print
 */
void print_short(char format, unsigned short number)
{
/* Handle format specifiers for short data type */
switch (format)
{
case 'd':
case 'i':
printf("%hd", (short)number);
break;
case 'u':
printf("%hu", number);
break;
case 'o':
printf("%ho", number);
break;
case 'x':
printf("%hx", number);
break;
case 'X':
printf("%hX", number);
break;
default:
printf("Invalid format specifier");
}
}

/**
 * print_long - prints a long number with the given format specifier
 * @format: the format specifier (d, i, u, o, x, or X)
 * @number: the number to print
 */
void print_long(char format, unsigned long number)
{
/* Handle format specifiers for long data type */
switch (format)
{
case 'd':
case 'i':
printf("%ld", number);
break;
case 'u':
printf("%lu", number);
break;
case 'o':
printf("%lo", number);
break;
case 'x':
printf("%lx", number);
break;
case 'X':
printf("%lX", number);
break;
default:
printf("Invalid format specifier");
}
}

/**
 * print_number - prints a number with the given format and length modifier
 * @format: the format specifier (d, i, u, o, x, or X)
 * @length_modifier: the length modifier (l or h)
 * @number: the number to print
 */
void print_number(char format, char length_modifier, long number)
{
if (length_modifier == 'h')
{
print_short(format, (unsigned short)number);
}
else if (length_modifier == 'l')
{
print_long(format, (unsigned long)number);
}
else
{
printf("Invalid length modifier");
}
}
