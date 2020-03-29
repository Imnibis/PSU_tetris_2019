/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** move
*/

#include "tetris.h"

int check_collision(gamedata_t *data)
{
    vector2i_t pos = {-1, 0};
    tetrimino_t *t = data->current_tetrimino->tetrimino;
    vector2i_t t_pos = data->current_tetrimino->pos;

    while (t->pattern[pos.y] && data->map[pos.y + t_pos.y]) {
        pos.x++;
        if (!t->pattern[pos.y][pos.x] ||
            !data->map[pos.y + t_pos.y][pos.x + t_pos.x - 1]) {
            pos.x = 0;
            pos.y++;
            continue;
        }
        if (t->pattern[pos.y][pos.x] == '*' &&
            data->map[pos.y + t_pos.y][pos.x + t_pos.x - 2] < 9)
            return 0;
    }
    if (t->pattern[pos.y] && !data->map[pos.y + t_pos.y])
        return 0;
    return 1;
}

void move_down(gamedata_t *data)
{
    if (data->current_tetrimino) {
        data->last_move = clock();
        if (check_collision(data))
            data->current_tetrimino->pos.y++;
        else {
            put_in_map(data);
            free(data->current_tetrimino);
            data->current_tetrimino = 0;
        }
    } else generate_tetrimino(data);
}

void move_left(gamedata_t *data)
{
    if (data->current_tetrimino)
        data->current_tetrimino->pos.x--;
}

void move_right(gamedata_t *data)
{
    if (data->current_tetrimino)
        data->current_tetrimino->pos.x++;
}