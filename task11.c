#include "main.h"
#include <stdarg.h>

/**
 * format_with_zero_flag - Formats the given value as a string with the 0 flag
 * character, if applicable.
 *
 * @format: The format string to use.
 * @value: The value to format.
 *
 * Returns: The formatted string.
 */
char *format_with_zero_flag(const char *format, int value)
{
char *output;
int has_zero_flag = 0;
int i;

for (i = 0; format[i] != '\0'; i++) 
{
if (format[i] == '0' && i == 0) 
{
has_zero_flag = 1;
break;
} 
else if (format[i] == '%') 
{
i++;
while (format[i] != '\0') 
{
if (format[i] == '0') 
{
has_zero_flag = 1;
break;
} 
else if (format[i] == 'd' || format[i] == 'f') 
{
break;
}
i++;
}
if (has_zero_flag) 
{
break;
}
}
}

if (has_zero_flag) 
{
output = (char *) malloc(12 * sizeof(char));
if (sprintf(output, "%0d", value) < 0) 
{
free(output);
}
} else 
{
output = (char *) malloc(8 * sizeof(char));
if (sprintf(output, "%d", value) < 0) 
{
free(output);
}
}
return (output);
}
