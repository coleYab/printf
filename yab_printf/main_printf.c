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
	int i = -1, index = 0, len = 0;
	char arr[1024];

	va_start(ap, format);
	if (!format || (format[i + 1] == '%' && format[i + 2]))
		return (-1);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				break;
			get_function(format[i + 1], arr, &index, ap, &len);
			i += 1;
		}
		else
			copy(arr, format[i], &index, &len);
	}
	if (index)
		len += write_std(arr, &index);

	va_end(ap);
	return (len);
}

/**
 * get_function - gets the function to copy the chars.
 * @specifier: the format specifier that is passed to the function.
 * @buffer_storage: stores the buffer.
 * @index: the indes of the arr.
 * @va: the va_ list.
 * @len: the length that is printed.
 *
 * Return: the amount of chars added to buffer.
*/
int get_function(char specifier, char *buffer_storage,
				int *index, va_list va, int *len)
{
	int i = -1;
	Format formats_list[] = {
	{'c', char_printer}, {'d', int_printer}, {'i', int_printer},
	{'s', string_printer}, {'%', percent_printer}, {'\0', NULL}
	};

	while (formats_list[++i].specifiers)
	{
		if (formats_list[i].specifiers == specifier)
			return ((*formats_list[i].fun_ptr)(va, buffer_storage, index, len));
	}

	return (0);
}

