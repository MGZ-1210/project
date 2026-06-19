#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

int main(int ac, char **av, char **env)
{
    char *str = NULL;
    char *buf = NULL;
    size_t size = 0;
    char **tab = NULL;

    while (1) {
        int i = 0;
        write(1, "$> ", 3);
        if (getline(&str, &size, stdin) == -1) {
            return 84;
        }
        str = strtok(str, "\n");
        int n = count_words(str);
        tab = malloc(sizeof(char *) * n + 1);
        char *part = strtok_r(str, " ", &buf);
        while (part != NULL) {
            tab[i] = part;
            part = strtok_r(NULL, " ", &buf);
            i++;
        }
        tab[i] = NULL;
        for (int i = 0; tab[i]; i++) {
        printf("%s\n", tab[i]);
    }
    }
    return 0;
}