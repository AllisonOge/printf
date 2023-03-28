#include "main.h"

/**
 * print_char - prints a character
 * @args: list of arguments
 * @buffer: buffer array to handle print
 *
 * Return: number of chars printed except the null byte
 */
int print_char(va_list args, char buffer[])
{
	va_list args_copy;
	char c;

	UNUSED(buffer);
	va_copy(args_copy, args);
	c = va_arg(args_copy, int);

	return (_putchar(c));
}

/**
 * print_string - prints a string
 * @args: list of arguments
 * @buffer: buffer array to handle print
 *
 * Return: number of chars printed except the null byte
 */
int print_string(va_list args, char buffer[])
{
	va_list args_copy;
	int i, len = 0;
	char *s;

	UNUSED(buffer);
	va_copy(args_copy, args);
	s = va_arg(args_copy, char *);

	if (s == NULL)
		s = "(null)";

	/* find the length of string */
	while (s[len] != '\0')
		len++;

	for (i = 0; i < len; i++)
		_putchar(s[i]);

	return (len);
}

/**
 * print_percent - print percent character
 * @args: list of arguments
 * @buffer: buffer array to handle print
 *
 * Return: number of chars printed except null byte
 */
int print_percent(va_list args, char buffer[])
{
	UNUSED(args);
	UNUSED(buffer);
	return (_putchar('%'));
}
