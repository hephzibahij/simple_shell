#include "shell.h"

/**
 * print_error - Function to display error message
 * @input: User input
 * @counter: Count of shell loop
 * @argv: Arguments vector
 */

void print_error(char *input, int counter, char **argv)
{
	char *er;

	PRINT(argv[0]);
	PRINT(": ");
	er = _itoa(counter);
	PRINT(er);
	free(er);
	PRINT(": ");
	PRINT(input);
	PRINT(": not found\n");
}

/**
 *  _prerror - Function to prints custom Error
 * @argv: Arguments vector
 * @c: character to check
 * @cmd: Command pointer
 */

void _prerror(char **argv, int c, char **cmd)
{
	char *er = _itoa(c);

	PRINT(argv[0]);
	PRINT(": ");
	PRINT(er);
	PRINT(": ");
	PRINT(cmd[0]);
	PRINT(": Illegal number: ");
	PRINT(cmd[1]);
	PRINT("\n");
	free(er);
}

/**
 * file_error - Function to prints file error
 * @argv: Arguments vector
 * @c: character to check
 */

void file_error(char **argv, int c)
{
	char *er = _itoa(c);

	PRINT(argv[0]);
	PRINT(": ");
	PRINT(er);
	PRINT(": Can't open ");
	PRINT(argv[1]);
	PRINT("\n");
	free(er);
}
