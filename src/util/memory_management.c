/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** memory_management
*/

#include "tetris.h"

void free_tetrimino(tetrimino_t *tetrimino)
{
    free(tetrimino->name);
    for (int i = 0; tetrimino->pattern[i]; i++)
        free(tetrimino->pattern[i]);
    free(tetrimino);
}

void free_all(gamedata_t *data)
{
    free(data->settings->keys);
    free(data->settings);
    ll_free(data->tetriminos, free_tetrimino);
    free(data);
}