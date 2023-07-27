#include "shell.h"

/**
 * print_number - Prints unsigned integers using _putchar function
 * @n: Unsigned integer to be printed
 */

void print_number(unsigned int n)
{
	unsigned int x = n;

	if ((x / 10) > 0)
		print_number(x / 10);

	_putchar(x % 10 + '0');
}

/**
 * print_number_int - Prints integers using _putchar function
 * @n: Integer to be printed
 */

void print_number_int(int n)
{
	unsigned int x = n;

	if (n < 0)
	{
		_putchar('-');
		x = -x;
	}
	if ((x / 10) > 0)
		print_number(x / 10);

	_putchar(x % 10 + '0');
}

/**
 * hashtag_handler - function that removes everything after '#'
 * @buff: input buffer
 * Return: nothing
 */
void hashtag_handler(char *buff)
{
	int a;

	for (a = 0; buff[a] != '\0'; a++)
	{
		if (buff[a] == '#' && buff[a - 1] == ' ' && buff[a + 1] == ' ')
		{
			buff[a] = '\0';
		}
	}
}
