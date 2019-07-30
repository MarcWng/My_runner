/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** remove warnings
*/

#ifndef MY_H
#define MY_H

#include <unistd.h>
#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>

typedef struct texture {
    sfRenderWindow* window;
    sfTexture* first_texture;
    sfSprite* first_back;
    sfSprite* second_back;
    sfTexture* marco_texture;
    sfSprite* marco_sprite;
    sfTexture* alien_texture;
    sfSprite* alien_sprite;
    sfTexture* rat_texture;
    sfSprite* rat_sprite;
    sfTexture* hopper_texture;
    sfSprite* hopper_sprite;
}texture_t;

typedef struct movement{
    sfIntRect alien_rect;
    sfIntRect marco_rect;
    sfIntRect rat_rect;
    sfIntRect hopper_rect;
    sfVector2f move_back;
    sfVector2f marco_jump;
    sfVector2f move_alien;
    sfVector2f move_rat;
    sfVector2f move_hopper;
}ms_animation_t;

typedef struct clock_var {
    sfClock *clock_al_marco;
    sfTime time_al_marco;
    float seconds_al_marco;
    sfClock *clock_rat;
    sfTime time_rat;
    float seconds_rat;
    sfClock *clock_hop;
    sfTime time_hop;
    float seconds_hop;
}my_timer_t;

typedef struct pos {
    int x;
    int y;
}pos_sprit_t;

typedef struct jump {
    sfVector2f speed;
    sfVector2f initial_pos;
    sfVector2f actual_pos;
}jump_t;

void hitbox(texture_t texture, ms_animation_t *mvt, sfMusic *music);
void move_hopper_rect(sfIntRect *hopper_rect, my_timer_t timer);
void move_hopper(texture_t *texture, ms_animation_t *hop);
void move_character(texture_t *texture, my_timer_t timer,
                    ms_animation_t *mvt);
void move_rat(texture_t *texture, ms_animation_t *rat);
void move_rat_rect(sfIntRect *rat_rect, my_timer_t timer);
void rat_sprite(texture_t *help, sfIntRect *rat_rect,
                sfIntRect *hopper_rect);
void music_gest(sfMusic **music);
void rect(texture_t texture, ms_animation_t *mvt);
void marco_sprite(texture_t *help, sfIntRect *marco_rect,
                  sfIntRect *alien_rect);
void windows_events(ms_animation_t mvt, sfEvent event,
                    int score);
void move_marco_alien_rect(sfIntRect *marco_rect, texture_t texture,
                           my_timer_t timer, sfIntRect *alien_rect);
void move_background(texture_t *texture, ms_animation_t *background);
void rat_action(texture_t *texture, ms_animation_t *rat,
                my_timer_t timer);
int converter(char *str);
void move_alien(texture_t *texture, ms_animation_t *alien);
void create_clock(my_timer_t *timer);
int my_strdif(char *str1, char *str2);
void draw(texture_t help);
void destroy(texture_t help, sfMusic *music);
void close_window(sfRenderWindow *window);
void jump(texture_t *texture, int *moving);
int my_putstr(char const *str);
void my_putchar(char c);
int my_isneg(int nb);
int my_strlen(char const *str);
void my_put_error(char *str);
int my_getnbr(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strcat(char *dest, char const *src);
char *my_strncat( char *dest, char const *str, int nb);
int my_put_nbr(int nb);
int number(char *str);
void my_printf(char *str, ...);

#endif
