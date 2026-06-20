#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

int main(int ac, char **av, char **env)
{
    int i;
    var_t var = {0};

    while (1) {
        i = 0;
        write(1, "$> ", 3);
        if (getline(&var.str, &var.size, stdin) == -1) {
            return 84;
        }
        var.str = strtok(var.str, "\n");
        var.n = count_words(var.str);
        var.tab = malloc(sizeof(char *) * var.n + 1);
        var.part = strtok_r(var.str, " ", &var.buf);
        while (var.part != NULL) {
            var.tab[i] = var.part;
            var.part = strtok_r(NULL, " ", &var.buf);
            i++;
        }
        var.tab[i] = NULL;
    }
    return 0;
}