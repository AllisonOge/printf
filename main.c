#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * test_char_string - test edge cases with format specifiers c, s, %
*/
void test_char_string(void)
{
	int len;
	int len2;

	len = _printf("Character:[%c]\n", 'H');
	len2 = printf("Character:[%c]\n", 'H');
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	len = _printf("String:[%s]\n", NULL);
	len2 = printf("String:[%s]\n", NULL);
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	len = _printf("String:[%s]\n", "I am a string !");
	len2 = printf("String:[%s]\n", "I am a string !");
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
}

/**
 * test_decimal - test edge cases with format specifiers i, d
*/
void test_decimal(void)
{
	int len;
	int len2;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	len = _printf("Negative:[%d]\n", -762534);
	len2 = printf("Negative:[%d]\n", -762534);
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	len = _printf("Negative:[%d]\n", INT_MIN);
	len2 = printf("Negative:[%d]\n", INT_MIN);
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
}

/**
 * test_unsigned - test edge cases with format specifiers u, o, x, X
*/
void test_unsigned(void)
{
	int len;
	int len2;
	unsigned int ui;

	ui = (unsigned int)INT_MAX + 1024;
	len = _printf("Unsigned:[%u]\n", ui);
	len2 = printf("Unsigned:[%u]\n", ui);
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	_printf("Binary:[%b]\n", 98);
	len = _printf("Unsigned octal:[%o]\n", ui);
	len2 = printf("Unsigned octal:[%o]\n", ui);
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	len = _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	len2 = printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
}

/**
 * test_pointer - test edge cases with format specifier p
*/
void test_pointer(void)
{
	int len;
	int len2;
	void *addr;

	addr = (void *)0x7ffe637541f0;
	len = _printf("Address:[%p]\n", addr);
	len2 = printf("Address:[%p]\n", addr);
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	test_decimal();

	test_unsigned();

	test_char_string();

	test_pointer();

	_printf("Unknown:[%r]\n");
	printf("Unknown:[%r]\n");
	return (0);
}
