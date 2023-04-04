#include <gtest/gtest.h>
#include "test_printf.h"

/**
 * testPrintf - assert the output through the stdout and compare with built-in output
 * @printFunc: function that prints values
 * @format: format for the functions
 */
void testPrintf(int (*printFunc)(const char *, ...), const char *format, ...)
{
    // redirect output to a file
    FILE *tmp = tmpfile();
    if (tmp == NULL)
        FAIL() << "Unable to create temporary file";

    fflush(stdout);
    int old_stdout = dup(fileno(stdout));
    dup2(fileno(tmp), fileno(stdout));

    // get the expected value
    char expected[BUFF_SIZE];

    // Call function that prints value
    va_list args;
    va_start(args, format);
    sprintf(expected, format, args);
    printFunc(format, args);
    va_end(args);

    // restore the orignal output stream
    fflush(stdout);
    dup2(old_stdout, fileno(stdout));
    rewind(tmp);

    // read the content of the file
    char actual[BUFF_SIZE];
    memset(actual, 0, sizeof(actual));
    fread(actual, sizeof(char), sizeof(actual) - 1, tmp);
    fclose(tmp);

    // check the contents of the file
    ASSERT_STREQ(expected, actual);
}

/**
 * testPrintf2 - assert the output through the stdout and compare with expected string
 * @printFunc: function that prints values
 * @expected_str: expected string of the function
 * @format: format for the function
 */
void testPrintf2(int (*printFunc)(const char *, ...), const char *expected_str, const char *format, ...)
{
    // redirect output to a file
    FILE *tmp = tmpfile();
    if (tmp == NULL)
        FAIL() << "Unable to create temporary file";

    fflush(stdout);
    int old_stdout = dup(fileno(stdout));
    dup2(fileno(tmp), fileno(stdout));

    // Call function that prints value
    va_list args;
    va_start(args, format);
    printFunc(format, args);
    va_end(args);

    // restore the orignal output stream
    fflush(stdout);
    dup2(old_stdout, fileno(stdout));
    rewind(tmp);

    // read the content of the file
    char actual[BUFF_SIZE];
    memset(actual, 0, sizeof(actual));
    fread(actual, sizeof(char), sizeof(actual) - 1, tmp);
    fclose(tmp);

    // check the contents of the file
    ASSERT_STREQ(expected_str, actual);
}