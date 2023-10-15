#ifndef PRINTF_H
#define PRINTF_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>

/**
 * struct Format_specifier - stores the format specifier for the printf funct
 *
 * @specifiers: characters that will be used as format specifier
 * @fun_ptr: a pointer to specific function that will perform the task
 */
typedef struct Format_specifier
{
	char specifiers;
	int (*fun_ptr)(va_list, int *);
} Formats;

int _printf(const char *format, ...);
int char_printer(va_list va, int *);
int int_printer(va_list va, int *);
int string_printer(va_list va, int *);
int percent_printer(va_list va __attribute__((unused)), int *);
int get_function(char, va_list va, int *);
void copy(char c, int *);
void print_number(unsigned long n, unsigned long, int *);

#endif
