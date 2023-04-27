#include "main.h"
#include <stdarg.h>

/**
 * add_plus_flag - adds the + flag to the result
 * @result: a string containing the result of the conversion
 *
 * Return: a new string with the + flag applied to the result, or NULL
 */
static char *add_plus_flag(char *result)
{
char *formatted_result = NULL;
if (result[0] != '-')
{
formatted_result = malloc(strlen(result) + 2);
sprintf(formatted_result, "+%s", result);
}
return (formatted_result);
}

/**
 * add_space_flag - adds the space flag to the result
 * @result: a string containing the result of the conversion
 *
 * Return: a new string with the space flag applied to the result, or NULL
 */
static char *add_space_flag(char *result)
{
char *formatted_result = NULL;
if (result[0] != '-')
{
formatted_result = malloc(strlen(result) + 2);
sprintf(formatted_result, " %s", result);
}
return (formatted_result);
}

/**
 * add_hash_flag - adds the # flag to the result
 * @result: a string containing the result of the conversion
 *
 * Return: a new string with the # flag applied to the result, or NULL
 */
static char *add_hash_flag(char *result)
{
char *formatted_result = NULL;
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
return (formatted_result);
}

/**
 * handle_flags - handle +, space, and # flags for conv. specifiers
 * @flags: a string containing the flags to handle
 * @result: a string containing the result of the conversion
 *
 * Return: a string containing the result with the flags applied
 */
char *handle_flags(const char *flags, char *result)
{
char *formatted_result = NULL;
if (strchr(flags, '+'))
{
formatted_result = add_plus_flag(result);
}
else if (strchr(flags, ' '))
{
formatted_result = add_space_flag(result);
}
else if (strchr(flags, '#'))
{
formatted_result = add_hash_flag(result);
}
if (!formatted_result)
{
return (result);
}
free(result);
return (formatted_result);
}
