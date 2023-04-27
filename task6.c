#include "main.h"
#include <stdarg.h>
/**
 * print_pointer - prints a pointer address in hexadecimal format
 * @ptr: the pointer to print
 *
 * Return: the number of characters printed
 */
int print_pointer(void *ptr)
{
unsigned long int address = (unsigned long int)ptr;
int count = 0;

count += printf("0x%lx", address);

return (count);
}
