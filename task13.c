#include "main.h"
#include <stdarg.h>
#include <string.h>

/**
 * reverse_string - Reverses a string in place.
 * @str: The string to be reversed.
 */
void reverse_string(char *str)
{
int left, right;
char temp;

if (str == NULL)
return;

left = 0;
right = strlen(str) - 1;

while (left < right)
{
temp = str[left];
str[left] = str[right];
str[right] = temp;
left++;
right--;
}
}

/**
 * handle_reversed_string - Handles the custom conversion specifier %r.
 * @format: The format string.
 * @args: The variable argument list.
 *
 * Return: The number of characters printed.
 */
int handle_reversed_string(const char *format, va_list args)
{
char *str = va_arg(args, char *);
int len = strlen(str);

reverse_string(str);
return (fwrite(str, 1, len, stdout));
}
