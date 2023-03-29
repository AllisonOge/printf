#include "main.h"

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
	unsigned int num;

	va_copy(args_copy, args);
	value = va_arg(args_copy, int);

	if (value < 0)
	{
		neg = 1;
		num = (unsigned int) ((-1) * value);
	} else
	{
		num = (unsigned int) value;
	}

	buffer[i] = '\0';
	do {
		buffer[i++] = (num % 10) + '0';
		num /= 10;
	} while (num > 0);

	if (neg)
		buffer[i++] = '-';

	while (i > 0)
		count += _putchar(buffer[--i]);

	return (count);
}

/**
 * print_binary - print in binary format
 * @args: list of arguments
 * @buffer: buffer arry to handle print
 *
 * Return: number of chars printed except the null byte
 */
int print_binary(va_list args, char buffer[])
{
	va_list args_copy;
	int i = 0, count = 0;
	unsigned int value;

	va_copy(args_copy, args);
	value = va_arg(args_copy, unsigned int);

	buffer[i] = '\0';
	do {
		buffer[i++] = (value % 2) + '0';
		value /= 2;
	} while (value > 0);

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

	buffer[i] = '\0';
	do {
		buffer[i++] = (value % 10) + '0';
		value /= 10;
	} while (value > 0);

	while (i > 0)
		count += _putchar(buffer[--i]);

	return (count);
}
