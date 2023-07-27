#ifndef SHELLF
#define SHELLF

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

int main(int ac, char **av, char **env);
void prompt_func(void);
void handle_signs(int signs);
void _EOF_(char *buffer);
void sh_exit(char **cmd);

int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _atoi(char *s);
char *_strcat(char *dest, char *src);

void child(char **cmd, char *progname, char **env, int f);
int change_dir(const char *path);

void execute(char **cmd, char *progname, char **env, int f);
void print_env(char **env);
char **get_path(char **env);
void msgerror(char *progname, int fcode, char **cmd);
char **string_cmd(char *buffer, const char *s);
void free_rp(char **cmd);
void free_exit(char **cmd);

#endif
