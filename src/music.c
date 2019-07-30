/*
** EPITECH PROJECT, 2019
** music.c
** File description:
** gest music
*/

#include "my.h"

void music_gest(sfMusic **music)
{
    *music = sfMusic_createFromFile("Metal_Slug_music.ogg");
    sfMusic_setLoop(*music, sfTrue);
    sfMusic_play(*music);
}
