#include "shellf.h"
/**
 * get_path - A function to gets the full value from.
 *enviromental variable PATH.
 *@env: The pointer to enviromental variables.
 * Return: All tokenized pathways for cmds.
 */
char **get_path(char **env)
{
	char *pathvalue = NULL, **pathways = NULL;
	unsigned int i = 0;

	pathvalue = strtok(env[i], "=");
	while (env[i])
	{
		if (_strcmp(pathvalue, "PATH"))
		{
			pathvalue = strtok(NULL, "\n");
			pathways = string_cmd(pathvalue, ":");
			return (pathways);
		}
		i++;
		pathvalue = strtok(env[i], "=");
	}
	return (NULL);
}
