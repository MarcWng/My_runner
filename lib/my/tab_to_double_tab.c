/*
** EPITECH PROJECT, 2018
** tab_to_double_tab
** File description:
** transform a tab to double tab
*/

#include "my.h"

int line_double(char **str)
{
    int x = 0;
    int y = 0;

    while (str[y] != NULL) {
        if (str[y][x] == '\0')
            y++;
        x++;
    }
    return (y);
}

int line(char *str)
{
    int i = 0;
    int res = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n')
            res++;
        i++;
    }
    return (res);
}

char **alloc_lines(char **dbl_str, char *str)
{
    int i = 0;
    int y = 0;
    int x = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n' && str[i + 1] != '\0') {
            dbl_str[y + 1] = malloc(sizeof(char) * (my_strlen(str) + 1));
            dbl_str[y][x] = '\0';
            y++;
            if (dbl_str[y] == NULL)
                return NULL;
            i++;
            x = 0;
        }
        dbl_str[y][x] = str[i];
        x++;
        i++;
    }
    return (dbl_str);
}

char **tab_to_double(char *str)
{
    int i = 0;
    int y = 0;
    int x = 0;
    char **dbl_str = malloc(sizeof(char*) * (line(str) + 1));

    if (dbl_str == NULL)
        return NULL;
    dbl_str[y] = malloc(sizeof(char) * (my_strlen(str) + 1));
    if (dbl_str[y] == NULL)
        return NULL;
    alloc_lines(dbl_str, str);
    return (dbl_str);
}
