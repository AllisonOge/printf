#include <gtest/gtest.h>
#include "test_printf.h"

/***** Test case to assert the output with conversion specifiers d and i ***/

// Test case to assert function prints with conversion specifier d
TEST(TestPrintf, TestDecimal) {
    const char *format = "%d";
    testPrintf(&_printf, format, 1024);

    testPrintf(&_printf, format, -1024);

    testPrintf(&_printf, format, 10000);

    testPrintf(&_printf, format, 0);

    testPrintf(&_printf, format, INT_MAX);

    testPrintf(&_printf, format, INT_MIN);

    testPrintf(&_printf, format, (INT_MAX + 1024));

    testPrintf(&_printf, format, (INT_MIN - 1024));

    const char *format1 = "There is %d bytes in %d KB\n";
    testPrintf(&_printf, format1, 1024, 1);

    const char *format2 = "%d - %d = %d\n";
    testPrintf(&_printf, format2, 1024, 2048, -1024);

    const char *format3 = "%d + %d = %d\n";
    testPrintf(&_printf, format3, INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
}

// Test case to assert function prints with conversion specifier i
TEST(TestPrintf, TestInteger)
{
    const char *format = "%i";
    testPrintf(&_printf, format, 1024);

    testPrintf(&_printf, format, -1024);
    
    testPrintf(&_printf, format, 10000);

    testPrintf(&_printf, format, 0);

    testPrintf(&_printf, format, INT_MAX);

    testPrintf(&_printf, format, INT_MIN);

    testPrintf(&_printf, format, (INT_MAX + 1024));

    testPrintf(&_printf, format, (INT_MIN - 1024));

    const char *format1 = "There is %i bytes in %i KB\n";
    testPrintf(&_printf, format1, 1024, 1);

    const char *format2 = "%i - %i = %i\n";
    testPrintf(&_printf, format2, 1024, 2048, -1024);

    const char *format3 = "%i + %i = %i\n";
    testPrintf(&_printf, format3, INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
}

// Test cases for combined conversion specifiers d and i
TEST(TestPrintf, TestCombined)
{
    const char *format = "%d == %i\n";
    testPrintf(&_printf, format, 1024, 1024);

    const char *format2 = "iddi%diddiiddi\n";
    testPrintf(&_printf, format2, 1024);
}