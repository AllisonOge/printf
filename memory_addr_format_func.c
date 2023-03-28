#include <stdint.h>
#include "main.h"

/**
 * print_pointer - print the value of a pointer variable
 * @args: list of arguments
 * @buffer: buffer array to handle print
 *
 * Return: number of chars printed except the null byte
 */
int print_pointer(va_list args, char buffer[])
{
        va_list args_copy;
        int i = 0, count = 0, digit;
        uintptr_t value;

        va_copy(args_copy, args);
        value = va_arg(args_copy, uintptr_t);

        do {
                digit = value % 16;
                buffer[i++] = (digit < 10) ?
                        (digit + '0') : (digit - 10 + 'a');
                value /= 16;
        } while (value > 0);

        _putchar('0');
        _putchar('x');

        while (i > 0)
                count += _putchar(buffer[i--]);

	return (count);
}
