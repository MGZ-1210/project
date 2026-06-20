#ifndef SHELL_H
    #define SHELL_H

typedef struct var {
    int n;
    char *str;
    char *buf;
    size_t size;
    char **tab;
    char *part;
} var_t;

int count_words(char *str);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
#endif