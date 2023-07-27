#include "shellf.h"

/**
 * main - main entry to start all run.
 *@ac: number of arguments.
 *@av: array of inputed arguments.
 *@env: enviromental variables.
 *Return: success 0
*/
int main(int ac, char **av, char **env)
{
	char *in_buffer = NULL, **cmd = NULL;
	size_t buf_size = 0;
	ssize_t chars_decl = 0;
	int ccc = 0;
	(void)ac;
	while (1)
	{
		ccc++;
		prompt_func();
		signal(SIGINT, handle_signs);
		chars_decl = getline(&in_buffer, &buf_size, stdin);
		if (chars_decl == EOF)
			_EOF_(in_buffer);
		else if (*in_buffer == '\n')
			free(in_buffer);
		else
		{
			in_buffer[_strlen(in_buffer) - 1] = '\0';
			cmd = string_cmd(in_buffer, " \0");
			free(in_buffer);
			if (_strcmp(cmd[0], "exit") != 0)
				sh_exit(cmd);
			else if (_strcmp(cmd[0], "cd") != 0)
				change_dir(cmd[1]);
			else
				child(cmd, av[0], env, ccc);
		}
		fflush(stdin);
		in_buffer = NULL, buf_size = 0;
	}
	if (chars_decl == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
 * prompt_func - A function that prints the prompt_func
 * Return: Nothing.
 */
void prompt_func(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "cisfun$ ", 9);
}

/**
 * handle_signs - A function to handle_signs Ctr + C signal.
 *@signs: The signal to handle_signs.
 * Return: Nothing.
 */
void handle_signs(int signs)
{
	(void)signs;
	write(STDOUT_FILENO, "\ncisfun$ ", 10);
}

/**
 * _EOF_ - A function that chaecks if buffer is EOF
 *@buffer: The pointer to the input string.
 * Return: Nothing
 */
void _EOF_(char *buffer)
{
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(buffer);
	exit(EXIT_SUCCESS);
}

/**
 * sh_exit - A function that exits the shell.
 *@pr: The pointer to tokenized cmd.
 *Return: Nothing.
 */
void sh_exit(char **pr)
{
	int report = 0;

	if (pr[1] == NULL)
	{
		free_rp(pr);
		exit(EXIT_SUCCESS);
	}
	report = _atoi(pr[1]);
	free_rp(pr);
	exit(report);
}
