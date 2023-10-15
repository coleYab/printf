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
	int (*fun_ptr)(va_list, char *, int *, int *);
} Formats;

int _printf(const char *format, ...);
int char_printer(va_list va, char *, int *, int *);
int int_printer(va_list va, char *, int *, int *);
int string_printer(va_list va, char *, int *, int *);
int percent_printer(va_list va __attribute__((unused)), char *, int *, int *);
int get_function(char, char *, int *, va_list va, int *);
int write_std(char *, int *);
void copy(char *, char c, int *, int *);
int check_1024(char *, int *);
void print_number(char *, unsigned long n, unsigned long, int *, int *);

#endif
