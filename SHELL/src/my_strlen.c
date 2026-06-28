/*
** EPITECH PROJECT, 2026
** my_strlen
** File description:
** function that counts and returns the number of characters
*/

#include <unistd.h>

int my_strlen(char const *str)
{
    int i;
    int n;

    n = 0;
    for (i = 0; str[i] != '\0'; i++) {
        n++;
    }
    return n;
}
