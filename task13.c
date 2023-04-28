#include "main.h"

/**
 * reverse_string - Reverses string
 * str: String to reverse
*/
char *reverse_string(const char *str)
{
    int length = strlen(str);
    int i;
    char *reversed_str = malloc(length + 1);
    if (reversed_str == NULL)
    {
        return (NULL);
    }
    for (i = 0; i < length; i++)
    {
        reversed_str[i] = str[length - i - 1];
    }
    reversed_str[length] = '\0';
    return (reversed_str);
}
