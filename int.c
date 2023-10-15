#include "main.h"

/**
 * int_printer - prints the number in any base.
 *
 * @va: the variadic arg list
 * @len: the count of printed bytes
 *
 * Return: the always one.
*/
int int_printer(va_list va, int *len)
{
	long int n = va_arg(va, int);

	if (n < 0)
	{
		copy('-', len);
		n *= -1;
	}
	print_number((unsigned int)n, 10, len);

	return (1);
}

/**
 * print_number - prints the number in hex_capital.
 *
 * @n: the number to be changed.
 * @base: the base to be printed
 * @len: the length.
 *
 * Return: the amount of char copied.
*/
void print_number(unsigned long n, unsigned long base, int *len)
{
	char *symbols;

	symbols = "0123456789abcdef";

	if (n < base)
	{
		copy(arr, symbols[n], index, len);
	}
	else
	{
		print_number(n / base, base, len);
		copy(symbols[n % base], len);
	}
}
