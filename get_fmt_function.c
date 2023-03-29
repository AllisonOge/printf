#include "main.h"
#include <stddef.h>

/**
 * get_fmt_func - function pointer to handle print for supported formats
 * @fmt: format to be handled
 *
 * Return: pointer to format handler otherwise null
 */
int (*get_fmt_func(char fmt))(va_list, char[])
{
	fmt_t print_fmt[] = {
		{'c', print_char},
		{'s', print_string},
		{'i', print_int},
		{'d', print_int},
		{'u', print_unsigned},
		{'b', print_binary},
		{'o', print_octa},
		{'x', print_hexadecimal},
		{'X', print_Hexadecimal},
		{'p', print_pointer},
		{'%', print_percent},
		{'\0', NULL}
	};
	int i = 0;

	while (print_fmt[i].fn != NULL)
	{
		if (fmt == print_fmt[i].fmt)
			return (print_fmt[i].fn);
		i++;
	}

	return (NULL);
}
