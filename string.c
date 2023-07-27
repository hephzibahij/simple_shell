#include "shell.h"

/**
 * _strcmp -compares string
 * @s1: string to character
 * @s2: string to character
 *
 * Return: 0
 */
int _strcmp(char *s1, char *s2)
{
	int res = 0, a, len1, len2;

	len1 = _strlen(s1);
	len2 = _strlen(s2);

	if (s1 == NULL || s2 == NULL)
		return (1);

	if (len1 != len2)
		return (1);

	for (a = 0; s1[a]; a++)
	{
		if (s1[a] != s2[a])
		{
			res = s1[a] - s2[a];
			break;
		}
		else
			continue;
	}
	return (res);
}

/**
 * _isalpha - function to check if c is alphabet
 * @c: character to check
 * Return: 1 if true 0 if false
 */
int _isalpha(int c)
{
	if (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90)))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/**
 * _itoa - funciton that convert integer to character
 * @n: integer to convert
 * Return: character pointer
 */
char *_itoa(unsigned int n)
{
	int len = 0, a = 0;
	char *s;

	len = intlen(n);
	s = malloc(len + 2);

	if (!s)
	{
		free(s);
		return (NULL);
	}
	*s = '\0';

	while (n / 10)
	{
		s[a] = (n % 10) + '0';
		n /= 10;
		a++;
	}

	s[a] = (n % 10) + '0';
	array_rev(s, len);
	s[a + 1] = '\0';

	return (s);
}
/**
 * array_rev - function reverse an array
 * @arr: array to reverse
 * @len: length of array
 */
void array_rev(char *arr, int len)
{
	int a;
	char tmp;

	for (a = 0; a < (len / 2); a++)
	{
		tmp = arr[a];
		arr[a] = arr[(len - 1) - a];
		arr[(len - 1) - a] = tmp;
	}
}
/**
 * intlen - function that determine length of integer
 * @num: given integer
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
