#include "shell.h"
/**
 * change_dirc - Function that changes directory
 * @cmd: command pointer
 * @st: Status of last command executed
 * Return: 0 on success 1 if failed (For OLDPWD Always 0 incase of no OLDPWD)
 */
int change_dirc(char **cmd, __attribute__((unused))int st)
{
	int value = -1;
	char cwd[PATH_MAX];

	if (cmd[1] == NULL)
		value = chdir(getenv("HOME"));
	else if (_strcmp(cmd[1], "-") == 0)
	{
		value = chdir(getenv("OLDPWD"));
	}
	else
		value = chdir(cmd[1]);

	if (value == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (value != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}
/**
 * env_dis - Function to display enviroment variable
 * @cmd: command pointer
 * @st: status of last command executed
 * Return: Always 0
 */
int ev_dis(__attribute__((unused)) char **cmd, __attribute__((unused)) int st)
{
	size_t a;
	int len;

	for (a = 0; environ[a] != NULL; a++)
	{
		len = _strlen(environ[a]);
		write(1, environ[a], len);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
/**
 * built_exec - Functions that execute echo cases
 * @st: pointer status
 * @cmd: command pointer
 * Return: Always 1 Or execute normal echo
 */
int built_exec(char **cmd, int st)
{
	char *path;
	unsigned int pid = getppid();

	if (_strncmp(cmd[1], "$?", 2) == 0)
	{
		print_int_number(st);
		PRINT("\n");
	}
	else if (_strncmp(cmd[1], "$$", 2) == 0)
	{
		print_number(pid);
		PRINT("\n");
	}
	else if (_strncmp(cmd[1], "$PATH", 5) == 0)
	{
		path = _getenv("PATH");
		PRINT(path);
		PRINT("\n");
		free(path);
	}
	else
		return (print_echo(cmd));

	return (1);
}
/**
 * dis_history - Function to display history of command
 * @c: parsed command
 * @st: pointer to the status of last command executed
 * Return: 0 success or -1 if fail
 */
int dis_histry(__attribute__((unused))char **c, __attribute__((unused))int st)
{
	char *filename = ".simple_shell_history";
	FILE *fp;
	char *row = NULL;
	size_t len = 0;
	int counter = 0;
	char *er;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		return (-1);
	}
	while ((getline(&row, &len, fp)) != -1)
	{
		counter++;
		er = _itoa(counter);
		PRINT(er);
		free(er);
		PRINT(" ");
		PRINT(row);
	}
	if (row)
		free(row);
	fclose(fp);
	return (0);
}
