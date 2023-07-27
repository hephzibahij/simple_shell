#include "shell.h"
/**
 * check_delim - function that checks if a character matchs any character
 * @c: character to check
 * @str: string of delimiters
 * Return: 1 on success, 0 on failure
 */
unsigned int check_delim(char c, const char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (c == str[i])
			return (1);
	}
	return (0);
}
/**
 * _strtok - function that extracts tokens of a string
 * @str: string
 * @delim: delimiter
 * Return: pointer to the next token or NULL
 */
char *_strtok(char *str, const char *delim)
{
	static char *tokens;
	static char *new_token;
	unsigned int i;

	if (str != NULL)
		new_token = str;
	tokens = new_token;
	if (tokens == NULL)
		return (NULL);
	for (i = 0; tokens[i] != '\0'; i++)
	{
		if (check_delim(tokens[i], delim) == 0)
			break;
	}
	if (new_token[i] == '\0' || new_token[i] == '#')
	{
		new_token = NULL;
		return (NULL);
	}
	tokens = new_token + i;
	new_token = tokens;
	for (i = 0; new_token[i] != '\0'; i++)
	{
		if (check_delim(new_token[i], delim) == 1)
			break;
	}
	if (new_token[i] == '\0')
		new_token = NULL;
	else
	{
		new_token[i] = '\0';
		new_token = new_token + i + 1;
		if (*new_token == '\0')
			new_token = NULL;
	}
	return (tokens);
}
/**
* _getline - read input from standard input by user
* Return: the input on a buffer
*/
char *_getline()
{
	int a, rd, buffsize = BUFSIZE;
	char c = 0, *buffer, *buf;

	buffer = malloc(buffsize);
	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	for (a = 0; c != EOF && c != '\n'; a++)
	{
		fflush(stdin);
		rd = read(STDIN_FILENO, &c, 1);
		if (rd == 0)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		buffer[a] = c;
		if (buffer[0] == '\n')
			return (enter(buffer));
		if (a >= buffsize)
		{
			buffer = realloc(buffer, (buffsize + 2));
			if (buffer == NULL)
			{
				free(buffer);
				return (NULL);
			}
		}
	}
	buffer[a] = '\0';
	buf = space(buffer);
	free(buffer);
	hashtag_handler(buf);
	return (buf);
}
/**
 * enter - Handles newline character input
 * @string: String to be handled
 * Return: Empty string
 */
char *enter(char *string)
{
	free(string);
	return ("\0");
}

/**
 * space - Modifies the input string to remove preceeding whitespaces
 * @str: Input to be modifies
 * Return: Returns the modified string
 */
char *space(char *str)
{
	int a, b = 0;
	char *buff;

	buff = malloc(sizeof(char) * (_strlen(str) + 1));
	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}
	for (a = 0; str[a] == ' '; a++)
		;
	for (; str[a + 1] != '\0'; a++)
	{
		buff[b] = str[a];
		b++;
	}
	buff[b] = '\0';
	if (buff[0] == '\0' || buff[0] == '#')
	{
		free(buff);
		return ("\0");
	}
	return (buff);
}
