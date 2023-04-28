#include "main.h"
#include <stdarg.h>
/**
 * handle_flag_minus - Handles "-" flag char for non-custom conversion specifiers
 * @format: A format string containing the conversion specifier to handle
 * @specifier: The current conversion specifier being handled
 *
 * Return: The updated format string with "-" flag applied to current specifier
 */
char *handle_flag_minus(const char *format, char specifier)
{
char *result = NULL;
int i = 0, j = 0, count = 0;
int k;
while (format[i])
{
if (format[i] == specifier)
{
result = malloc(sizeof(char) * (count + 3));
if (!result)
return ((char *) format);
for (k = 0; k < i; k++)
result[j++] = format[k];
result[j++] = '-';
result[j++] = specifier;
i++;
while (format[i] && (format[i] >= '0' && format[i] <= '9'))
{
count++;
i++;
}
if (count > 0)
{
char *field_width = malloc(sizeof(char) * (count + 1));
if (!field_width)
{
free(result);
return ((char *) format);
}
for (k = 0; k < count; k++)
field_width[k] = format[i - count + k];
field_width[count] = '\0';
strcat(result, field_width);
j += count;
free(field_width);
}
if (format[i] == 'h' || format[i] == 'l' || format[i] == 'z' || format[i] == 'j')
i++;
return (result);
}
i++;
count++;
}
return ((char *) format);
}
