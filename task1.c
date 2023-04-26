#include "main.h"
#include <stdarg.h>


/**
 * print_integer - Prints an integer to the console
 *
 * @num: The integer to print
 */
void print_integer(int num)
{
printf("%d", num);
}

int main(void)
{
int num = 42;
print_integer(num); /* Will output "42" */
return (0);
}
