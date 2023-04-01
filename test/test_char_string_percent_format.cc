#include <gtest/gtest.h>
#include "test_printf.h"


/***** Test case to assert the output with conversion specifiers c s and % ***/

// Test edge cases
TEST(TestPrintf, TestEdges)
{
    const char *format = NULL;
    testPrintf(&_printf, format);
}

// Test case to assert function prints with conversion specifier c
TEST(TestPrintf, TestChar)
{
    const char *format = "%c\n";
    testPrintf(&_printf, format, 'S');

    const char *format1 = "A char inside a sentence: %c. Did it work?\n";
    testPrintf(&_printf, format1, 'F');

    const char *format2 = "Let's see if the cast is correctly done: %c. Did it work?\n";
    testPrintf(&_printf, format2, 48);

    const char *format3 = "%c";
    testPrintf(&_printf, format3, '\0');
}

// Test case to assert function prints with conversion specifier s
TEST(TestPrintf, TestString)
{
    const char *format = "Let's print a simple sentence.\n";
    testPrintf(&_printf, format);

    const char *format1 = "%s";
    testPrintf(&_printf, format1, "This sentence is retrieved from va_args!\n");

    const char *format2 = "Complete the sentence: You %s nothing, Jon Snow.\n";
    testPrintf(&_printf, format2, "know");

    const char *format3 = "Complete the sentence: You %s nothing, Jon Snow.\n";
    testPrintf(&_printf, format3, (char *)0);

    char bigStr[STRING_SIZE + 1];
    strcpy(bigStr, "This is a big string");
    for (int i = 0; i < 1000; i++)
        strcpy(bigStr, " that keeps getting bigger");

    const char *format4 = bigStr;
    testPrintf(&_printf, format4);

    const char *format5 = "man gcc:\n%s";
    testPrintf(&_printf, format5, bigStr);
}

// Test case to assert function prints with conversion specifier %
TEST(TestPrintf, TestPercent)
{
    const char *format = "%";
    testPrintf(&_printf, format);

    const char *format1 = "%%";
    testPrintf(&_printf, format1);

    const char *format2 = "Should print a single percent sign: %%\n";
    testPrintf(&_printf, format2);

    const char *format3 = "%!\n";
    testPrintf(&_printf, format3);

    const char *format4 = "%K\n";
    testPrintf(&_printf, format4);
}

// Test case to assert function prints with combined specifiers
TEST(TestPrintf, TestCombined)
{
    const char *format = "%c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c";
    testPrintf(&_printf, format, 'W', 'i', "some ", "more", 'r', "s", "", "know", 't', ", Jon", '\n');

    const char *format1 = "%s%c%c%c%s%%%s%c";
    testPrintf(&_printf, format1, "Loading ", '.', '.', '.', " 99", " Please wait", '\n');

    const char *format2 = "css%ccs%scscscs";
    testPrintf(&_printf, format2, 'T', "Test");
}