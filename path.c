#include "shell.h"
/**
 * path_cmd -  Search In $PATH for executable command
 * @cmd: Parsed input
 * Return: 0 on success or  1 on failure  0
 */
int path_cmd(char **cmd)
{
	char *path, *value, *cmd_path;
	struct stat buf;

	path = _getenv("PATH");
	value = _strtok(path, ":");
	while (value != NULL)
	{
		cmd_path = build(*cmd, value);
		if (stat(cmd_path, &buf) == 0)
		{
			*cmd = _strdup(cmd_path);
			free(cmd_path);
			free(path);
			return (0);
		}
		free(cmd_path);
		value = _strtok(NULL, ":");
	}
	free(path);
	free(value);
	return (1);
}
/**
 * build - Build command
 * @token: Executable command
 * @value: Directory conatining Command
 * Return: Parsed full path of command or NULL if failed
 */
char *build(char *token, char *value)
{
	char *cmd;
	size_t len;

	len = _strlen(value) + _strlen(token) + 2;
	cmd = malloc(sizeof(char) * len);
	if (cmd == NULL)
	{
		perror("unable to alloc");
		return (NULL);
	}

	memset(cmd, 0, len);

	cmd = _strcat(cmd, value);
	cmd = _strcat(cmd, "/");
	cmd = _strcat(cmd, token);

	return (cmd);
}
/**
 * _getenv - Gets the value of environment variable by name
 * @name: Environment variable name
 * Return: The value of the environment variable or NULL if failed
 */
char *_getenv(char *name)
{
	size_t name_len, value_len;
	char *value;
	int a, b, c;


	name_len = _strlen(name);
	for (a = 0 ; environ[a]; a++)
	{
		if (_strncmp(name, environ[a], name_len) == 0)
		{
			value_len = _strlen(environ[a]) - name_len;
			value = malloc(sizeof(char) * value_len);
			if (!value)
			{

				perror("unable to alloc");
				return (NULL);
			}

			b = 0;
			for (c = name_len + 1; environ[a][c]; c++, b++)
			{
				value[b] = environ[a][c];
			}
			value[b] = '\0';

			return (value);
		}
	}
	return (NULL);
}
