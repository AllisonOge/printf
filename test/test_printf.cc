#include <gtest/gtest.h>
#include "test_printf.h"

/**
 * testPrintf - assert the output through the stdout
 * @printFunc: function that prints values
 */
void testPrintf(int (*printFunc)(const char *, ...), const char *str, ...)
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
    va_start(args, str);
    sprintf(expected, str, args);
    printFunc(str, args);
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
