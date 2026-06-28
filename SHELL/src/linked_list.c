/*
** EPITECH PROJECT, 2026
** minishell1
** File description:
** linked list manipulation
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/minishell1.h"

env_t *create_noeud(char *line)
{
    env_t *node = malloc(sizeof(env_t));

    if (!node) {
        return NULL;
    }
    node->line = my_strdup(line);
    node->next = NULL;
    return node;
}

void run(env_t **linked, env_t *new)
{
    env_t *tmp = NULL;

    tmp = *linked;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = new;
}

int add(env_t **linked, char **env)
{
    env_t *new;
    env_t *tmp = NULL;
    int i = 0;

    while (env[i] != NULL) {
        new = create_noeud(env[i]);
        if (!new)
            return 84;
        if (*linked == NULL) {
            *linked = new;
        } else {
            run(linked, new);
        }
        i++;
    }
    return 0;
}

char **convert(env_t *env)
{
    env_t *tmp = env;
    int n = 0;
    char **tab;

    while (tmp != NULL) {
        n++;
        tmp = tmp->next;
    }
    tab = malloc(sizeof(char *) * (n + 1));
    if (!tab)
        return NULL;
    tmp = env;
    for (int i = 0; tmp != NULL; i++) {
        tab[i] = tmp->line;
        tmp = tmp->next;
    }
    tab[n] = NULL;
    return tab;
}