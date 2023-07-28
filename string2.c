#include "shell.h"

/**
 * _strchr - function that locates character in a string
 * @s: string to be searched
 * @c: character to be located
 * Return: pointer to character
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
		{
			break;
		}
	} while (*s++);
	return (s);
}

/**
 * _strcpy - function that copies a string
 * @dest: string destination
 * @src: string source
 * Return: destination
 */


char *_strcpy(char *dest, char *src)
{
	int a = 0;

	while (src[a])
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}

/**
 * _strncpy - function that copies a string
 * @dest: string destination
 * @src: string source
 * @n: number of charaters to be copied
 * Return: void
 */
char *_strncpy(char *dest, char *src, int n)
{
	int a = 0;

	while (a < n && *(src + a))
	{
		*(dest + a) = *(src + a);
		a++;
	}
	while (a < n)
	{
		*(dest + a) = '\0';
			a++;
	}
	return (dest);
}

/**
 * _strcat - function that concatenates two strings
 * @dest: string destination
 * @src: string source
 * Return: combined string
 */
char *_strcat(char *dest, char *src)
{
	char *s = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (s);
}

/**
 * _strdup - duplicate a string
 * @str: string
 * Return: duplicated string or Null if failed
 */
char *_strdup(char *str)
{
	size_t len, a;
	char *str2;

	len = _strlen(str);
	str2 = malloc(sizeof(char) * (len + 1));
	if (!str2)
	{
		return (NULL);
	}
	for (a = 0; a <= len; a++)
	{
		str2[a] = str[a];
	}
	return (str2);
}
