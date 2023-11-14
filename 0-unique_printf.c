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
	va_start(list_words, format);								/* loops until the end of format */
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	if (list_words == NULL)
		return (-2);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			swtch_case(&format, list_words, &tally_character);
		}
		else
		{
			tally_character += write(1, format, 1);
		}
		format++;
		}
	va_end(list_words);										/* arguments stop being processed */
	return (tally_character);									/* returns total count of characters */
}
