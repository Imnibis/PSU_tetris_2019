/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** move
*/

#include "tetris.h"

int check_collision(gamedata_t *data, element_t *tetrimino)
{
    vector2i_t pos = {-1, 0};
    tetrimino_t *t = tetrimino->tetrimino;
    vector2i_t t_pos = v2i(tetrimino->pos.x - 1, tetrimino->pos.y - 1);

    if (pos.x + t_pos.x < -1 || pos.x + t_pos.x + t->size.x >=
        data->settings->map_size.x) return 0;
    while (t->pattern[pos.y] && data->map[pos.y + t_pos.y]) {
        pos.x++;
        if (!t->pattern[pos.y][pos.x] ||
            !data->map[pos.y + t_pos.y][pos.x + t_pos.x]) {
            pos.x = -1;
            pos.y++;
            continue;
        }
        if ((t->pattern[pos.y][pos.x] == '*' ||
            t->pattern[pos.y][pos.x] == '#')
            && data->map[pos.y + t_pos.y][pos.x + t_pos.x] < 9) return 0;
    }
    if (t->pattern[pos.y] && !data->map[pos.y + t_pos.y]) return 0;
    return 1;
}

void move_down(gamedata_t *data)
{
    if (data->current_tetrimino) {
        data->last_move = clock();
        data->current_tetrimino->pos.y++;
        if (!check_collision(data, data->current_tetrimino)) {
            data->current_tetrimino->pos.y--;
            put_in_map(data);
            free(data->current_tetrimino);
            data->current_tetrimino = 0;
        }
    } else generate_tetrimino(data);
}

void move_left(gamedata_t *data)
{
    if (data->current_tetrimino) {
        data->current_tetrimino->pos.x--;
        if (!check_collision(data, data->current_tetrimino))
            data->current_tetrimino->pos.x++;
    }
}

void move_right(gamedata_t *data)
{
    if (data->current_tetrimino) {
        data->current_tetrimino->pos.x++;
        if (!check_collision(data, data->current_tetrimino))
            data->current_tetrimino->pos.x--;
    }
}

void drop(gamedata_t *data)
{
    while (data->current_tetrimino)
        move_down(data);
}