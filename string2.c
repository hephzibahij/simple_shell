#include "shell.h"
/**
 * _strcpy - function that copies a string
 * @dest: destination
 * @src: source
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
 * _strcat - function that concatenates two strings
 * @dest: first string
 * @src: second string
 * Return: first string + second string
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
 * _strncmp - function that compares n amount of characters of two strings
 * @s1: first string
 * @s2: second string
 * @n: amount of characters to compare
 * Return: 1 if the strings don't match otherwise 0
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t a;

	if (s1 == NULL)
		return (-1);

	for (a = 0; a < n && s2[a]; a++)
	{
		if (s1[a] != s2[a])
		{
			return (1);
		}
	}
	return (0);
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
