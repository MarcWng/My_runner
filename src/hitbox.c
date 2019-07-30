/*
** EPITECH PROJECT, 2019
** hitbox.c
** File description:
** hitbox management
*/

#include "my.h"
#include <stdio.h>

void check_height(sfVector2f pos_marco, sfVector2f pos_hopper,
                  sfMusic *music, texture_t texture)
{
    if (pos_hopper.y < pos_marco.y + 307) {
        my_printf("Don't touch the red hopper ! He's freaking dangerous !\n");
        sfRenderWindow_close(texture.window);
    }
}

void hitbox(texture_t texture, ms_animation_t *mvt, sfMusic *music)
{
    sfIntRect marco_bound;
    sfIntRect hopper_bound;
    sfVector2f pos_marco;
    sfVector2f pos_hopper;
    float hopper_right;

    pos_marco = sfSprite_getPosition(texture.marco_sprite);
    pos_hopper = sfSprite_getPosition(texture.hopper_sprite);
    marco_bound = sfSprite_getTextureRect(texture.marco_sprite);
    hopper_bound = sfSprite_getTextureRect(texture.hopper_sprite);
    hopper_right = pos_hopper.x + hopper_bound.width;
    if (hopper_right >= pos_marco.x + marco_bound.width &&
        pos_hopper.x + 50 <= pos_marco.x + marco_bound.width)
        check_height(pos_marco, pos_hopper, music, texture);
    else if (hopper_right >= pos_marco.x + 50 &&
             pos_hopper.x <= pos_marco.x + 50 ||
             hopper_right >= pos_marco.x + (marco_bound.width / 2) &&
             pos_hopper.x + 50 <= pos_marco.x + (marco_bound.width / 2))
        check_height(pos_marco, pos_hopper, music, texture);
}
