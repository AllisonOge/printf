#ifndef TEST_PRINTF_H
#define TEST_PRINTF_H

extern "C" {
#define STRING_SIZE 10000
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "main.h"
}

void testPrintf(int (*printFunc)(const char *, ...), const char *format, ...);
void testPrintf2(int (*printFunc)(const char *, ...), const char *expected_str, const char *format, ...);

#endif /* TEST_PRINTF_H */