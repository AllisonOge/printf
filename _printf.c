#include <stdarg.h>
#include "main.h"


/**
 * _printf - produces output according to a format and
 * returns the number of characters printed excluding the null byte
 * @format: character string with formate string composed of zero or more directives
 * @...: args based on format specifiers
 *
 * Return: number of characters printed excluding the null byte used to end strings
 */
int _printf(const char *format, ...)
{
	va_list args;
	/* start the arg list */
	va_start(args, format);
	const char *p = format;
	int count = 0;

	while (*p != '\0')
	{
		/* if the character is not a format specifier, print it */
		if (*p != '%')
		{
			_putchar(*p);
			p++;
			count++;
			continue;
		}

		/* parse the format specifier */
		p++;

		/* check for flag characters */
		...

		/* parse the width specifier */
		...

		/* parse the precision specifier */
		...

		/* parse the conversion specifier */
		...

		p++;
	}

	/* clean up */
	va_end(args);
	return (count);
}
