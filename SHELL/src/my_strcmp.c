/*
** EPITECH PROJECT, 2026
** my_strcmp
** File description:
** function strcmp
*/

#include <stdio.h>

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int j = 0;

    while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j]) {
        i++;
        j++;
    }
    if (s1[i] != s2[j])
        return s1[i] - s2[j];
    else
        return 0;
}
