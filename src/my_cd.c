/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** minishell1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include "../inc/my.h"

char *tcheck_path(char **env, char *buf, char *path)
{
    if (envv->path == NULL) {
        envv->statuss = 1;
        envv->status2 = 1;
        my_printf("%s: Command not found\n", buf);
        display_shell(env);
    }
    return (path);
}

void print_prompt(void)
{
    if (isatty(0) == 1)
        my_printf("$>");
}

void my_cd(char *buff, char **env)
{
    char *buf = copy_string(buff);
    char **tab = my_str_to_word_array(buf, " ");
    static char str[4096];
    char path[4096];

    if (!tab[1] || my_strcmp(tab[1], "~") == 0) {
        for (int i = 0; i < 4096; str[i] = 0, i += 1);
        getcwd(str, 4096);
        chdir("/home");
        envv->statuss = 0;
        envv->status2 = 0;
        return ;
    } else if (my_strcmp(tab[1], "-") == 0) {
        return (my_cd2(path, str, env));
    } else
        return (error_dir(tab, str, env));
}

void error_dir(char **tab, char *str, char **env)
{
    for (int i = 0; i < 4096; str[i] = 0, i += 1);
    getcwd(str, 4096);
    if (chdir(tab[1]) < 0) {
        if (errno != ENOTDIR)
            my_printf("%s: No such file or directory.\n", tab[1]);
        else
            my_printf("%s: Not a directory.\n", tab[1]);
        envv->statuss = 1;
        envv->status2 = 1;
        return ;
    }
    envv->statuss = 0;
    envv->status2 = 0;
    return ;
}

void my_cd2(char *path, char *str, char **env)
{
    for (int i = 0; i < 4096; path[i] = 0, i += 1);
    for (int i = 0; str[i]; i += 1)
        path[i] = str[i];
    for (int i = 0; i < 4096; str[i] = 0, i += 1);
    if (path[0] == '\0') {
        envv->statuss = 1;
        envv->status2 = 1;
        my_printf(": No such file or directory.\n");
        return ;
    }
    getcwd(str, 4096);
    chdir(path);
    envv->status2 = 0;
    envv->statuss = 0;
    return ;
}