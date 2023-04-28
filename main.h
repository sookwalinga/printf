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

void print_binary(unsigned int num);

void prints_specifier(char c, unsigned int num);

void print_specifier(char c, unsigned int num);

int _printS(const char *format, ...);

int write_buffered(char *str);

void print_hex(unsigned char num);

int _printHex(const char *format, ...);

int print_pointer(void *ptr);

int handle_flags(const char *format, int *i);

void print_number(char format, char length_modifier, long number);

int handle_precision(const char *format, int *start_i, va_list args);

int handle_zero_flag(const char *format, int *i, va_list list, char specifier);

char *format_with_zero_flag(const char *format, int value);

int handle_reversed_string(va_list args);

int handle_width(const char *format, int *i, va_list list);

#endif
