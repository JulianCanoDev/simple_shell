#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
extern char **environ;
#define TOKENS_BUFFER_SIZE 64
#define LINE_SIZE 1024
#define TOKEN_DELIMITERS " \t\r\n\a"

/**
 * struct builtins - structure for built-ins
 * @arg: arguments
 * @line: line
 * @env: environment
 * @builtin: builtin
 * Description: structure of shell
 */
typedef struct builtins
{
	char *arg;
	void (*builtin)(char **args, char *line, char **env);
} builtins_t;

int _putchar(char c);
void shell(int ac, char **av, char **env);
void exit_shell(char **args, char *line, char **env);
void env_shell(char **args, char *line, char **env);
char *_getline(void);
char **split_line(char *line);
int check_for_builtins(char **args, char *line, char **env);
int launch_prog(char **args);
int builtins_checker(char **args);
int _strcmp(char *s1, char *s2);
char *_strstr(char *haystack, char *needle);
int _strlen(char *s);
void prompt(void);
char *_getenv(char *env);
char *search_cwd(char *filename, char *er);
int execute_prog(char **args, char *line, char **env, int flow);
int bridge(char *check, char **args);
char *find_path(char *filename, char *tmp, char *er);
char *read_dir(char *er, struct dirent *s, char *fil, int l, char *fp, char *t);
char *save_path(char *tmp, char *path);
#endif /* SHELL_H */
