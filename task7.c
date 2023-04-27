#include "main.h"
#include <stdarg.h>
/**
 * handle_flags - handles the +, space, and # flags for non-custom conversion specifiers
 * @flags: a string containing the flags to handle
 * @result: a string containing the result of the conversion
 *
 * Return: a string containing the result with the flags applied
 */
char *handle_flags(const char *flags, char *result)
{
char *formatted_result = NULL;
// handle the + flag
if (strchr(flags, '+'))
{
if (result[0] != '-')
{
formatted_result = malloc(strlen(result) + 2);
sprintf(formatted_result, "+%s", result);
}
}
// handle the space flag
else if (strchr(flags, ' '))
{
if (result[0] != '-')
{
formatted_result = malloc(strlen(result) + 2);
sprintf(formatted_result, " %s", result);
}
}
// handle the # flag
else if (strchr(flags, '#'))
{
switch (result[0])
{
case 'x':
case 'X':
formatted_result = malloc(strlen(result) + 3);
sprintf(formatted_result, "0%s", result);
break;
case 'o':
if (result[1] != '0')
{
formatted_result = malloc(strlen(result) + 2);
sprintf(formatted_result, "0%s", result);
}
break;
default:
break;
}
}
// if no flags were applied, return the original result
if (!formatted_result)
return result;
// free the original result and return the formatted result
free(result);
return (formatted_result);
}
