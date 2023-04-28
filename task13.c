#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100

/**
 * reverse_string - Reverses a given string
 * @str: The string to reverse
 *
 * Return: void
 */
void reverse_string(char *str)
{
int length = strlen(str);
for (int i = 0; i < length / 2; i++)
{
char temp = str[i];
str[i] = str[length - i - 1];
str[length - i - 1] = temp;
}
}

/**
 * print_reversed_string - Formats and prints a reversed string
 * @str: The string to reverse and print
 *
 * Return: void
 */
void print_reversed_string(char *str)
{
char *reversed_str = malloc(sizeof(char) * (strlen(str) + 1));
strcpy(reversed_str, str);
reverse_string(reversed_str);
printf("%s", reversed_str);
free(reversed_str);
}

/**
 * handle_reversed_string - Handles the 'r' custom conversion specifier
 * @args: The list of arguments for printf
 *
 * Return: 0
 */
int handle_reversed_string(va_list args)
{
char *str = va_arg(args, char *);
print_reversed_string(str);
return (0);
}

/**
 * my_printf - Main printf function
 * @format: The format string
 *
 * Return: 0
 */
int my_printf(const char *format, ...)
{
va_list args;
va_start(args, format);
int i = 0;
while (format[i] != '\0')
{
if (format[i] == '%')
{
i++;
if (format[i] == 'r')
{
handle_reversed_string(args);
}
}
else
{
putchar(format[i]);
}
i++;
}
va_end(args);
return (0);
}
