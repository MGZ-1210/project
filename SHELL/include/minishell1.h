/*
** EPITECH PROJECT, 2026
** minishell_1
** File description:
** functions prototypes
*/

#ifndef SHELL_H
    #define SHELL_H

typedef struct var {
    int n;
    char *str;
    char *buf;
    char *save;
    size_t size;
    char **tab;
    char **envp;
    char path[10000];
    char *part;
    int len;
    int m;
} var_t;

typedef struct env {
    char *line;
    struct env *next;
} env_t;

int add(env_t **linked, char **env);
int count_words(char *str);
int my_strlen(char const *str);
char **convert(env_t *env);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strchr(char *str, int c);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
int var_env(char **env, env_t **node);
int path_test(char *env, char *av, var_t *var);
void build_path(char *path, char const *repo, char const *filename);
#endif
