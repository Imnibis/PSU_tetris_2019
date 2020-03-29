/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetriminos
*/

#include "tetris.h"

void display_tetrimino_line(gamedata_t *data, element_t *e, int i)
{
    for (int j = 0; e->tetrimino->pattern[i][j]; j++) {
        if (e->tetrimino->pattern[i][j] == '*')
            display_color(data->windows->game, '*',
                v2i(e->pos.x + j, e->pos.y + i), e->tetrimino->color);
    }
}

void display_tetrimino(gamedata_t *data, element_t *e)
{
    for (int i = 0; e && e->tetrimino->pattern[i]; i++) {
        display_tetrimino_line(data, e, i);
    }
}