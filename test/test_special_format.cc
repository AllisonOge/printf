#include <gtest/gtest.h>
#include "test_printf.h"


/***** Test case to assert the output with conversion specifiers S ***/

// Test case to assert function _printf prints with conversion specifier S
TEST(TestPrintf, TestSpecial)
{
    testPrintf2(&_printf, "Best\x0ASchool\n", "%S\n", "Best\nSchool");
}