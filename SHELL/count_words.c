#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int count_words(char *str)
{
    int count = 0;
    bool word = true;

    for (int i = 0; str[i]; i++) {
        if (str[i] !=' ' && word) {
            count++;
            word = false;
        }
        if (str[i] == ' ') {
            word = true;
        }
    }
    return count;
}
