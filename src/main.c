/*
** EPITECH PROJECT, 2018
** main
** File description:
** main runner
*/

#include "my.h"

int error(int ac, char **av);

int main(int ac, char **av)
{
    if (error(ac, av) == 1)
        return (84);
    else
        return (0);
}
