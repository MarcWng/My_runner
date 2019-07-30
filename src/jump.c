/*
** EPITECH PROJECT, 2019
** jump.c
** File description:
** manage jumps
*/

#include "my.h"

void jump(texture_t *texture, int *moving)
{
    jump_t jump;

    jump.actual_pos = sfSprite_getPosition(texture->marco_sprite);
    jump.speed.x = 0;
    jump.speed.y = -15;
    if (*moving == 1) {
        sfSprite_move(texture->marco_sprite, jump.speed);
        jump.actual_pos = sfSprite_getPosition(texture->marco_sprite);
        if (jump.actual_pos.y < 350)
            *moving = 2;
        return;
    }
    jump.speed.y = 15;
    if (*moving == 2 && jump.actual_pos.y < 650)
        sfSprite_move(texture->marco_sprite, jump.speed);
    if (jump.actual_pos.y == 650)
        *moving = 0;
}
