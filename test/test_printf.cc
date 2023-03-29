#include "gtest/gtest.h"
extern "C" {
    #include "main.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
}


// Test case that the test works
TEST(TestPrintf, TestWorks) {
    EXPECT_EQ(5, 5);
}

// Test case to assert the output with conversion specifiers c s and %
TEST(TestPrintf, TestCharStringPercent) {
    // redirect output to a file
    FILE* tmp = tmpfile();
    if (tmp == NULL)
        FAIL() << "Unable to create temporary file";
    
    fflush(stdout);
    int old_stdout = dup(fileno(stdout));
    dup2(fileno(tmp), fileno(stdout));

    // Call function that prints value
    _printf("Hello World!\n");

    // restore the orignal output stream
    fflush(stdout);
    dup2(old_stdout, fileno(stdout));
    rewind(tmp);

    // read the content of the file
    char buffer[BUFF_SIZE];
    memset(buffer, 0, sizeof(buffer));
    fread(buffer, sizeof(char), sizeof(buffer) - 1, tmp);
    fclose(tmp);

    // check the contents of the file
    EXPECT_STREQ("Hello World!\n", buffer);
}

