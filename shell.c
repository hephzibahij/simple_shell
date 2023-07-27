#include "shell.h"

/**
 * main - entry point to the shell
 * @argc : Arguement count
 * @argv : Arguement vector
 * Return: (0) for success
 */
int main(__attribute__((unused)) int argc, char **argv)
{
	char *input, **cmd, **commands;
	int count = 0, a, condition = 1, stat = 0;

	if (argv[1] != NULL)
		read_file(argv[1], argv);
	signal(SIGINT, signal_to_handle);

	while (condition)
	{
		count++;
		if (isatty(STDIN_FILENO))
			prompt();
		input = _getline();
		if (input[0] == '\0')
			continue;
		history(input);
		commands = separator(input);
		for (a = 0; commands[a] != NULL; a++)
		{
			cmd = parse_cmd(commands[a]);
			if (_strcmp(cmd[0], "exit") == 0)
			{
				free(commands);
				builtin_exit(cmd, input, argv, count, stat);
			}
			else if (check_builtin(cmd) == 0)
			{
				stat = builtin_proc(cmd, stat);
				free(cmd);
				continue;
			}
			else
				stat = check_cmd(cmd, input, count, argv);
			free(cmd);
		}
		free(input);
		free(commands);
		wait(&stat);
	}
	return (stat);
}

/**
 * prompt - displays input
 *
 */
void prompt(void)
{
	PRINT("cisfun$ ");

}

/**
 * signal_to_handle - Configures ^C not to terminate our shell
 * @sig: Incoming Signal
 */

void signal_to_handle(int sig)
{
	if (sig == SIGINT)
	{
		PRINT("\ncisfun$ ");
	}
}
