#include "main.h"

/**
 * percent_printer - prints the % sign in.
 *
 * @va: the va_list macro
 * @len: is the length printed.
 *
 * Return: one.
*/
int percent_printer(va_list va __attribute__ ((unused)), int *len)
{
	copy('%', len);
	return (1);
}

/**
 * string_printer - copies a string to the buffer.
 *
 * @va: is the varidic argument list
 * @len: the length of the chars.
 *
 * Return: the amount of char copied.
*/
int string_printer(va_list va, char *buffer_storge, int *index, int *len)
{
	char *str = NULL;
	char arr[] = "(null)";
	int i = -1;

	str = va_arg(va, char *);
	if (str == NULL)
		str = arr;
	while (str[++i])
	{
		copy(str[i], len);
	}

	return (1);
}


/**
 * char_printer - copies a string to the buffer.
 *
 * @va: is the varidic argument list
 * @len: the length printed
 *
 * Return: the amount of char copied.
*/
int char_printer(va_list va, int *len)
{
	int c = va_arg(va, int);

	copy((char)c, len);

	return (1);
}
