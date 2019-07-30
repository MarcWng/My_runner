/*
** EPITECH PROJECT, 2019
** sprite.c
** File description:
** sprite management
*/

#include "my.h"

void alien_sprite(texture_t *help, sfIntRect *alien_rect)
{
    sfVector2f pos;

    alien_rect->top = 0;
    alien_rect->left = 0;
    alien_rect->height = 116;
    alien_rect->width = 138;
    pos.x = 1700;
    pos.y = 100;
    help->alien_texture = sfTexture_createFromFile("mini_ufo.png", NULL);
    help->alien_sprite = sfSprite_create();
    sfSprite_setTexture(help->alien_sprite, help->alien_texture, sfTrue);
    sfSprite_setPosition(help->alien_sprite, pos);
}

void marco_sprite(texture_t *help, sfIntRect *marco_rect,
                  sfIntRect *alien_rect)
{
    sfVector2f pos;

    marco_rect->top = 0;
    marco_rect->width = 251;
    marco_rect->height = 307;
    marco_rect->left = 0;
    pos.x = 200;
    pos.y = 650;
    help->marco_texture = sfTexture_createFromFile("Marco_sprite.png", NULL);
    help->marco_sprite = sfSprite_create();
    sfSprite_setTexture(help->marco_sprite, help->marco_texture, sfTrue);
    sfSprite_setPosition(help->marco_sprite, pos);
    alien_sprite(help, alien_rect);
}
