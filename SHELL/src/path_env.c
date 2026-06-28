/*
** EPITECH PROJECT, 2026
** minishell1
** File description:
** buid path
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "../include/minishell1.h"

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

int var_env(char **env, env_t **node)
{
    return add(node, env);
}

int path_test(char *env, char *av, var_t *var)
{
    char *str = strtok_r(env, ":", &var->save);

    while (str != NULL) {
        build_path(var->path, str, av);
        if (access(var->path, X_OK) == 0)
            return 0;
        str = strtok_r(NULL, ":", &var->save);
    }
    return 1;
}