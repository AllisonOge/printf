#include <stdarg.h>
#include "main.h"

/**
 * print_char - prints a character
 * @args: list of arguments
 * @buffer: buffer array to handle print
 *
 * Return: always 1
 */
int print_char(va_list args, char buffer[])
{
	va_list args_copy;
	va_copy(args_copy, args);
	char c = va_arg(args_copy, int);

	_putchar(c);
	return (1);
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

	va_copy(args_copy, args);
	/* find the length of string */
	while (s[len] != '\0')
		len++;

	for (i = 0; i < len; i++)
		_putchar(s[i]);

	return (len);
}

/**
 * print_hex - print in hexadecimal format
 * @args: list of arguments
 * @buffer: buffer array to handle print
 *
 * Return: number of chars printed except the null byte
 */
int print_hex(va_list args, char buffer[])
{
	int i = 0, count = 0;
	va_list args_copy;
	unsigned int value;

	va_copy(args_copy, args);
	value = va_arg(args_copy, unsigned int);

	do {
		buffer[i++] = (vlaue % 10) + '0';
		value /= 10;
	} while (value > 0);

	while (i > 0)
	{
		_putchar(buffer[--i]);
		count++;
	}

	return (count);
}

/**
 * print_octa - print in octadecimal format
 * @args: list of arguments
 * @buffer: buffer array to handle print
 *
 * Return: number of chars printed except the null byte
 */
int print_octa(va_list args, char buffer[])
{
	int count = 0;

	return (count);
}
