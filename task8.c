#include "main.h"
#include <stdio.h>

/**
 * print_number - prints a number with the given format and length modifier
 * @format: the format specifier (d, i, u, o, x, or X)
 * @length_modifier: the length modifier (l or h)
 * @number: the number to print
 */
void print_number(char format, char length_modifier, long number)
{
  if (length_modifier == 'h') {
    switch (format) {
      case 'd':
      case 'i':
        printf("%hd", (short)number);
        break;
      case 'u':
        printf("%hu", (unsigned short)number);
        break;
      case 'o':
        printf("%ho", (unsigned short)number);
        break;
      case 'x':
        printf("%hx", (unsigned short)number);
        break;
      case 'X':
        printf("%hX", (unsigned short)number);
        break;
      default:
        printf("Invalid format specifier");
    }
  } else if (length_modifier == 'l') {
    switch (format) {
      case 'd':
      case 'i':
        printf("%ld", number);
        break;
      case 'u':
        printf("%lu", (unsigned long)number);
        break;
      case 'o':
        printf("%lo", (unsigned long)number);
        break;
      case 'x':
        printf("%lx", (unsigned long)number);
        break;
      case 'X':
        printf("%lX", (unsigned long)number);
        break;
      default:
        printf("Invalid format specifier");
    }
  } else {
    printf("Invalid length modifier");
  }
}
