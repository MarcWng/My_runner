/*
** EPITECH PROJECT, 2018
** runner.c
** File description:
** my_runner
*/

#include "my.h"

void event_jump(texture_t *texture)
{
    sfKeyCode key;
    static int moving = 0;

    key = sfKeySpace;
    if (sfKeyboard_isKeyPressed(key) == sfTrue && moving == 0)
        moving = 1;
    if (moving == 1 || moving == 2)
        jump(texture, &moving);
}

void sprite(texture_t *help, ms_animation_t *anim)
{
    sfVideoMode mode = {1835, 1080, 32};
    sfVector2f pos;

    pos.x = 1835;
    pos.y = 0;
    help->window = sfRenderWindow_create(mode, "RUN", sfResize |
                                         sfClose, NULL);
    help->first_texture = sfTexture_createFromFile("Background.png", NULL);
    help->first_back = sfSprite_create();
    help->second_back = sfSprite_create();
    sfSprite_setTexture(help->first_back, help->first_texture, sfTrue);
    sfSprite_setTexture(help->second_back, help->first_texture, sfTrue);
    sfSprite_setPosition(help->first_back, pos);
    pos.x = 0;
    sfSprite_setPosition(help->second_back, pos);
    rat_sprite(help, &anim->rat_rect, &anim->hopper_rect);
    marco_sprite(help, &anim->marco_rect, &anim->alien_rect);
    sfRenderWindow_setFramerateLimit(help->window, 50);
}

void windows_events(ms_animation_t mvt, sfEvent event,
                    int score)
{
    texture_t texture;
    my_timer_t timer;
    sfMusic *music;

    music_gest(&music);
    create_clock(&timer);
    sprite(&texture, &mvt);
    while (sfRenderWindow_isOpen(texture.window)) {
        sfRenderWindow_clear(texture.window, sfBlack);
        while (sfRenderWindow_pollEvent(texture.window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(texture.window);
        }
        event_jump(&texture);
        move_character(&texture, timer, &mvt);
        draw(texture);
        hitbox(texture, &mvt, music);
    }
    destroy(texture, music);
}

int error(int ac, char **av)
{
    if (ac == 1) {
        my_put_error("Missing map\n");
        return 1;
    }
    if (ac == 2 && my_strdif(av[1], "-h") == 0) {
        my_putstr("Type ./my_runner [map] and press space bar to jump !\n");
        return 0;
    }
    if (ac == 2 && my_strdif(av[1], "-h") == 1)
        return (converter(av[1]));
    if (ac > 2) {
        write(2, "Too many arguments !\n", 21);
        return 1;
    }
}
