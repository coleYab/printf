#include "main.h"

/**
 * int_printer - prints the number in any base.
 *
 * @va: the variadic arg list.
 * @buffer_storge: the buffer to store chars.
 * @index: the current index position.
 * @len: the count of printed bytes
 *
 * Return: the always one.
*/
int int_printer(va_list va, char *buffer_storge, int *index, int *len)
{
	long int n = va_arg(va, int);

	if (n < 0)
	{
		copy(buffer_storge, '-', index, len);
		n *= -1;
	}
	print_number(buffer_storge, (unsigned int)n, 10, index, len);

	return (0);
}

/**
 * print_number - prints the number in hex_capital.
 *
 * @arr: the pointer to a string.
 * @n: the number to be changed.
 * @base: the base to be printed.
 * @index: the current index position.
 * @len: the length.
 *
 * Return: the amount of char copied.
*/
void print_number(char *arr, unsigned long n, int base, int *index, int *len)
{
	char *symbols, *symbols2;

	symbols = "0123456789abcdef";

	if (n < base)
	{
		copy(arr, symbols[n], index, len);
	}
	else
	{
		print_number(arr, n / base, base, index, len);
		copy(arr, symbols[n % base], index, len);
	}
}
