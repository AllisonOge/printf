#include <stdarg.h>
#include <stdint.h>
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

	/* find the length of string */
	while (s[len] != '\0')
		len++;

	for (i = 0; i < len; i++)
		_putchar(s[i]);

	return (len);
}

/**
 * print_int - print in decimal format
 * @args: list of arguments
 * @buffer: buffer array to handle print
 *
 * Return: number of chars printed except the null byte
 */
int print_int(va_list args, char buffer[])
{
	int i = 0, neg = 0, count = 0;
	va_list args_copy;
	int value;

	va_copy(args_copy, args);
	value = va_arg(args_copy, int);

	if (value < 0)
	{
		neg = 1;
		value = -value;
	}

	do {
		buffer[i++] = (value % 10) + '0';
		value /= 10;
	} while (value > 0);

	if (neg)
		buffer[i++] = '-';

	while (i > 0)
		count += _putchar(buffer[--i]);

	return (count);
}

/**
 * print_unsigned - print in unsigned decimal format
 * @args: list of arguments
 * @buffer: buffer arry to handle print
 *
 * Return: number of chars printed except the null byte
 */
int print_unsigned(va_list args, char buffer[])
{
	va_list args_copy;
	int i = 0, count = 0;
	unsigned int value;

	va_copy(args_copy, args);
	value = va_arg(args_copy, unsigned int);

	do {
		buffer[i++] = (value % 10) + '0';
		value /= 10;
	} while (value > 0);

	while (i > 0)
		count += _putchar(buffer[--i]);

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
	int i, count = 0;
	va_list args_copy;
	unsigned int value;

	va_copy(args_copy, args);
	value = va_arg(args_copy, unsigned int);
	do {
		buffer[i++] = (value & 7) + '0';
		value >>= 3;
	} while (value > 0);

	while (i > 0)
		count += _putchar(buffer[--i]);
	return (count);
}

/**
 * print_hexadecimal - print in lowercase hexadecimal format
 * @args: list of arguments
 * @buffer: buffer array to handle print
 *
 * Return: number of chars printed except the null byte
 */
int print_hexadecimal(va_list args, char buffer[])
{
	va_list args_copy;
	int i = 0, count = 0;
	unsigned int value;

	va_copy(args_copy, args);
	value = va_arg(args_copy, unsigned int);

	do {
		buffer[i++] = (value & 15) +
			(((value & 15) < 10) ? '0' : 'a' - 10);
		value >>= 4;
	} while (value > 0);

	while (i > 0)
		count += _putchar(buffer[i--]);

	return (count);
}

/**
 * print_Hexadecimal - print in uppercase hexadecimal format
 * @args: list of arguments
 * @buffer: buffer array to handle print
 *
 * Return: number of chars printed except the null byte
 */
int print_Hexadecimal(va_list args, char buffer[])
{
	va_list args_copy;
	int count = 0, i = 0;
	unsigned int value;

	va_copy(args_copy, args);
	value = va_arg(args_copy, unsigned int);

	do {
		buffer[i++] = (value & 15) +
			(((value & 15) < 10) ? '0' : 'A' - 10);
		value >>= 4;
	} while (value > 0);

	while (i > 0)
		count += _putchar(buffer[i--]);

	return (count);
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
