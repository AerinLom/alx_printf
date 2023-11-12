#include "main.h"
/**
 * _printf - This function will test our built-in printf func
 * @format: Points to character in string and processes them
 * through their individual specifiers
 * Return: Total number of characters counted
 */

												/* our initialized var will count characters */
int _printf(const char *format, ...)
{												/* our initialized var will count characters */
	int tally_character = 0;								/* This stores variable argument list */
	va_list list_words;
												/* starts with parameter format */
	va_start(list_words, format);
	if (format == NULL)
	write(1, "error", 1);											/* loops until the end of format */
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;								/* proceeds to new character in the format string */
			switch (*format)
			{									/* specifies code area that is performed */
				case '%':
					write(1, "%", 1);
					tally_character++;
					break;
				case 'c':
					tally_character += char_func(list_words);
					break;
				case 's':
					tally_character += string_func(list_words);
					break;
				case 'i':
				case 'd':
					tally_character += integer_func(list_words);
					break;
				default:
				break;
			}
		}
		else
		{
			write(1, format, 1);
			tally_character++;
		}
		format++;
		}
	va_end(list_words);										/* arguments stop being processed */
	return (tally_character);									/* returns total count of characters */
}
