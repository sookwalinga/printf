#include "main.h"
#include <stdio.h>

/**
 * print_specifier - Print out the corresponding conversion specifier
 * @c: The conversion specifier character
 * @num: The unsigned integer to be printed
 */
void print_specifier(char c, unsigned int num)
{
switch (c)
{
case 'u':
printf("%u", num);
break;
case 'o':
printf("%o", num);
break;
case 'x':
printf("%x", num);
break;
case 'X':
printf("%X", num);
break;
default:
printf("Error: Invalid conversion specifier");
break;
}
}
