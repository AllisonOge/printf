#include <gtest/gtest.h>
#include "test_printf.h"

/***** Test case to assert the function uses buffer ***/

TEST(TestPrintf, TestBuffer)
{
    char str1020[1020 + 1];
    strcpy(str1020, "This is a string of 1020 characters that keeps going");
    for (int i = 0; i < 100; i++)
        strcpy(str1020, " and going");

    testPrintf(&_printf, str1020);

    char str1023[1023 + 1];
    strcpy(str1023, "This is a string of 1023 characters that keeps going");
    for (int i = 0; i < 100; i++)
        strcpy(str1023, " and going");

    testPrintf(&_printf, str1023);

    char str1023_2[1023 + 1];
    strcpy(str1023_2, "This is a string of 1023 characters with %d that keeps going");
    for (int i = 0; i < 100; i++)
        strcpy(str1023_2, " and going");
    testPrintf(&_printf, str1023_2, 123456789);

    char str727[727 + 1];
    char str147[147 + 1];
    char str97[97 + 1];
    strcpy(str727, "This is a string of 727 characters that keeps going");
    strcpy(str147, "This is a string of 147 characters that keeps going");
    strcpy(str97, "This is a string of 97 characters that keeps going");
    for (int i = 0; i < 100; i++)
        strcpy(str727, " and going");
    for (int i = 0; i < 10; i++)
    {
        strcpy(str147, " and going");
        strcpy(str97, " and going");
    }
    testPrintf(&_printf, str727, "you", "normally does preprocessing, compilation, assembly", '"', '"', "For example,", str147, 'o', str97, 8);

    testPrintf(&_printf, str727, "you", "normally does preprocessing, compilation, assembly", '"', '"', "For example,", str147, 'o', str97, 123456789);

    char str1020_2[1020 + 1];
    strcpy(str1020_2, "AAAAAAAAAAAAAAAAAAA");
    for (int i = 0; i < 1000; i++)
        strcpy(str1020_2, "A");
    strcpy(str1020_2, "\0");
    testPrintf(&_printf, "%s%b\n", str1020);
}