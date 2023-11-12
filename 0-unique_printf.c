#include "main.h"
/**
 * _printf - This function will test our built-in printf func
 * @format: This points to character in string and processes them through their individual specifiers
 * Return: Total number of characters counted
 */

												/* our initialized var will count characters */ 
int _printf(const char *format, ...)

{												 /* our initialized var will count characters */ 
	int tally_character = 0, length_Of_Str;
												/* This will store list of variable arguments */
	va_list list_words;
												/* starts with parameter format */
	va_start(list_words, format);
												/* loops until the end of format */
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
				{
					char c = (char)va_arg(list_words, int);

					write(1, &c, 1);

					tally_character++;

					break;
				}

				case 's':
				{
					const char *string = va_arg(list_words, const char *);

					while (*string != '\0')

					{
						write(1, string, 1);

						tally_character++;

						string++;
					}

					break;
				}

				 case 'i':
			       	{
                                                int d_int = va_arg(list_words, int);
                                                char id_buff[12];
                                                intConversion(d_int, id_buff);
                                                length_Of_Str = 0;
						
						while (id_buff[length_Of_Str] != '\0')
                                                {
                                                        length_Of_Str++;
						}
						write(1, id_buff, length_Of_Str);
						tally_character += length_Of_Str;
                                                break;
                                        }

				case 'd':
                                        {
                                                int d_int = va_arg(list_words, int);
                                                char id_buff[12];
                                                intConversion(d_int, id_buff);
                                                length_Of_Str = 0;
						
						while (id_buff[length_Of_Str] != '\0')
                                                {
                                                        length_Of_Str++;
                                                }
						write(1, id_buff, length_Of_Str);
						tally_character += length_Of_Str;
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

	va_end(list_words);										/* arguments stop being processed */

	return tally_character;									/* returns total count of characters */

}
