#include "main.h"
/**
 * _printf - This function will test our built-in printf func
 * @format: This points to character in string and processes them through their individual specifiers
 * Return: Total number of characters counted
 */


int _printf(const char *format, ...)								// declares function printf and stores argument //

{
	int tally_character = 0;								// our initialized var will count characters //	

	va_list words;										// This will store list of variable arguments //

	va_start(words, format);								// starts with parameter format //

	while (*format != '\0')									// loops until the end of format //
	{
		if (*format == '%')

		{
			format++;								// proceeds to new character in the format string //

			switch (*format)

			{
				case '%':							// specifies the code area in which the action will be performed //

					write(1, "%", 1);

					tally_character++;

					break;

				case 'c':
				{
					char c = (char)va_arg(words, int);

					write(1, &c, 1);

					tally_character++;

					break;

				}

				case 's':

				{
					const char *string = va_arg(words, const char *);

					while (*string != '\0')

					{
						write(1, string, 1);

						tally_character++;

						string++;
					}

					break;

				}

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

	va_end(words);										// arguments stop being processed //

	return tally_character;									// returns total count of characters //

}

