#include "main.h"
#include <stdarg.h>

/**
 * handle_precision - Handles precision for non-custom conversion specifiers
 * @format: The format string to parse
 * @start_i: The index to start parsing the format string from
 * @args: The va_list of arguments
 *
 * Return: The precision value
 */
int handle_precision(const char *format, int *start_i, va_list args)
{
int i = *start_i;
int precision = -1; /* Initialize to -1 to indicate no precision specified */
char curr_char = format[i];
/* Check if the current character is a period */
if (curr_char == '.')
{
i++;
curr_char = format[i];
/* Check if the next character is a digit */
if (curr_char >= '0' && curr_char <= '9')
{
precision = 0;
/* Parse the precision value */
while (curr_char >= '0' && curr_char <= '9')
{
precision = precision * 10 + (curr_char - '0');
i++;
curr_char = format[i];
}
}
/* Check if the next character is a * */
else if (curr_char == '*')
{
i++;
precision = va_arg(args, int);
}
/* If the next character is neither a digit nor a *, it is an error */
else
{
/* TODO: Handle error */
}
}
/* Update the start index and return the precision */
*start_i = i;
return (precision);
}
