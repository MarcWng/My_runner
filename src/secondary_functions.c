/*
** EPITECH PROJECT, 2018
** secondary_functions
** File description:
** reduce the lengh of some of the runner functions
*/

#include "my.h"

void rect(texture_t texture, ms_animation_t *mvt)
{
    sfSprite_setTextureRect(texture.marco_sprite, mvt->marco_rect);
    sfSprite_setTextureRect(texture.alien_sprite, mvt->alien_rect);
    sfSprite_setTextureRect(texture.rat_sprite, mvt->rat_rect);
    sfSprite_setTextureRect(texture.hopper_sprite, mvt->hopper_rect);
}

void draw(texture_t help)
{
    sfRenderWindow_drawSprite(help.window, help.first_back, NULL);
    sfRenderWindow_drawSprite(help.window, help.second_back, NULL);
    sfRenderWindow_drawSprite(help.window, help.alien_sprite, NULL);
    sfRenderWindow_drawSprite(help.window, help.rat_sprite, NULL);
    sfRenderWindow_drawSprite(help.window, help.marco_sprite, NULL);
    sfRenderWindow_drawSprite(help.window, help.hopper_sprite, NULL);
    sfRenderWindow_display(help.window);
}

void destroy(texture_t help, sfMusic *music)
{
    sfTexture_destroy(help.first_texture);
    sfTexture_destroy(help.alien_texture);
    sfTexture_destroy(help.marco_texture);
    sfTexture_destroy(help.rat_texture);
    sfTexture_destroy(help.hopper_texture);
    sfMusic_destroy(music);
    sfRenderWindow_destroy(help.window);
}

void create_clock(my_timer_t *timer)
{
    timer->clock_al_marco = sfClock_create();
    timer->clock_rat = sfClock_create();
    timer->clock_hop = sfClock_create();
}
