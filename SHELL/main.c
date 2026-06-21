#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include "shell.h"

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

int command(var_t *var, char **envp)
{
    int cmd = 1;

    if (my_strchr(var->tab[0], '/')) {
        return access(var->tab[0], X_OK);
    }
    for (int i = 0; envp[i]; i++) {
        if (my_strncmp(envp[i], "PATH=", 5) == 0) {
            cmd = path_test(&envp[i][5], var->tab[0], var);
        }
    }
    return cmd;
}

int execute(char *path, char **envp, var_t *var)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        execve(path, var->tab, envp);
        perror(var->tab[0]);
        exit(84);
    }
    waitpid(pid, &status, 0);
    if (WIFEXITED(status)) {
        return WEXITSTATUS(status);
    }
    return 84;
}

int main(int ac, char **av, char **env)
{
    int  m;
    char *cmd = NULL;
    int i;
    char err[30] = ": command not found\n";
    var_t var = {0};

    while (1) {
        i = 0;
        write(1, "$> ", 3);
        if (getline(&var.str, &var.size, stdin) == -1)
            return 84;
        var.len = my_strlen(var.str);
        if (var.len > 0 && var.str[var.len - 1] == '\n')
            var.str[var.len - 1] = '\0';
        if (my_strcmp(var.str, "exit") == 0){
            break;
        }
        var.n = count_words(var.str);
        var.tab = malloc(sizeof(char *) * (var.n + 1));
        if (!var.tab)
            return 84;
        var.part = strtok_r(var.str, " ", &var.buf);
        while (var.part != NULL) {
            var.tab[i] = var.part;
            var.part = strtok_r(NULL, " ", &var.buf);
            i++;
        }
        var.tab[i] = NULL;
        if (!var.tab[0])
            continue;
        var.envp = var_env(env);
        if (command(&var, var.envp) == 0) {
            cmd = my_strchr(var.tab[0], '/') ? var.tab[0] : var.path;
            m = execute(cmd, var.envp, &var);
        } else {
            write(2, var.tab[0], my_strlen(var.tab[0]));
            write(2, err, my_strlen(err));
            m = 1;
        }
        for (int i = 0; var.envp[i]; i++)
            free(var.envp[i]);
        free(var.envp);
        free(var.tab);
    }
    return m;
}