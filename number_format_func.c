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

	buffer[i] = '\0';
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
	int i = 0, count = 0;
	va_list args_copy;
	unsigned int value;

	va_copy(args_copy, args);
	value = va_arg(args_copy, unsigned int);

	buffer[i] = '\0';
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

	buffer[i] = '\0';
	do {
		buffer[i++] = (value & 15) +
			(((value & 15) < 10) ? '0' : 'a' - 10);
		value >>= 4;
	} while (value > 0);

	while (i > 0)
		count += _putchar(buffer[--i]);

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

	buffer[i] = '\0';
	do {
		buffer[i++] = (value & 15) +
			(((value & 15) < 10) ? '0' : 'A' - 10);
		value >>= 4;
	} while (value > 0);

	while (i > 0)
		count += _putchar(buffer[--i]);

	return (count);
}
