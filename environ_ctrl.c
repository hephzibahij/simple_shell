#include "shell.h"

/**
 * create_envi - A function that creates an array of Enviroment Variables
 * @envi: Array to store Enviroment Variables
 */

void create_envi(char **envi)

{
	int crt_envr;

	for (crt_envr = 0; environ[crt_envr]; crt_envr++)
	{
		envi[crt_envr] = _strdup(environ[crt_envr]);
	}
	envi[crt_envr] = NULL;
}

/**
 * free_env - A function that frees the memory of
 * the created Enviroment Variables array
 * @env:  Array of Environment variables
 */

void free_env(char **env)
{
	int crt_envr;

	for (crt_envr = 0; env[crt_envr]; crt_envr++)
	{
		free(env[crt_envr]);
	}
}

/**
 * help_env - Displays information on the shell by builtin command 'env'
 */
void help_env(void)
{
	char *msg = "env: env\n\tPrints the current environment.\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * setenv_help - Displays information on the shell by builtin command 'setenv'
 */
void setenv_help(void)
{
	char *msg = "setenv: setenv [VARIABLE] [VALUE]\n\tInitializes a new";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "environment variable, or modifies an existing one.\n\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "\tUpon failure, prints a message to stderr.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * unsetenv_help - Displays information on the shellby builtin command
 * 'unsetenv'
 */
void unsetenv_help(void)
{
	char *msg = "unsetenv: unsetenv [VARIABLE]\n\tRemoves an ";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "environmental variable.\n\n\tUpon failure, prints a ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "message to stderr.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}
