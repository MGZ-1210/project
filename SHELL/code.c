#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

void build_path(char *path, char const *repo, char const *filename)
{
    int i = 0;
    int j = 0;

    while (repo[i] != '\0') {
        path[i] = repo[i];
        i++;
    }
    path[i] = '/';
    i++;
    while (filename[j] != '\0') {
        path[i] = filename[j];
        i++;
        j++;
    }
    path[i] = '\0';
}

char **var_env(char **env)
{
    int n = 0;
    char **var = NULL;

    int j = 0;
    for (int i = 0; env[i]; i++) {
        n++;
    }
    var = malloc(sizeof(char *) * (n + 1));
    if (!var)
        return NULL;
    for (j = 0; env[j]; j++) {
        var[j] = my_strdup(env[j]);
    }
    var[j] = NULL;
    return var;
}
