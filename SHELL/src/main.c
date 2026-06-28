#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include "../include/minishell1.h"

int command(var_t *var, env_t *env)
{
    char *copy = NULL;
    int test;
    env_t *tmp = env;

    if (my_strchr(var->tab[0], '/')) {
        return access(var->tab[0], X_OK);
    }
    while (tmp != NULL) {
        if (my_strncmp(tmp->line, "PATH=", 5) == 0) {
            copy = my_strdup(tmp->line + 5);
            test = path_test(copy, var->tab[0], var);
            free(copy);
            return test;
        }
        tmp = tmp->next;
    }
    return 1;
}

int execute(var_t *var, char *path, env_t *env)
{
   pid_t pid;
    int status;
    char **envp = convert(env);

    if (!envp)
        return 84;
    pid = fork();
    if (pid == 0) {
        execve(path, var->tab, envp);
        perror(var->tab[0]);
        free(envp);
        exit(84);
    }
    free(envp);
    waitpid(pid, &status, 0);
    if (WIFEXITED(status))
        return WEXITSTATUS(status);
    return 84;
}

void main1(var_t *var)
{
    int i = 0;

    var->n = count_words(var->str);
    var->tab = malloc(sizeof(char *) * (var->n + 1));
    if (!var->tab)
        return;
    var->part = strtok_r(var->str, " ", &var->buf);
    while (var->part != NULL) {
        var->tab[i] = var->part;
        var->part = strtok_r(NULL, " ", &var->buf);
        i++;
    }
    var->tab[i] = NULL;
}

int main2(env_t *envp, char **av, char **env, var_t *var)
{
    char *cmd = NULL;
    int i;
    char err[30] = ": command not found\n";

    if (command(var, envp) == 0) {
        cmd = my_strchr(var->tab[0], '/') ? var->tab[0] : var->path;
        var->m = execute(var, cmd, envp);
    } else {
        write(2, var->tab[0], my_strlen(var->tab[0]));
        write(2, err, my_strlen(err));
        var->m = 1;
    }
    return var->m;
}

int main(int ac, char **av, char **env)
{
    int i;
    char err[30] = ": command not found\n";
    var_t var = {0};
    env_t *envp = NULL;

    var_env(env, &envp);
    while (1) {
        i = 0;
        write(1, "$> ", 3);
        if (getline(&var.str, &var.size, stdin) == -1) {
            free(var.str);
            break;
        }
        var.len = my_strlen(var.str);
        if (var.len > 0 && var.str[var.len - 1] == '\n')
            var.str[var.len - 1] = '\0';
        if (my_strcmp(var.str, "exit") == 0){
            break;
        }
        /*var.n = count_words(var.str);
        var.tab = malloc(sizeof(char *) * (var.n + 1));
        if (!var.tab)
            return 84;
        var.part = strtok_r(var.str, " ", &var.buf);
        while (var.part != NULL) {
            var.tab[i] = var.part;
            var.part = strtok_r(NULL, " ", &var.buf);
            i++;
        }
        var.tab[i] = NULL;*/
        main1(&var);
        if (!var.tab[0])
            continue;
        main2(envp, av, env, &var);
        free(var.tab);
    }
    return var.m;
}
