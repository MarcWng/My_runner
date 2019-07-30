/*
** EPITECH PROJECT, 2019
** hopper_movement.c
** File description:
** hopper animation and move
*/

#include "my.h"

void move_hopper(texture_t *texture, ms_animation_t *hop)
{
    sfVector2f posi;

    hop->move_hopper.x = -20;
    sfSprite_move(texture->hopper_sprite, hop->move_hopper);
    posi = sfSprite_getPosition(texture->hopper_sprite);
    if (posi.x < -400) {
        sfRenderWindow_close(texture->window);
        my_printf("Congratz, you avoided the red hopper !\n");
    }
}

void move_hopper_rect(sfIntRect *hopper_rect, my_timer_t timer)
{
    timer.time_hop = sfClock_getElapsedTime(timer.clock_hop);
    timer.seconds_hop = timer.time_hop.microseconds / 1000000.0;
    if (timer.seconds_hop > 0.045) {
        if (hopper_rect->left != 1530) {
            hopper_rect->left = hopper_rect->left + 153;
            if (hopper_rect->left == 1530)
                hopper_rect->left = 0;
        }
        sfClock_restart(timer.clock_hop);
    }
}
