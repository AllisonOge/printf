#include "main.h"
#include <stddef.h>

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
	int count = 0;
	char buffer[BUFF_SIZE];
	int (*fmt_func)(va_list, char[]);
	const char *p = format;

	if (p == NULL)
		return (-1);

	/* get arg list */
	va_start(args, format);
	while (*p != '\0')
	{
		/* if the character is not a format specifier, print it */
		if (*p != '%')
		{
			count += _putchar(*p);
			p++;
			continue;
		}

		/* parse the format specifier */
		p++;

		/* check for flag characters */

		/* parse the width specifier */

		/* parse the precision specifier */

		/* parse the conversion specifier */
		fmt_func = get_fmt_func(*p);

		if (fmt_func == NULL)
		{
			/* unsupported format */
			count += _putchar('%');
			continue;
		}

		count += fmt_func(args, buffer);
		p++;
	}

	/* clean up */
	va_end(args);
	return (count);
}
