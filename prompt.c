#include "shell.h"

/**
 * read_file - Reads commands from the argument File
 * @file: File containing commands
 * @argv: Arguments passed
 * Return: -1 or 0
 */

void read_file(char *file, char **argv)
{
	FILE *fp;
	char *row = NULL;
	size_t len = 0;
	int count = 0;

	fp = fopen(file, "r");
	if (fp == NULL)
	{
	file_error(argv, count);
		exit(127);
	}
	while ((getline(&row, &len, fp)) != -1)
	{
		count++;
		check_file(row, count, fp, argv);
	}
	if (row)
		free(row);
	fclose(fp);
	exit(0);
}

/**
 * check_file - Parse commands and handle their execution
 * @row: row from file
 * @count: Error counter
 * @fp: File descriptor
 * @argv: Command line arguments
 */

void check_file(char *row, int count, FILE *fp, char **argv)
{
	char **cmd;
	int stat = 0;

	cmd = parse_cmd(row);
	if (_strncmp(cmd[0], "exit", 4) == 0)
		file_exit(cmd, row, fp);
	else if (check_builtin(cmd) == 0)
	{
		stat = builtin_proc(cmd, stat);
		free(cmd);
	}
	else
	{
		stat = check_cmd(cmd, row, count, argv);
		free(cmd);
	}
}

/**
 * file_exit - Exit status handler for file input
 * @row: row in a file
 * @cmd: Parsed command
 * @fd: File Descriptor
 */

void file_exit(char **cmd, char *row, FILE *fd)
{
	int status;
	int a = 0;

	if (cmd[a] == NULL)
	{
		free(row);
		free(cmd);
		fclose(fd);
		exit(errno);
	}
	while (cmd[1][a])
	{
		if (_isalpha(cmd[1][a++]) < 0)
			perror("Illegal number");
	}
	status = _atoi(cmd[1]);
	free(row);
	free(cmd);
	fclose(fd);
	exit(status);
}
