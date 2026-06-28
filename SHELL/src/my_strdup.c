/*
** EPITECH PROJECT, 2026
** my_strdup.c
** File description:
** function  that allocates memory
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/minishell1.h"

char *my_strdup(char const *src)
{
    char *caracter;

    caracter = malloc(sizeof(char) * (my_strlen(src) + 1));
    if (caracter == NULL) {
        return NULL;
    }
    my_strcpy(caracter, src);
    return caracter;
}
