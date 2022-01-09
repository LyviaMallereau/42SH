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

char *copy_string(char *buff)
{
    char *str = malloc(sizeof(char) * 4096);
    int i = 0;
    int j = 0;

    while (buff[i] != '\n' && buff[i] != '\0') {
        if (buff[i] == '"')
            ++i;
        str[j] = buff[i];
        ++i;
        ++j;
    }
    str[j] = '\0';
    return (str);
}

void unset_enviro(char *buff, char **env)
{
    char *str = copy_string(buff);
    char **tab = my_str_to_word_array(str, " ");
    char **envi = malloc(sizeof(char *) * 4096);
    int i = 0;
    int y = 0;

    tcheck_error(tab, env);
    char *dest = my_strcat(tab[1], "=");
    for (; env[i] != NULL;) {
        if (my_strncmp(dest, env[i], my_strlen(dest)) == 0) {
            envi[i] == env[y+1];
            ++y;
        }
        envi[i] = env[y];
        ++y;
        ++i;
    }
    envi[i] == NULL;
    envv->enviro = envi;
}

void set_enviro(char *buff, char **env)
{
    char *str = copy_string(buff);
    char **tab = my_str_to_word_array(str, " ");

    if (tab[1] == NULL) {
        display_enviro(env);
        return ;
    }
    if (my_str_isnum(tab[1]) == 1) {
        my_printf("setenv: Variable name must contain ");
        my_printf("alphanumeric characters.\n");
        envv->statuss = 1;
        envv->status2 = 1;
        return ;
    }
    char **envi = unset_env2(buff, env);
    envv->enviro = reset_enviro2(str, envi);
    envv->status2 = 0;
    envv->statuss = 0;
    return ;
}

void display_enviro(char **env)
{
    int i = 0;

    while (env[i] != NULL) {
        my_printf("%s\n", env[i]),
        ++i;
    }
    envv->statuss = 0;
    envv->status2 = 0;
    return ;
}

char **unset_env2(char *buff, char **env)
{
    char *str = copy_string(buff);
    char **tab = my_str_to_word_array(str, " ");
    char **envi = malloc(sizeof(char *) * 4096);
    int i = 0;
    int y = 0;

    tcheck_error(tab, env);
    char *dest = my_strcat(tab[1], "=");
    for (; env[i] != NULL;) {
        if (my_strncmp(dest, env[i], my_strlen(dest)) == 0) {
            envi[i] == env[y+1];
            ++y;
        }
        envi[i] = env[y];
        ++y;
        ++i;
    }
    envi[i] == NULL;
    return (envi);
}