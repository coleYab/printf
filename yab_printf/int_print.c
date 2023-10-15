#include "main.h"

/**
 * int_printer - prints the number in any base.
 *
 * @va: the variadic arg list.
 * @buffer_storge: the buffer to store chars.
 * @index: the current index position.
 * @len: the count of printed bytes
 *
 * Return: the amount of char copied.
*/
int int_printer(va_list va, char *buffer_storge, int *index, int *len)
{
	int old_index = *index;

	print_number(buffer_storge, (long)va_arg(va, int), 10, index, len);
	if (old_index > *index)
		return (old_index + 1024 - *index);
	return (old_index - *index);
}

/**
 * print_number - prints the number in any base.
 *
 * @arr: the pointer to a string.
 * @n: the number to be changed.
 * @base: the base to be printed.
 * @index: the current index position.
 *@len: the count of printed bytes
 *
 * Return: void.
*/
void print_number(char *arr, long n, int base, int *index, int *len)
{
	char *symbols;

	symbols = "0123456789abcdef";
	if (n < 0)
	{
		copy(arr, '-', index, len);
		n = -n;
	}
	if (n < base)
		copy(arr, symbols[n], index, len);
	else
	{
	print_number(arr, n / base, base, index, len);
		copy(arr, symbols[n % base], index, len);
	}
}

