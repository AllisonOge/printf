#include <gtest/gtest.h>
#include "test_printf.h"

/***** Test case to assert the output with conversion specifiers u o x and X ***/

// Test case to assert function prints with conversion specifier u
TEST(TestPrinf, TestUnsigned)
{
    testPrintf(&_printf, "%u", 1024);

    testPrintf(&_printf, "%u", -1024);

    testPrintf(&_printf, "%u", 0);

    testPrintf(&_printf, "%u", UINT_MAX);

    testPrintf(&_printf, "%u", (UINT_MAX + 1024));

    testPrintf(&_printf, "There is %u bytes in %u KB\n", 1024, 1);

    testPrintf(&_printf, "%u - %u = %u\n", 2048, 1024, 1024);

    testPrintf(&_printf, "%u + %u = %u\n", INT_MAX, INT_MAX, (INT_MAX * 2));
}

// Test case to assert function _printf prints with conversion specifier o
TEST(TestPrintf, TestOctal)
{
    testPrintf(&_printf, "%o", 1024);

    testPrintf(&_printf, "%o", -1024);

    testPrintf(&_printf, "%o", 0);

    testPrintf(&_printf, "%o", UINT_MAX);

    testPrintf(&_printf, "%o", (UINT_MAX + 1024));

    testPrintf(&_printf, "There is %o bytes in %o KB\n", 1024, 1);

    testPrintf(&_printf, "%o - %o = %o\n", 2048, 1024, 1024);

    testPrintf(&_printf, "%o + %o = %o\n", INT_MAX, INT_MAX, (INT_MAX * 2));
}

// Test case to assert function _printf prints with conversion specifier x
TEST(TestPrintf, TestHexadecimalLower)
{
    testPrintf(&_printf, "%x", 1024);

    testPrintf(&_printf, "%x", -1024);

    testPrintf(&_printf, "%x", 0);

    testPrintf(&_printf, "%x", UINT_MAX);

    testPrintf(&_printf, "%x", (UINT_MAX + 1024));

    testPrintf(&_printf, "There is %x bytes in %x KB\n", 1024, 1);

    testPrintf(&_printf, "%x - %x = %x\n", 2048, 1024, 1024);

    testPrintf(&_printf, "%x + %x = %x\n", INT_MAX, INT_MAX, (INT_MAX * 2));
}

// Test case to assert function _printf prints with conversion specifier X
TEST(TestPrintf, TestHexadecimalUpper)
{
    testPrintf(&_printf, "%X", 1024);

    testPrintf(&_printf, "%X", -1024);

    testPrintf(&_printf, "%X", 0);

    testPrintf(&_printf, "%X", UINT_MAX);

    testPrintf(&_printf, "%X", (UINT_MAX + 1024));

    testPrintf(&_printf, "There is %X bytes in %X KB\n", 1024, 1);

    testPrintf(&_printf, "%X - %X = %X\n", 2048, 1024, 1024);

    testPrintf(&_printf, "%X + %X = %X\n", INT_MAX, INT_MAX, (INT_MAX * 2));
}

// Test case to assert function _printf prints with combined specifiers
TEST(TestPrintf, TestCombined)
{
    testPrintf(&_printf, "%u == %o == %x == %X\n", 1024, 1024, 1024, 1024);

    testPrintf(&_printf, "uuoxxX%xuoXo\n", 1024);
}