#ifndef FUNCTIONS_SHELL_H
#define FUNCTIONS_SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;
int _strcmp(char *s1, char *s2, int n);
int _strlen(char *s);
int _strlenconst(char const *s);
char *_strncpy(char *dest, char *src, int n);
char *str_concat(char *s1, char *s2);
char *_prompt(char *buffer, int *status);
void _exited(char **p, char *buffer, int *status);
char **assign_args(char **p, int cont);
char **_store_args(char *buffer, int *cont);
char *_found_path(char *buffer, char **p);
char *execute_ok(char *cpypath, char **p, int *basura);
void not_command(const char *shell, const char *comm, const char *num);
int _env(char **p, int *status);
void handle_sigint(int sign);
char *number_to_str(int num);
void only_command(char *buffer, char **p, char *name_shell, int count_prompt,
int *status);
void execute_pathname(char **p, char *name_shell, int count_prompt,
int *status);

#endif /* FUNCTIONS_SHELL_H */
