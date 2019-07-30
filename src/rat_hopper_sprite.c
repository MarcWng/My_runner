/*
** EPITECH PROJECT, 2018
** rat
** File description:
** rat character
*/

#include "my.h"

void move_rat(texture_t *texture, ms_animation_t *rat)
{
    sfVector2f posi;

    rat->move_rat.x = -1;
    sfSprite_move(texture->rat_sprite, rat->move_rat);
    posi = sfSprite_getPosition(texture->rat_sprite);
    if (posi.x < -400) {
        posi.x = 1835;
        sfSprite_setPosition(texture->rat_sprite, posi);
    }
}

void move_rat_rect(sfIntRect *rat_rect, my_timer_t timer)
{
    timer.time_rat = sfClock_getElapsedTime(timer.clock_rat);
    timer.seconds_rat = timer.time_rat.microseconds / 1000000.0;
    if (timer.seconds_rat > 0.05) {
        if (rat_rect->left != 450) {
            rat_rect->left = rat_rect->left + 75;
            if (rat_rect->left == 450)
                rat_rect->left = 0;
        }
        sfClock_restart(timer.clock_rat);
    }
}

void hopper_sprite(texture_t *help, sfIntRect *hopper_rect)
{
    sfVector2f pos;

    hopper_rect->top = 0;
    hopper_rect->left = 0;
    hopper_rect->height = 81;
    hopper_rect->width = 153;
    pos.x = 1835;
    pos.y = 876;
    help->hopper_texture = sfTexture_createFromFile("hopper.png", NULL);
    help->hopper_sprite = sfSprite_create();
    sfSprite_setTexture(help->hopper_sprite, help->hopper_texture, sfTrue);
    sfSprite_setPosition(help->hopper_sprite, pos);
}

void rat_sprite(texture_t *help, sfIntRect *rat_rect,
                sfIntRect *hopper_rect)
{
    sfVector2f pos;

    rat_rect->top = 0;
    rat_rect->left = 0;
    rat_rect->height = 27;
    rat_rect->width = 75;
    pos.x = 1835;
    pos.y = 850;
    help->rat_texture = sfTexture_createFromFile("Rat.png", NULL);
    help->rat_sprite = sfSprite_create();
    sfSprite_setTexture(help->rat_sprite, help->rat_texture, sfTrue);
    sfSprite_setPosition(help->rat_sprite, pos);
    hopper_sprite(help, hopper_rect);
}
