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

int write_buffered(char *str);

<<<<<<< HEAD
void print_hex(unsigned char num);
=======
// For task No. 5.
>>>>>>> 1ce9f989994a083ecf361461d809d086e608dcb2
int _printHex(const char *format, ...);

#endif /* MAIN_H */
