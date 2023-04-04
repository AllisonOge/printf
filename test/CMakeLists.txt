# add gtest source folder (provide gtests and gtest_main)
add_subdirectory(/usr/src/gtest
                ${PROJECT_BINARY_DIR}/gtest)

# include testing cmake package
include(CTest)

# add executable that runs the enable_testing
add_executable(test_char_string_percent_format test_printf.cc 
    test_char_string_percent_format.cc
)

add_executable(test_decimal_interger_format test_printf.cc 
    test_number_format.cc
)

add_executable(test_binary test_printf.cc 
    test_binary.cc
)

add_executable(test_buffer test_printf.cc 
    test_buffer.cc
)

add_executable(test_unsigned_octal_hex
    test_printf.cc 
    test_unsigned_octal_hex.cc
)

# link the executable to gtest library
target_link_libraries(test_char_string_percent_format
    myprintf
    gtest gtest_main
)

target_link_libraries(test_decimal_interger_format
    myprintf
    gtest gtest_main
)

target_link_libraries(test_binary
    myprintf
    gtest gtest_main
)

target_link_libraries(test_buffer
    myprintf
    gtest gtest_main
)

target_link_libraries(test_unsigned_octal_hex
    myprintf
    gtest gtest_main
)

# add gtest to be able to run test
add_test(NAME test_char_string_percent_format 
         COMMAND test_char_string_percent_format
         WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/test
)

add_test(NAME test_decimal_interger_format 
         COMMAND test_decimal_interger_format
         WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/test
)

add_test(NAME test_binary 
         COMMAND test_binary
         WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/test
)

add_test(NAME test_buffer 
         COMMAND test_buffer
         WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/test
)

add_test(NAME test_unsigned_octal_hex 
         COMMAND test_unsigned_octal_hex
         WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/test
)