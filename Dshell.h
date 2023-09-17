#ifndef DSHELL_H
#define DSHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_LINE 256
#define PATH_MAX_LENGTH 1024
#define MAX_LEN 1024
#define BUFF_SIZE 1024
/**
 * struct cmd - Struct cmd
 *
 * @cmd: The command
 * @f: The function associated
 */

typedef struct cmd
{
	char *cmd;
	int (*f)(char **args);
} builtinCmd;

extern char **environ;
int (*get_cmd_func(char *s))(char **);
char **inputDefiner(char *text_cpy, ssize_t read_len);
int process_cmd(char **args);
int execute_cmd(char **args);
char *handle_path(char *cmd);
int exit_cmd(char **args);
int env_cmd(char **args);
int cd_cmd(char **args);
char *strcat_cmd(char *dest, const char *src);
int strcmp_cmd(char *stringa, char *stringb);
int strlen_cmd(char *string);
char *strncat_cmd(char *flat, char *source, int number);
char *strdup_cmd(char *s);
char *strcpy_cmd(char *flat, char *source);
void process_file(char *file);
void interact_mode(void);
char **tokenize_line(char *input, ssize_t read_line);
char **tokenize(char *read);
ssize_t getline_cmd(char **thread, size_t *v, FILE *stream);
char *_getline_cmd();
int atoi_cmd(char *str);
bool check_delim(const char *delim, char c);
char *strtok_cmd(char *str, const char *delim);

#endif
