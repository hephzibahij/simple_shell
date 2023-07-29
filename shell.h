#ifndef SHELL_H
#define SHELL_H

/** MACROS */

#define PRINT(c) (write(STDERR_FILENO, c, _strlen(c)))
#define BUFSIZE 10240
#define DELIMITER " \t\r\n\a"

/** STANDARD LIBRARIES */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>

/** Builting Structure*/

/**
 * builtin_struct - Builtin structure function
 * @command: - Built-in command
 * @function: - Pointer to similar functions in the builtin commands
 */
typedef struct _builtin
{
	char *command;
	int (*function)(char **row, int st);
} builtin;

/** Builtin Functions*/
int check_builtin(char **cmd);
int builtin_proc(char **cmd, int st);
void builtin_exit(char **cmd, char *input, char **argv, int c, int stat);
int change_dirc(char **cmd, __attribute__((unused))int st);
int ev_dis(__attribute__((unused)) char **cmd, __attribute__((unused)) int st);
int built_exec(char **cmd, int st);
int dis_histry(__attribute__((unused))char **c, __attribute__((unused))int st);
int dis_help(char **cmd, __attribute__((unused))int st);

/** Delimiter Functions */

unsigned int check_delim(char c, const char *str);
char *_strtok(char *str, const char *delim);
char *_getline();
char *enter(char *string);
char *space(char *str);
void hashtag_handler(char *buff);

/** Path Functions */
int path_cmd(char **cmd);
char *build(char *token, char *value);
char *_getenv(char *name);

/* Main & Prompt Function */
int main(__attribute__((unused)) int argc, char **argv);
void prompt(void);
void signal_to_handle(int sig);
void read_file(char *file, char **argv);
void check_file(char *row, int count, FILE *fp, char **argv);
void file_exit(char **cmd, char *row, FILE *fd);

/* String Functions */
int _strcmp(char *s1, char *s2);
int _isalpha(int c);
int _isalpha(int c);
char *_itoa(unsigned int n);
void array_rev(char *arr, int len);
int intlen(int num);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);
int _putchar(char c);
void _puts(char *str);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
int _atoi(char *s);

/* Child Process*/

int check_cmd(char **cmd, char *input, int c, char **argv);
char **parse_cmd(char *input);
int print_echo(char **cmd);
int history(char *input);
char **separator(char *input);


/* Environmen Functions */
extern char **environ;
void create_envi(char **envi);
void free_env(char **env);


/* Help Control */
void help_all(void);
void alias_help(void);
void cd_help(void);
void help_exit(void);
void help_help(void);
void help_env(void);
void setenv_help(void);
void unsetenv_help(void);

/* Error Control */
void print_error(char *input, int counter, char **argv);
void _prerror(char **argv, int c, char **cmd);
void file_error(char **argv, int c);

/* Memory Control */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_all(char **cmd, char *row);
char *_memcpy(char *dest, char *src, unsigned int n);
void *fill_an_array(void *a, int el, unsigned int len);
void *_calloc(unsigned int size);

/* Write Function */

void print_number(unsigned int n);
void print_int_number(int n);
void handle_hashtag(char *buff);

#endif
