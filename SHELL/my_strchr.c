#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

char *my_strchr(char *str, int c)
{
    int  i = 0;

    for (i = 0; str[i]; i++) {
        if (str[i] == c) {
            return &str[i];
        }
    }
    if (c == '\0') {
        return &str[i];
    }
    return NULL;
}
