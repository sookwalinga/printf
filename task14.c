#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * rot13 - Encodes a string using rot13.
 * @s: The string to be encoded.
 *
 * Return: A pointer to the encoded string.
 */
char *rot13(char *s)
{
char *encoded;
int i;

encoded = malloc(sizeof(char) * (strlen(s) + 1));
if (encoded == NULL)
return (NULL);

for (i = 0; s[i] != '\0'; i++)
{
if ((s[i] >= 'a' && s[i] <= 'm') || (s[i] >= 'A' && s[i] <= 'M'))
encoded[i] = s[i] + 13;
else if ((s[i] >= 'n' && s[i] <= 'z') || (s[i] >= 'N' && s[i] <= 'Z'))
encoded[i] = s[i] - 13;
else
encoded[i] = s[i];
}
encoded[i] = '\0';

return (encoded);
}

/**
 * add_to_buffer - Adds a string to the buffer at the current position.
 * @buffer: The buffer to add the string to.
 * @i: A pointer to the current position in the buffer.
 * @s: The string to add to the buffer.
 * @len: The length of the string.
 */
void add_to_buffer(char *buffer, int *i, char *s, int len)
{
int j;

for (j = 0; j < len; j++)
{
buffer[*i] = s[j];
(*i)++;
}
}

/**
 * handle_rot13 - Handles the "R" custom conversion specifier.
 * @buffer: The buffer to print the formatted string to.
 * @i: A pointer to the current position in the buffer.
 * @list: The arguments to be printed.
 */
void handle_rot13(char *buffer, int *i, va_list list)
{
char *s = va_arg(list, char *);
char *encoded = rot13(s);

if (encoded == NULL)
{
printf("Error: malloc failed in handle_rot13\n");
exit(1);
}

add_to_buffer(buffer, i, encoded, strlen(encoded));

free(encoded);
}
