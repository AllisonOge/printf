cmake_minimum_required(VERSION 3.0)

project(printf_project)

# set C flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic -Wno-format")

# set the C standard
set(CMAKE_C_STANDARD 90)

# add location of header files
include_directories(${PROJECT_SOURCE_DIR})

# add sub directories
add_subdirectory(${PROJECT_SOURCE_DIR}/test)

# add printf library
add_library(myprintf 
                _printf.c
                _putchar.c
                char_string_format_func.c
                get_fmt_function.c
                memory_addr_format_func.c
                number_format_func.c)

# add source files
add_executable(main main.c)

# link library to target
target_link_libraries(main myprintf)

# enable gtest globally in project
enable_testing()