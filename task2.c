#include "main.h"
#include <stdio.h>

/**
 * print_binary - Print the binary representation of an unsigned int
 * @num: The unsigned int to be printed
 */
void print_binary(unsigned int num)
{
if (num > 1)
print_binary(num / 2);
printf("%u", num % 2);
}

/**
 * prints_specifier - Print out the corresponding conversion specifier
 * @c: The conversion specifier character
 * @num: The unsigned integer to be printed
 */
void prints_specifier(char c, unsigned int num)
{
switch (c)
{
case 'b':
print_binary(num);
break;
default:
printf("Error: Invalid conversion specifier");
break;
}
}
