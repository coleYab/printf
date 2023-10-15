#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>

/**
 * struct Format_specifier - struct for the enitre printf
 * @specifiers: the variable format specifiers
 * @fun_ptr: function pointer.
 *
 */
typedef struct Format_specifier
{
	char specifiers;
	int (*fun_ptr)(va_list, char *, int *, int *);
} Format;

int _printf(const char *format, ...);
int char_printer(va_list, char *, int *, int *);
int int_printer(va_list, char *, int *index, int *len);
int string_printer(va_list, char *buffer_storge, int *index, int *len);
int percent_printer(va_list va __attribute__((unused)), char *, int *, int *);
int get_function(char, char *, int *, va_list, int *);
int write_std(char *str, int *index);
void copy(char *arr, char c, int *index, int *len);
int check_1024(char *arr, int *index);
void print_number(char *, unsigned long n, int, int *, int *);

#endif

