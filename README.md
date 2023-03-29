# printf project

Project task is to write a function that produces output according to a format.

- prototype: `int _print(const char *format, ...);`
- Returns: the number of characters printed (excluding the null byte used to end output to strings)
- write output to stdout, the standard output stream
- `format` is a character string. The format string is composed of zero or more directives. You need to handle the following conversion specifiers: `c`, `s`, `%`, `d`, `o`, `x`, `X`, `S`, `R`, `r`, `u`, `p` and `i`.

For the mandatory tasks,

- You don't have to reproduce the buffer handling of the C library `printf` function 
- You don't have to handle the flag characters
- You don't have to handle field width
- You don't have to handle precision
- You don't have to handle the length modifiers

For the advanced tasks,

- The buffer handling to limit the call of `write` function should be implemented
- The flag characters in the format should be handled
- The field width and length modifiers should be handled and 
- The precision specifiers should be handled