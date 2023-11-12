#include "main.h"

/**
  *intConversion - converts int to string
  *@list_num: numbers in a list
  *@list_buff: the buffer
  */

void intConversion(int list_num, char *list_buff)
{
	int array_value = 0, negative = 0, print_value, iterate_num;

	if (list_num < 0)								/* Checking if the number is negative */

	{
		list_num = -list_num;

		negative = 1;								/* Negative is true */
	}

	if (list_num == 0)								/* Checking if the number is 0 */

	{
		list_buff[array_value++] = '0';
	}

	while (list_num != 0)								/* As long as number is positive */
	
	{
		print_value = list_num % 10;						

		list_buff[array_value++] = '0' + print_value;				/* Assigns array value digit by digit */

		list_num = list_num / 10;
	}

	if (negative)									/* If negative is true */
	
	{
		list_buff[array_value++] = '-';
	}

	for (iterate_num = 0; iterate_num < array_value / 2; iterate_num++)		/* Loop that reverses the output */

	{
		char save_value = list_buff[iterate_num];				/* Dereferencing of output */

		list_buff[iterate_num] = list_buff[array_value - iterate_num - 1];

		list_buff[array_value - iterate_num - 1] = save_value;
	}

	list_buff[array_value] = '\0';							/* Outputs the null character */
}
