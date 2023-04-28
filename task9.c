#include "main.h"
#include <stdio.h>
#include <ctype.h>

/**
 * is_digit - checks if a character is a digit
 * @c: the character to check
 *
 * Return: 1 if the character is a digit, 0 otherwise.
 */
int is_digit(char c)
{
return (c >= '0' && c <= '9');
}

/**
 * handle_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int handle_width(const char *format, int *i, va_list list)
{
int curr_i;
int width = 0;
for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
{
if (is_digit(format[curr_i]))
{
width *= 10;
width += format[curr_i] - '0';
}
else if (format[curr_i] == '*')
{
curr_i++;
width = va_arg(list, int);
break;
}
else
break;
}
*i = curr_i - 1;
return (width);
}
