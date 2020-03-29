/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** generate
*/

#include "tetris.h"

tetrimino_t *pick_tetrimino(gamedata_t *data)
{
    tetrimino_t *generated = 0;
    int count = ll_len(data->tetriminos);
    int random = irand(0, count - 1);

    while (!generated || !generated->pattern) {
        generated = ll_get(data->tetriminos, random);
        random = irand(0, count - 1);
    }
    return generated;
}

void generate_tetrimino(gamedata_t *data)
{
    element_t *e = malloc(sizeof(element_t));

    e->tetrimino = pick_tetrimino(data);
    e->pos = v2i(data->settings->map_size.x / 2 + e->tetrimino->size.x / 2 + 1,
        1);
    data->current_tetrimino = data->next_tetrimino;
    data->next_tetrimino = e;
}