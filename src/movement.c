/*
** EPITECH PROJECT, 2018
** sprite_character.c
** File description:
** characters sprites
*/

#include "my.h"

void move_marco_alien_rect(sfIntRect *marco_rect, texture_t texture,
                           my_timer_t timer, sfIntRect *alien_rect)
{
    timer.time_al_marco = sfClock_getElapsedTime(timer.clock_al_marco);
    timer.seconds_al_marco = timer.time_al_marco.microseconds / 1000000.0;
    if (timer.seconds_al_marco > 0.08) {
        if (alien_rect->left != 2208) {
            alien_rect->left = alien_rect->left + 138;
            if (alien_rect->left == 2208)
                alien_rect->left = 0;
        }
        if (marco_rect->left != 3012) {
            marco_rect->left = marco_rect->left + 251;
            if (marco_rect->left == 3012)
                marco_rect->left = 0;
        }
        sfClock_restart(timer.clock_al_marco);
    }
}

void move_alien(texture_t *texture, ms_animation_t *alien)
{
    sfVector2f posi;

    alien->move_alien.x = -5;
    alien->move_alien.y = 0;
    sfSprite_move(texture->alien_sprite, alien->move_alien);
    posi = sfSprite_getPosition(texture->alien_sprite);
    if (posi.x < -300) {
        posi.x = 1835;
        sfSprite_setPosition(texture->alien_sprite, posi);
    }
}

void move_background(texture_t *texture, ms_animation_t *background)
{
    sfVector2f posi;

    background->move_back.x = -4;
    sfSprite_move(texture->first_back, background->move_back);
    sfSprite_move(texture->second_back, background->move_back);
    posi = sfSprite_getPosition(texture->second_back);
    if (posi.x < -1835) {
        posi.x = 0;
        sfSprite_setPosition(texture->second_back, posi);
    }
    posi = sfSprite_getPosition(texture->first_back);
    if (posi.x < 0) {
        posi.x = 1835;
        sfSprite_setPosition(texture->first_back, posi);
    }
}
