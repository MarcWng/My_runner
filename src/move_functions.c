/*
** EPITECH PROJECT, 2019
** move_functions
** File description:
** move_function call
*/

#include "my.h"

void move_character(texture_t *texture, my_timer_t timer,
                    ms_animation_t *mvt)
{
    move_background(texture, mvt);
    move_alien(texture, mvt);
    move_marco_alien_rect(&mvt->marco_rect, *texture, timer, &mvt->alien_rect);
    move_rat(texture, mvt);
    move_rat_rect(&mvt->rat_rect, timer);
    move_hopper(texture, mvt);
    rect(*texture, mvt);
    move_hopper_rect(&mvt->hopper_rect, timer);
}
