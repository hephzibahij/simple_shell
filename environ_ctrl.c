#include "shell.h"

/**
 * create_envi - Function that creates enviroment variables arrays
 *
 * @envi: Enviroment variables array
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
 * free_env - Function to frees the environment variable array memory
 *
 * @env: Environment variables array
 */

void free_env(char **env)
{
	int ce;

	for (ce = 0; env[ce]; ce++)
	{
		free(env[ce]);
	}
}

/**
 * help_env - Function that displays information about the env
 *
 */
void help_env(void)
{
	char *msg = "env: env\n\tPrints the current environment.\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * setenv_help - Function that displays information setenv
 *
 */
void setenv_help(void)
{
	char *msg = "setenv: setenv [VARIABLE] [VALUE]\n\tInitializes a new";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "environment variable, or modifies an existing one.\n\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "\tWhen failed, prints a message to stderr.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * unsetenv_help - Function that displays information on unsetenv command
 *
 */
void unsetenv_help(void)
{
	char *msg = "unsetenv: unsetenv [VARIABLE]\n\tRemoves an ";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "environmental variable.\n\n\tWhen failed, prints a ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "message to stderr.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}
