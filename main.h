#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>
#include <ctype.h>

int _printf(const char *format, ...);
void intConversion(int list_num, char *list_buff);
int char_func(va_list list_words);
int string_func(va_list list_words);
int integer_func(va_list list_words);
void format_spec_cases(const char **format, va_list list_words, int *tally_character);

#endif
