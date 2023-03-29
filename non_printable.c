#include "main.h"

/**
 * print_non_printable - prints ASCII code in hexa of non-printable chars
 * @args: list of arguments
 * @buffer: buffer array to handle print
 * 
 * Return: number of chars printed except the null byte
*/
int print_non_printable(va_list args, char buffer[])
{
	va_list args_copy;
	int len = 0, i = 0, count = 0;
	char map_to[] = "0123456789ABCDEF";
	char *s;

	va_copy(args_copy, args);
	s = va_arg(args_copy, char *);

	buffer[i] = '\0';
	/* get length of string */
	while (s[len] != '\0')
		len++;
	do {
		if (is_printable(s[len]))
			buffer[i++] = s[len];
		else
		{
			if (s[len] < 0) s[len] *= -1;
			buffer[i++] = map_to[s[len] % 16];
			buffer[i++] = map_to[(s[len] / 16) % 16];
			buffer[i++] = 'x';
			buffer[i++] = '\\';
		}
	} while (--len >= 0);

	while(i > 4)
		count += _putchar(buffer[--i]);

	return (count);
}

/**
 * is_printable - checks if a char is printable
 * @c: char to be checked
 * 
 * Return: 1 if c is printable otherwise 0
*/
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}