#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

#define BUFF_SIZE 1024

/* HANDLE UNUSED ARGS */
#define UNUSED(x) (void)(x)

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
typedef struct fmt
{
	char fmt;
	int (*fn)(va_list, char[]);
} fmt_t;


int _printf(const char *format, ...);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int print_char(va_list args, char buffer[]);
int print_string(va_list args, char buffer[]);
int print_percent(va_list args, char buffer[]);

/* Functions to print numbers */
int print_int(va_list args, char buffer[]);
int print_unsigned(va_list args, char buffer[]);
int print_octa(va_list args, char buffer[]);
int print_hexadecimal(va_list args, char buffer[]);
int print_Hexadecimal(va_list args, char buffer[]);

/* Function to print non printable characters */
int print_non_printable(va_list args, char buffer[]);

/* Funcion to print memory address */
int print_pointer(va_list args, char buffer[]);

/*Function to print string in reverse*/
int print_reverse(va_list args, char buffer[]);

/*Function to print a string in rot 13*/
int print_rot13string(va_list args, char buffer[]);

/*******************FUNCTION HANDLER********/
int (*get_fmt_func(char fmt))(va_list, char[]);

/****************** UTILS ******************/
extern int _putchar(char c);
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

#endif /* MAIN_H */

