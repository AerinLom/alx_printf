#include "main.h"

/**
  * swtch_case - handles format specifier switch statement
  *@format: pointer to string passed in as argumnt
  *@list_words: This holds the variable args
  *@tally_character: pointer to tally character
  */

void swtch_case(const char **format, va_list list_words, int *tally_character)
{
	(*format)++;

	switch (**format)
	{
		case '%':
			write(1, "%", 1);
			(*tally_character)++;
			break;
		case 'c':
			(*tally_character) += char_func(list_words);
			break;
		case 's':
			(*tally_character) += string_func(list_words);
			break;
		case 'i':
		case 'd':
			(*tally_character) += integer_func(list_words);
			break;
		case 'r':
			(*tally_character) += reverse_func(list_words);
			break;
		default:
			(*tally_character) += write(1, (*format) - 1, 1);
			break;
	}
}
