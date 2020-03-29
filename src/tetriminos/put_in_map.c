/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** put_in_map
*/

#include "tetris.h"

void put_in_map(gamedata_t *data)
{
    vector2i_t pos = {-1, 0};
    tetrimino_t *t = data->current_tetrimino->tetrimino;
    vector2i_t t_pos = data->current_tetrimino->pos;

    while (t->pattern[pos.y] && data->map[pos.y + t_pos.y - 1]) {
        pos.x++;
        if (!t->pattern[pos.y][pos.x] ||
            !data->map[pos.y + t_pos.y - 1][pos.x + t_pos.x - 1]) {
            pos.x = 0;
            pos.y++;
            continue;
        }
        if (t->pattern[pos.y][pos.x] == '*')
            data->map[pos.y + t_pos.y - 1][pos.x + t_pos.x - 1] = t->color + 1;
    }
}