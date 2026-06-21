/*
** EPITECH PROJECT, 2026
** my_strcmp
** File description:
** function strncmp
*/

#include <stdio.h>

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (s1[i] == s2[i] && i < n && s1[i]) {
        i++;
    }
    if (i == n) 
        return 0;
    return s1[i] - s2[i];
}
