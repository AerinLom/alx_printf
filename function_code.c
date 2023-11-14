#include "main.h"
/**
 * char_func - This maintains the structure and execution of char
 * @list_words: This holds the variable args
 * Return: Returns number of char
 */
int char_func(va_list list_words)
{
	int tally_character = 0;
	char c = (char)va_arg(list_words, int);

	write(1, &c, 1);

	tally_character++;

	return (1);
}

/**
 * string_func - This maintains structure and execution of string
 * @list_words: This holds the variable args
 * Return: Returns number of char
 */
int string_func(va_list list_words)
{
	int tally_character = 0;
	const char *string = va_arg(list_words, const char *);

	if (string == NULL)
	{
		string = "(null)";
		while (*string != '\0')
		{
			write(1, string, 1);

			tally_character++;

			string++;
		}
		return (tally_character);
	}
	else
	while (*string != '\0')

	{
		write(1, string, 1);

		tally_character++;

		string++;
	}

	return (tally_character);
}

/**
 * integer_func - This maintains structure and execution of integer
 * @list_words: This holds the variable args
 * Return: Returns number of char
 */
int integer_func(va_list list_words)
{
	int tally_character = 0, length_Of_Str = 0;
	int d_int = va_arg(list_words, int);
	char id_buff[12];

	intConversion(d_int, id_buff);

	while (id_buff[length_Of_Str] != '\0')
	{
		length_Of_Str++;
	}
	write(1, id_buff, length_Of_Str);

	tally_character += length_Of_Str;

	return (length_Of_Str);
}
