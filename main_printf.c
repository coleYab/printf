#include "main.h"

/**
 * _printf - a function that is used to format a string and print it
 *
 * @format: the format specifier argumert.
 *
 * Return: the amount of chars printed.
*/
int _printf(const char *format, ...)
{
	va_list ap;
	int i = -1, len = 0;

	va_start(ap, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (i);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				break;
			i += get_function(format[i + 1], ap, &len);
		}
		else
		{
			copy(format[i], &len);
		}
	}
	va_end(ap);
	return (len);
}

/**
 * get_function - gets the function to copy the chars.
 * @specifier: the format specifier that is passed to the function
 * @va: the va_ list.
 * @len: the length that is printed.
 *
 * Return: the amount of chars added to buffer.
*/
int get_function(char specifier, va_list va, int *len)
{
	int i = -1;
	Formats formats_list[] = {
		{ 'c', char_printer}, { 'd', int_printer}, { 'i', int_printer},
		{ 's', string_printer}, { '%', percent_printer}, {'\0', NULL}
		};

	while (formats_list[++i].specifiers)
	{
		if (formats_list[i].specifiers == specifier)
			return ((*formats_list[i].fun_ptr)(va, len));
	}

	return (-1);
}
