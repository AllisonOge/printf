# add gtest source folder (provide gtests and gtest_main)
add_subdirectory(/usr/src/gtest
                ${PROJECT_BINARY_DIR}/gtest)

# include testing cmake package
include(CTest)

# add executable that runs the enable_testing
add_executable(test_printf test_printf.cc)

# link the executable to gtest library
target_link_libraries(test_printf
                        myprintf
                        gtest gtest_main)

# add gtest to be able to run test
add_test(NAME test_printf 
         COMMAND test_printf
         WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/test)