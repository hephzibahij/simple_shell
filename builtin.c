#include "shell.h"

/**
 * check_builtin - Function that checks the command in built-in
 * @cmd: command pointer
 * Return: 0 Succes -1 Fail
 */

int check_builtin(char **cmd)
{
	builtin fun[] = {
		{"cd", NULL},
		{"help", NULL},
		{"exec", NULL},
		{"env", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int a = 0;

	if (*cmd == NULL)
	{
		return (-1);
	}
	while ((fun + a)->command)
	{
		if (_strcmp(cmd[0], (fun + a)->command) == 0)
			return (0);
		a++;
	}
	return (-1);
}

/**
 * builtin_proc - Functions that process builtin commands
 * @cmd: command pointer
 * @st: Pointer to the status of last execution
 * Return: -1 Failure 0 Success
 */

int builtin_proc(char **cmd, int st)
{
	builtin built_in[] = {
		{"cd", change_dirc},
		{"env", ev_dis},
		{"help", dis_help},
		{"exec", built_exec},
		{"history", dis_histry},
		{NULL, NULL}
	};
	int a = 0;

	while ((built_in + a)->command)
	{
		if (_strcmp(cmd[0], (built_in + a)->command) == 0)
		{
			return ((built_in + a)->function(cmd, st));
		}
		a++;
	}
	return (-1);
}

/**
 * builtin_exit - Function that exit status for built-in commands
 * @cmd: command pointer
 * @input: pointing to the input recieved from user
 * @argv: Arguments vector
 * @c: Array to shell execution count
 * @stat: Exit status
 */

void builtin_exit(char **cmd, char *input, char **argv, int c, int stat)
{
	int status, a = 0;

	if (cmd[1] == NULL)
	{
		free(input);
		free(cmd);
		exit(stat);
	}
	while (cmd[1][a])
	{
		if (_isalpha(cmd[1][a++]) != 0)
		{
			_prerror(argv, c, cmd);
			free(input);
			free(cmd);
			exit(2);
		}
		else
		{
			status = _atoi(cmd[1]);
			if (status == 2)
			{
				_prerror(argv, c, cmd);
				free(input);
				free(cmd);
				exit(status);
			}
			free(input);
			free(cmd);
			exit(status);
		}
	}
}

/**
 * dis_help - Function to display help for builtin commands
 * @cmd: command pointer
 * @st: Pointer to the status of last command executed
 * Return: 0 Success
 */
int dis_help(char **cmd, __attribute__((unused))int st)
{
	if (!cmd[1])
		help_all();
	else if (_strcmp(cmd[1], "alias") == 0)
		alias_help();
	else if (_strcmp(cmd[1], "cd") == 0)
		cd_help();
	else if (_strcmp(cmd[1], "exit") == 0)
		help_exit();
	else if (_strcmp(cmd[1], "env") == 0)
		help_env();
	else if (_strcmp(cmd[1], "setenv") == 0)
		setenv_help();
	else if (_strcmp(cmd[1], "unsetenv") == 0)
		unsetenv_help();
	else if (_strcmp(cmd[1], "help") == 0)
		help_help();
	return (0);
}
