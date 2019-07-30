/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** remove warnings
*/

#ifndef MY_H
#define MY_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

void my_put_error(char *str);
void my_printf(char *str, ...);
void my_putchar(char c);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_revstr(char *str);
int my_put_nbr(int nb);
int number(char *str);
int my_putstr(char const *str);
int flag_nbr(int nb, int p);
int space_handle(char *str, int *i, va_list va, int *p);
char flag_string(char *str, int p);
int flag_char(int letter, int p);

#endif
