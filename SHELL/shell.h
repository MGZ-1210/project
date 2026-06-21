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
} var_t;

int count_words(char *str);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strchr(char *str, int c);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
char **var_env(char **env);
void build_path(char *path, char const *repo, char const *filename);
#endif