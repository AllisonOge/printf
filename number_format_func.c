#include "main.h"



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
