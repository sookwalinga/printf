#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

int _printf(const char *format, ...);
void print_integer(int num);
void print_binary(unsigned int n);
int _printS(const char *format, ...);

#endif /* MAIN_H */
