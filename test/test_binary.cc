#include <gtest/gtest.h>
#include"test_printf.h"

/***** Test case to assert the output with conversion specifiers b ***/

// Test case to assert function prints with conversion specifier b
TEST(TestPrintf, TestBinary)
{
    const char *format = "%b";
    testPrintf(&_printf, format, 1024);

    testPrintf(&_printf, format, -1024);

    testPrintf(&_printf, format, 0);

    testPrintf(&_printf, format, UINT_MAX);

    testPrintf(&_printf, format, UINT_MAX + 1024);

    const char *format1 = "There is %b bytes in %b KB\n";
    testPrintf(&_printf, format1, 1024, 1);

    const char *format2 = "%b - %b = %b\n";
    testPrintf(&_printf, format2, 2048, 1024, 1024);

    const char *format3 = "%b + %b = %b\n";
    testPrintf(&_printf, format3, INT_MAX, INT_MAX, (INT_MAX * 2));
}