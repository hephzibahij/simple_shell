#include "shell.h"

/**
 * _putchar - function that writes the character to stdout
 * @c: Print chaacter
 * Return: void
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _puts - function that prints a string
 * @str: string's pointer
 * Return: void
 */
void _puts(char *str)
{
	int a;

	for (a = 0; str[a] != '\0'; a++)
	{
		_putchar(str[a]);
	}
	_putchar('\n');
}

/**
 * _strlen - function that counts the length of a string
 * @s: string's input
 * Return: length of string
 */

int _strlen(char *s)
{
	int a;

	for (a = 0; s[a] != '\0'; a++)
	{
		continue;
	}
	return (a);
}

/**
 * intlen - function that determine integer's length
 * @num: integer number
 * Return: length of integer
 */

int intlen(int num)
{
	int len = 0;

	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

/**
 * _atoi - function to convert string to a integer
 * @s: string's input
 * Return: converted integer
 */

int _atoi(char *s)
{
	int a = 0, b = 1, c;
	unsigned int l = 0;

	while (s[a] != '\0')
	{
		if (s[a] == '-')
		{
			return (2);
		}
		c = s[a] - '0';

		if (l > 0 && !(c >= 0 && c <= 9))
			break;

		if (c >= 0 && c <= 9)
			l = l * 10 + c;

		a++;
	}
	l *= b;
	return (l);
}
